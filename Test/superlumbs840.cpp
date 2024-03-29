#include "superlumbs840.h"
#include <QQmlEngine>
#include <QQmlApplicationEngine>
#include <iostream>
#include <iomanip>


MGEN_NAMESPACE_START

SuperlumBS840 :: SuperlumBS840(QObject *parent) : MGenSweepLaser(parent), mSerialPort()
{
    connect(mSerialPort.mSerial, &QSerialPort::readyRead, this, &SuperlumBS840::handleReadyRead);
    initialize();
}

SuperlumBS840 :: ~SuperlumBS840()
{}

QStringList SuperlumBS840 :: mBaudRates;
QStringList SuperlumBS840 :: mFlowControls;
QStringList SuperlumBS840 :: mParityOptions;
QStringList SuperlumBS840 :: mDataBits;
QStringList SuperlumBS840 :: mStopBits;

void SuperlumBS840 :: initialize()
{
    mBaudRates = mSerialPort.baudRates();
    mFlowControls = mSerialPort.flowControls();
    mParityOptions = mSerialPort.parityOptions();
    mDataBits = mSerialPort.dataBits();
    mStopBits = mSerialPort.stopBits();
}

bool SuperlumBS840 :: connectPort(const QString &portName, int baudRate, const QString &flowControl, const QString &parity, const QString &dataBits, const QString &stopBits)
{
    mbConnected = mSerialPort.connectToPort(portName, baudRate, flowControl, parity, dataBits, stopBits);

    RequestDeviceName();
    RequestDeviceStatus();
    RequestDeviceParam();

    return mbConnected;
}

bool SuperlumBS840 :: close()
{
    mbConnected = mSerialPort.closePort();
    return mbConnected;
}

bool SuperlumBS840::powerOn()
{
    if (sendPacket("MW\r\n"))
    {
        mLaserStatusMode = ELaserStatusMode::PowerOn;
    }
    return false;
}

bool SuperlumBS840::powerOff()
{
    if (sendPacket("MO\r\n"))
    {
        mLaserStatusMode = ELaserStatusMode::PowerOff;
    }
    return false;
}

bool SuperlumBS840::laserOn()
{
    if (sendPacket("X\r\n"))
    {
        mLaserStatusMode = ELaserStatusMode::Fire;
        return true;
    }
    return false;
}

bool SuperlumBS840::laserOff()
{
    if (sendPacket("X\r\n"))
    {
        mLaserStatusMode = ELaserStatusMode::ReadyToFire;
        return true;
    }
    return false;
}


bool SuperlumBS840::setSingleToneWaveLength(const QString waveLength)
{
    float WaveLength = waveLength.toFloat();
    const float MinWaveLength = 100.0f * (WaveLength - mSuperlumParam.BaseWaveLength);
    const int SingleToneWaveLength = static_cast<int>(MinWaveLength);
    std::stringstream Stream;
    Stream << "P21" << std::hex << std::setw(4) << std::setfill('0') << SingleToneWaveLength << "\r\n";
    qDebug() << Stream.str().c_str();

    return sendPacket(Stream.str().c_str());
}

bool SuperlumBS840::setStartWaveLength(const QString waveLength)
{
    float WaveLength = waveLength.toFloat();
    const float MinWaveLength = 100.0f * (WaveLength - mSuperlumParam.BaseWaveLength);
    const int StartWaveLength =  static_cast<int>(MinWaveLength);
    std::stringstream Stream;
    Stream << "P22" << std::hex << std::setw(4) << std::setfill('0') << StartWaveLength << "\r\n";

    return sendPacket(Stream.str().c_str());
}

bool SuperlumBS840::setStopWaveLength(const QString waveLength)
{
    float WaveLength = waveLength.toFloat();
    const float MaxWaveLength = 100.0f * (WaveLength - mSuperlumParam.BaseWaveLength);
    const int StopWaveLength = static_cast<int>(MaxWaveLength);
    std::stringstream Stream;
    Stream << "P23" << std::hex << std::setw(4) << std::setfill('0') << StopWaveLength << "\r\n";

    return sendPacket(Stream.str().c_str());
}

bool SuperlumBS840::setSweptSpeed(const QString sweptSpeed)
{
    int SweptSpeed = sweptSpeed.toInt();
    const int Speed = static_cast<int>(SweptSpeed);
    std::stringstream Stream;
    Stream << "P24" << std::hex << std::setw(6) << std::setfill('0') << Speed << "\r\n";

    return sendPacket(Stream.str().c_str());
}

