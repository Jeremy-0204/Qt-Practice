#include "superlumbs840vm.h"
MGEN_NAMESPACE_START

SuperlumBS840VM :: SuperlumBS840VM(QObject *parent) : mSuperlumBS840()
{}

SuperlumBS840VM :: ~SuperlumBS840VM()
{}

bool SuperlumBS840VM :: onClickedConnect(const QString &portName, int baudRate, const QString &flowControl, const QString &parity, const QString &dataBits, const QString &stopBits)
{
    return mSuperlumBS840.connectPort(portName, baudRate, flowControl, parity, dataBits, stopBits);
}

bool SuperlumBS840VM :: onClickedClose()
{
    return mSuperlumBS840.close();
}

//bool SuperlumBS840VM :: onClickedRefresh()
//{}

bool SuperlumBS840VM :: onClickedPowerOn()
{
    return mSuperlumBS840.powerOn();
}

bool SuperlumBS840VM :: onClickedPowerOff()
{
    return mSuperlumBS840.powerOff();
}

bool SuperlumBS840VM :: onClickedLaserOn()
{
    return mSuperlumBS840.laserOn();
}

bool SuperlumBS840VM :: onClickedLaserOff()
{
    return mSuperlumBS840.laserOff();
}

MGEN_NAMESPACE_END
