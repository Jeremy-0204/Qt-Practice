#include "serialport.h"
#include "QDebug"

SerialPort::SerialPort(QObject *parent)
    : QObject(parent), mSerial(new QSerialPort(this))
{
    // QSerialPort 객체 초기화
    refreshAvailablePorts();
    //connect(mSerial, &QSerialPort::readyRead, this, &SerialPort::handleReadyRead);

}

QStringList SerialPort::availablePorts() const
{
    return m_availablePorts;
}

QStringList SerialPort::baudRates() const
{
    QStringList baudRateOptions;

    const QList<int> baudRates = QSerialPortInfo::standardBaudRates();
    for (int baudRate : baudRates) {
        baudRateOptions.append(QString::number(baudRate));
    }

    return baudRateOptions;
}

QStringList SerialPort::flowControls() const
{
    QStringList flowControlOptions;
    flowControlOptions.append("NoFlowControl");
    flowControlOptions.append("HardwareControl");
    flowControlOptions.append("SoftwareControl");
    return flowControlOptions;
}

QStringList SerialPort::parityOptions() const
{
    QStringList parityOptions;
    parityOptions.append("NoParity");
    parityOptions.append("EvenParity");
    parityOptions.append("OddParity");
    parityOptions.append("SpaceParity");
    parityOptions.append("MarkParity");
    return parityOptions;
}

QStringList SerialPort::dataBits() const
{
    QStringList dataBitsOptions;
    dataBitsOptions.append("Data5");
    dataBitsOptions.append("Data6");
    dataBitsOptions.append("Data7");
    dataBitsOptions.append("Data8");
    return dataBitsOptions;
}

QStringList SerialPort::stopBits() const
{
    QStringList stopBitsOptions;
    stopBitsOptions.append("OneStop");
    stopBitsOptions.append("OneAndHalfStop");
    stopBitsOptions.append("TwoStop");
    return stopBitsOptions;
}

void SerialPort::refreshAvailablePorts()
{
    m_availablePorts.clear();

    const QList<QSerialPortInfo> ports = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &port : ports) {
        m_availablePorts.append(port.portName());
    }

    emit availablePortsChanged();
}

bool SerialPort::connectToPort(const QString &portName, int baudRate, int flowControl, int parity, int dataBits, int stopBits)
{
    // Baud rate 설정
    mSerial->setPortName(portName);
    qDebug() << mSerial->portName();

    // Baud rate 설정
    if(mSerial->setBaudRate(static_cast<QSerialPort::BaudRate>(baudRate)))
    {
        qDebug() << "SET GOOD" << baudRate;
    }
    else{
        qDebug() << "SET FAILED";
    }

    // Flow control 설정

    if(mSerial->setFlowControl(static_cast<QSerialPort::FlowControl>(flowControl)))
    {
        qDebug() << "SET GOOD" << flowControl;
    }
    else{
        qDebug() << "SET FAILED";
    }

    // Parity 설정
    mSerial->setParity(static_cast<QSerialPort::Parity>(parity));

    // Data bits 설정
    mSerial->setDataBits(static_cast<QSerialPort::DataBits>(dataBits));

    // Stop bits 설정
    mSerial->setStopBits(static_cast<QSerialPort::StopBits>(stopBits));
    qDebug() << "CONNECTED CALLED";

    if (mSerial->open(QIODevice::ReadWrite)) {
        qDebug() << "CONNECTED";

        // 시리얼 포트 열기 실패한 경우의 로직
        // 연결에 실패했음을 사용자에게 알릴 수 있습니다.
        return true;
    } else {
        // 시리얼 포트가 성공적으로 열렸을 때의 로직
        // 연결된 시리얼 포트 사용 가능
        qDebug() << "FAILED: " << mSerial->error() << mSerial->errorString();
        return false;
    }
}

bool SerialPort :: closePort()
{
    if (mSerial->isOpen()){
        qDebug() << "PORT IS CURRENTLY OPENED";
        mSerial->close();
        qDebug() << "PORT CLOSED";
    }
    else{
        qDebug() << "PORT IS NOT OPENED";
    }

}

bool SerialPort :: writePacket(const QString &Packet)
{
    //const char* Packet = "THIS MESSAGE IS FROM PORT ";
    // -1 if failed, else returns number of bytes sent
    qint64 bytesWritten;

    const char * cstr = Packet.toUtf8().constData();

    if (mSerial->isOpen()){
        bytesWritten = mSerial->write(cstr);
        qDebug() << "PORT IS CURRENTLY OPENED";
        qDebug() << bytesWritten << " " << sizeof(cstr);
    }

    else
    {
        qDebug() << "PORT IS NOT OPENED";
    }

    if (/*bytesWritten != sizeof(cstr) || */ bytesWritten == -1)
    {
        return false;
    }

    return true;

}