bool SuperlumBS840::setPauseTime(const QString pause)
{
    int Pause = pause.toInt();
    const int Time = static_cast<int>(Pause / 10);
    std::stringstream Stream;
    Stream << "P25" << std::hex << std::setw(6) << std::setfill('0') << Time << "\r\n";

    return sendPacket(Stream.str().c_str());
}

bool SuperlumBS840::setSweptMode(const int SweptMode)
{
    if (SweptMode == mSweepMode)
    {
        return true;
    }

    std::string Packet = "";
    switch (SweptMode)
    {
    case ESuperlumLaserSweepMode::SingleTone:		Packet = "MT\r\n";	break;
    case ESuperlumLaserSweepMode::SingleSweep:		Packet = "MY\r\n";	break;
    case ESuperlumLaserSweepMode::ContinuousSweep:	Packet = "MZ\r\n";	break;
    default: assert(false);					return false;		break;
    }

    if (sendPacket(Packet.c_str()))
    {
        mSweepMode = static_cast<ESuperlumLaserSweepMode>(SweptMode);
        return true;
    }

    return false;
}

bool SuperlumBS840::setControlMode(const int ControlMode)
{
    if (ControlMode == mSuperlumParam.ControlMode)
    {
        return true;
    }

    std::string Packet = "";
    switch (ControlMode)
    {
    case ESuperlumLaserControlMode::Local:	Packet = "MB\r\n";	break;
    case ESuperlumLaserControlMode::Remote:	Packet = "ME\r\n";	break;
    case ESuperlumLaserControlMode::USB:		Packet = "MC\r\n";	break;
    default: assert(false);				return false;		break;
    }

    if (sendPacket(Packet.c_str()))
    {
        mSuperlumParam.ControlMode = static_cast<ESuperlumLaserControlMode>(ControlMode);
        return true;
    }

    return false;
}

bool SuperlumBS840 :: sendPacket(const QString &Packet)
{
    mbWritten = mSerialPort.writePacket(Packet);
    mSerialPort.mSerial->waitForReadyRead(50);
    return mbWritten;
}

bool SuperlumBS840::RequestDeviceName()
{
    return sendPacket("I\r\n");
}

bool SuperlumBS840::RequestDeviceStatus()
{
    return sendPacket("M\r\n");
}

bool SuperlumBS840::RequestDeviceParam()
{
    sendPacket("P01\r\n");
    sendPacket("P02\r\n");
    sendPacket("P03\r\n");
    sendPacket("P04\r\n");
    sendPacket("P07\r\n");

    sendPacket("P10\r\n");
    sendPacket("P11\r\n");
    sendPacket("P12\r\n");

    sendPacket("P20\r\n");
    sendPacket("P21\r\n");
    sendPacket("P22\r\n");
    sendPacket("P23\r\n");
    sendPacket("P24\r\n");
    sendPacket("P25\r\n");
    sendPacket("P26\r\n");
}

QStringList SuperlumBS840 :: AvailablePorts()
{
    return mSerialPort.availablePorts();
}

QStringList SuperlumBS840 :: GetBaudRates()
{
    return mBaudRates;
}

QStringList SuperlumBS840 :: GetFlowControls()
{
    return mFlowControls;
}

QStringList SuperlumBS840 :: GetParityOptions()
{
    return mParityOptions;
}

QStringList SuperlumBS840 :: GetDataBits()
{
    return mDataBits;
}

QStringList SuperlumBS840 :: GetStopBits()
{
    return mStopBits;
}

