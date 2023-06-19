#include "superlumbs840.h"
MGEN_NAMESPACE_START

SuperlumBS840 :: SuperlumBS840(QObject *parent) : MGenSweepLaser(parent)
{}


SuperlumBS840 :: ~SuperlumBS840()
{}

bool SuperlumBS840 :: connectPort(const QString &portName, int baudRate, int flowControl, int parity, int dataBits, int stopBits)
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

bool SuperlumBS840 :: sendPacket(const QString &Packet)
{
    mbWritten = mSerialPort.writePacket(Packet);
    qDebug() << mbWritten;
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
    return (
        sendPacket("P01\r\n") &&
        sendPacket("P02\r\n") &&
        sendPacket("P03\r\n") &&
        sendPacket("P04\r\n") &&
        sendPacket("P07\r\n") &&

        sendPacket("P10\r\n") &&
        sendPacket("P11\r\n") &&
        sendPacket("P12\r\n") &&

        sendPacket("P20\r\n") &&
        sendPacket("P21\r\n") &&
        sendPacket("P22\r\n") &&
        sendPacket("P23\r\n") &&
        sendPacket("P24\r\n") &&
        sendPacket("P25\r\n") &&
        sendPacket("P26\r\n"));
}

MGEN_NAMESPACE_END
