#include "superlumbs840.h"

SuperlumBS840::SuperlumBS840(QObject *parent)
    : QObject(parent)
{}

bool SuperlumBS840::PowerOn()
{

}

bool SuperlumBS840::SendPacket(const char* Packet, QSerialPort &Serial)
{
    // -1 if failed, else returns number of bytes sent
    qint64 bytesWritten = Serial.write(Packet);

    if (bytesWritten != sizeof(Packet) || bytesWritten == -1)
    {
        return false;
    }

    return true;

}