void SuperlumBS840 :: handleReadyRead()
{
    qDebug() << "\nHANDLE READY READ CALLED";

    static QByteArray receivedData;  // 수신한 데이터를 누적할 변수

    while (mSerialPort.mSerial->bytesAvailable() > 0) {
        QByteArray newData = mSerialPort.mSerial->readAll();  // 새로 도착한 데이터를 읽음
        receivedData += newData;  // 데이터를 누적

        // 특정 패턴 또는 문자열을 확인하여 패킷의 끝을 확인
        if (receivedData.endsWith("\n")) {
            // 패킷이 완전히 도착한 경우 처리 로직 수행
            mDataRead = receivedData;

            // 누적한 데이터 초기화
            receivedData.clear();
        }
    }

    qDebug() << "WE RECEIVED: " << mDataRead;

    bool bCR = true;
    bool bLF = true;
    bool bDiscrim = false;
    bool bSave = false;

    char cDiscrim = 0;

    int nCR = 0;
    int nLF = 0;
    int nDiscrim = 0;
    int nCount = 0;


    for (size_t n = 0; n < strlen(mDataRead); n++)
    {
        if (mDataRead[n] == '\r')
        {
            bCR = true;
            bDiscrim = false;
            nCR = nCount;
            nCount++;
        }
        else if (mDataRead[n] == '\n' && bCR)
        {
            if (nCR == nCount - 1)
            {
                bLF = bSave = true;
                nLF = nCount;
            }
            else
            {
                bCR = nLF = false;
                nCount = 0;
            }
        }
        else if (bCR && bLF && !bDiscrim)
        {
            // Time to get discriminator
            cDiscrim = mDataRead[n];
            bDiscrim = true;
            bCR = bLF = false;
            nCount = 0;
        }
        else
        {
            nCount++;
        }

        if (bSave)
        {
            bSave = false;
            // time to data
            switch (cDiscrim)
            {
            case 'I':	ParseDataI((const char*)mDataRead, nCount);	break;
            case 'M':	ParseDataM((const char*)mDataRead, nCount);	break;
            case 'X':	ParseDataM((const char*)mDataRead, nCount);	break;
            case 'P':	ParseDataP((const char*)mDataRead, nCount);	break;
            case '!':       // error
                assert(false);
                //ParseDataError((const char*)Buffer, nCount);
                break;
            }
            nCount = 0;
        }
    }

    qDebug() << "Testing BaseWaveLength : " << mSuperlumParam.BaseWaveLength <<"\n";
}

void SuperlumBS840::ParseDataI(const char* Data, const int Size)
{
    strncpy_s(mSuperlumParam.DeviceType, sizeof(mSuperlumParam.DeviceType), (const char*)Data, Size);
}

void SuperlumBS840::ParseDataM(const char* Data, const int Size)
{
    // M7C01B : not firing, M7C4DB : firing
    // ex) "[M][DSB][SS][MSB][CR][LF]
    auto _FuncConvertBit = [](bool bit[], const long Number) {
        bit[0] = 0x01 & Number;
        bit[1] = 0x02 & Number;
        bit[2] = 0x04 & Number;
        bit[3] = 0x08 & Number;
        bit[4] = 0x10 & Number;
        bit[5] = 0x20 & Number;
        bit[6] = 0x40 & Number;
        bit[7] = 0x80 & Number;
    };

    bool bitDSB[8];
    char strDSB[3] = { Data[1], Data[2], 0 };
    const long DSBNumber = strtol(strDSB, NULL, 16);
    _FuncConvertBit(bitDSB, DSBNumber);

    bool bitSS[8];
    char strSS = Data[3];
    const long SSNumber = strtol(&strSS, NULL, 16);
    _FuncConvertBit(bitSS, SSNumber);

    bool bitMSB[8];
    char strMSB[2] = { Data[4], Data[5] };
    const long MSBNumber = strtol(strMSB, NULL, 16);
    _FuncConvertBit(bitMSB, MSBNumber);


    // [DSB] device mode 3bits
    mSuperlumParam.StatusMode = ELaserStatusMode::PowerOff;
    if ((!bitDSB[2] && !bitDSB[1] & !bitDSB[0]) || (!bitDSB[2] && !bitDSB[1] && bitDSB[0]))
    {
        mSuperlumParam.PowerMode = ESuperlumLaserPowerMode::Shutdown;
        mSuperlumParam.StatusMode = ELaserStatusMode::PowerOff;
    }
    else if (!bitDSB[2] && bitDSB[1] && !bitDSB[0])
    {
        mSuperlumParam.PowerMode = ESuperlumLaserPowerMode::WarmUp;
        mSuperlumParam.StatusMode = ELaserStatusMode::PowerOn;
    }
    else if ((bitDSB[2] && !bitDSB[1] && !bitDSB[0]) || (bitDSB[2] && !bitDSB[1] && bitDSB[0]))
    {
        mSuperlumParam.PowerMode = ESuperlumLaserPowerMode::Function;
        mSuperlumParam.StatusMode = ELaserStatusMode::ReadyToFire;
    }
    else if ((bitDSB[2] && bitDSB[1] && !bitDSB[0])	|| (bitDSB[2] && bitDSB[1] && bitDSB[0]))
    {
        mSuperlumParam.PowerMode = ESuperlumLaserPowerMode::PowerError;
        mSuperlumParam.StatusMode = ELaserStatusMode::LasorError;
    }

    // [DSB] device control 2bits
    if (!bitDSB[4] && !bitDSB[3])
    {
        mSuperlumParam.ControlMode = ESuperlumLaserControlMode::Local;
    }
    else if (!bitDSB[4] && bitDSB[3])
    {
        mSuperlumParam.ControlMode = ESuperlumLaserControlMode::Remote;
    }
    else if ((bitDSB[4] && !bitDSB[3]) || (bitDSB[4] && bitDSB[3]))
    {
        mSuperlumParam.ControlMode = ESuperlumLaserControlMode::USB;
    }

    // [DSB] device functions 2bits
    if (!bitDSB[6] && !bitDSB[5])
    {
        mSuperlumParam.SweepMode = ESuperlumLaserSweepMode::SingleTone;
    }
    else if (bitDSB[6] && !bitDSB[5])
    {
        mSuperlumParam.SweepMode = ESuperlumLaserSweepMode::SingleSweep;
    }
    else if (bitDSB[6] && bitDSB[5])
    {
        mSuperlumParam.SweepMode = ESuperlumLaserSweepMode::ContinuousSweep;
    }

    // [SS]
    if (mSuperlumParam.SweepMode == ESuperlumLaserSweepMode::ContinuousSweep)
    {
        mSuperlumParam.StatusMode = (SSNumber == 0) ? ELaserStatusMode::ReadyToFire : ELaserStatusMode::Fire;
    }

    // [MSB]
    mSuperlumParam.bAotfTecPower = bitMSB[0];
    mSuperlumParam.bAotfTecStable = bitMSB[1];
    mSuperlumParam.bAotfTecStatus = bitMSB[2];

    mSuperlumParam.bSldTecPower = bitMSB[3];
    mSuperlumParam.bSldTecStable = bitMSB[4];
    mSuperlumParam.bSldTecStatus = bitMSB[5];

    mSuperlumParam.bSldPower = bitMSB[6];
    mSuperlumParam.bSldCurrentLimit = bitMSB[7];

    if (mSuperlumParam.SweepMode == ESuperlumLaserSweepMode::SingleTone)
    {
        mSuperlumParam.StatusMode = (mSuperlumParam.bSldPower) ? ELaserStatusMode::ReadyToFire : ELaserStatusMode::Fire;
    }
}

