#include "superlumbs840.h"
#include "QDebug"
#include <string>

SuperlumBS840::SuperlumBS840(QObject *parent)
    : QObject(parent)
{
    serial = new QSerialPort();
    mStatus = ELaserStatus::PowerOFF;
    mSweepMode = ELaserSweepMode::SingleTone;
}

bool SuperlumBS840::PowerOn()
{
    if (SendPacket("MW\r\n"))
    {
        mStatus = ELaserStatus::PowerON;
    }
    return false;
}

bool SuperlumBS840::PowerOff()
{
    if (SendPacket("MO\r\n"))
    {
        mStatus = ELaserStatus::PowerOFF;
    }
    return false;
}

bool SuperlumBS840::SetSweepMode(ELaserSweepMode SweepMode)
{
    if (SweepMode == mSweepMode)
    {
        return true;
    }

    QString Packet = "";

    switch(SweepMode)
    {
    case(ELaserSweepMode::SingleTone): Packet ="MT\r\n";
    case(ELaserSweepMode::SingleSweep): Packet ="MY\r\n";
    case(ELaserSweepMode::ContinuousSweep): Packet ="MZ\r\n";
    }

    if (SendPacket(Packet.toStdString().c_str()))
    {
        mSweepMode = SweepMode;
        return true;
    }
    return false;
}

bool SuperlumBS840::SetSingleWaveLength(const float WaveLength)
{

}
/*
 *
 *
 *
 */







bool SuperlumBS840::SendPacket(const char* Packet)
{
    // -1 if failed, else returns number of bytes sent
    qint64 bytesWritten = serial->write(Packet);

    if (bytesWritten != sizeof(Packet) || bytesWritten == -1)
    {
        return false;
    }

    return true;

}

bool SuperlumBS840::connectToPort(const QString &portName, int baudRate, int flowControl, int parity, int dataBits, int stopBits)
{
//    QSerialPort *serial = new QSerialPort(portName);

    // Baud rate 설정
    serial->setBaudRate(static_cast<QSerialPort::BaudRate>(baudRate));

    // Flow control 설정
    serial->setFlowControl(static_cast<QSerialPort::FlowControl>(flowControl));

    // Parity 설정
    serial->setParity(static_cast<QSerialPort::Parity>(parity));

    // Data bits 설정
    serial->setDataBits(static_cast<QSerialPort::DataBits>(dataBits));

    // Stop bits 설정
    serial->setStopBits(static_cast<QSerialPort::StopBits>(stopBits));
    qDebug() << "CONNECTED CALLED";

    if (!serial->open(QIODevice::ReadWrite)) {
        qDebug() << "FAILED";
        // 시리얼 포트 열기 실패한 경우의 로직
        // 연결에 실패했음을 사용자에게 알릴 수 있습니다.
        return false;
    } else {
        // 시리얼 포트가 성공적으로 열렸을 때의 로직
        // 연결된 시리얼 포트 사용 가능
        qDebug() << "CONNECTED";
        return true;
    }
}
