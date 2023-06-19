#include "superlumbs840.h"
MGEN_NAMESPACE_START

SuperlumBS840 :: SuperlumBS840(QObject *parent) : MGenSweepLaser(parent)
{}


SuperlumBS840 :: ~SuperlumBS840()
{}

bool SuperlumBS840 :: connectPort(const QString &portName, int baudRate, int flowControl, int parity, int dataBits, int stopBits)
{
    mbConnected = mSerialPort.connectToPort(portName, baudRate, flowControl, parity, dataBits, stopBits);
    return mbConnected;
}

bool SuperlumBS840 :: close()
{
    mbConnected = mSerialPort.closePort();
    return mbConnected;
}

bool SuperlumBS840 :: write()
{
    mbWritten = mSerialPort.writePacket();
    return mbWritten;
}


MGEN_NAMESPACE_END