void SuperlumBS840::ParseDataP(const char* Data, const int Size)
{
    int HexNumber = strtoul(Data + 3, NULL, 16);
    if ('0' == Data[1])
    {
        switch (Data[2])
        {
        case '1':	strncpy_s(mSuperlumParam.Firmware, sizeof(mSuperlumParam.Firmware), (const char*)Data, Size);	break;
        case '2':	mSuperlumParam.BaseFrequency = HexNumber;	break;
        case '3':	mSuperlumParam.MeanWaveLength = HexNumber;	break;
        case '4':	mSuperlumParam.BaseWaveLength = HexNumber;	break;
        case '7':	mSuperlumParam.MinimumSweepRange = HexNumber;	break;
        }
    }
    else if ('1' == Data[1])
    {
        switch (Data[2])
        {
        case '0':	strncpy_s(mSuperlumParam.SerialNumber, sizeof(mSuperlumParam.SerialNumber), (const char*)Data, Size);	break;
        case '1':	mSuperlumParam.MinWaveLength = mSuperlumParam.BaseWaveLength + HexNumber * 0.01f;	break;
        case '2':	mSuperlumParam.MaxWaveLength = mSuperlumParam.BaseWaveLength + HexNumber * 0.01f;	break;
        }
    }
    else if ('2' == Data[1])
    {
        switch (Data[2])
        {
        case '0':	mSuperlumParam.OffModeData = HexNumber;	break;
        case '1':	mSingleToneWaveLength = mSuperlumParam.BaseWaveLength + HexNumber * 0.01f;	break;
        case '2':	mStartWaveLength = mSuperlumParam.BaseWaveLength + HexNumber * 0.01f;		break;
        case '3':	mStopWaveLength = mSuperlumParam.BaseWaveLength + HexNumber * 0.01f;		break;
        case '4':	mSweepSpeed = HexNumber * 0.1f;												break;
        case '5':	mPauseTime = HexNumber * 10;												break;
        case '6':	mSuperlumParam.SweepTime = HexNumber * 10;									break;
        case 'D':
        {
            char Start[4], Stop[4];
            for (int i = 0; i < 4; i++)
            {
                Start[i] = Data[3 + i];
                Stop[i] = Data[7 + i];
            }
            HexNumber = strtoul(Start, NULL, 16);
            mStartWaveLength = mSuperlumParam.BaseWaveLength + HexNumber * 0.01f;

            HexNumber = strtoul(Stop, NULL, 16);
            mStopWaveLength = mSuperlumParam.BaseWaveLength + HexNumber * 0.01f;
        }	break;
        }
    }
}

MGEN_NAMESPACE_END
