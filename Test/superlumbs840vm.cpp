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

bool SuperlumBS840VM :: onClickedSetSingleTone(const int SweptMode, const QString WaveLength)
{
    if(mSuperlumBS840.setSweptMode(SweptMode) && mSuperlumBS840.setSingleToneWaveLength(WaveLength))
    {
        return true;
    }
    return false;
}


bool SuperlumBS840VM :: onClickedSetSingleSwept(const int SweptMode, const QString StartWaveLength, const QString StopWaveLength, const QString SweptSpeed)
{
    mSuperlumBS840.setSweptMode(SweptMode);
    mSuperlumBS840.setStartWaveLength(StartWaveLength);
    mSuperlumBS840.setStopWaveLength(StopWaveLength);
    mSuperlumBS840.setSweptSpeed(SweptSpeed);
}

bool SuperlumBS840VM :: onClickedSetContinuousSwept(const int SweptMode, const QString StartWaveLength, const QString StopWaveLength, const QString SweptSpeed, const QString Pause)
{
    mSuperlumBS840.setSweptMode(SweptMode);
    mSuperlumBS840.setStartWaveLength(StartWaveLength);
    mSuperlumBS840.setStopWaveLength(StopWaveLength);
    mSuperlumBS840.setSweptSpeed(SweptSpeed);
    mSuperlumBS840.setPauseTime(Pause);
}

//bool SuperlumBS840VM :: onClickedSetSingleToneWaveLength(const QString WaveLength)
//{
//    return mSuperlumBS840.setSingleToneWaveLength(WaveLength);
//}

//bool SuperlumBS840VM :: onClickedSetStartWaveLength(const QString WaveLength)
//{
//    return mSuperlumBS840.setStartWaveLength(WaveLength);
//}

//bool SuperlumBS840VM :: onClickedSetStopWaveLength(const QString WaveLength)
//{
//    return mSuperlumBS840.setStopWaveLength(WaveLength);
//}

//bool SuperlumBS840VM :: onClickedSetSweptSpeed(const QString sweptSpeed)
//{
//    return mSuperlumBS840.setSweptSpeed(sweptSpeed);
//}

//bool SuperlumBS840VM :: onClickedSetPauseTime(const QString Pause)
//{
//    return mSuperlumBS840.setPauseTime(Pause);
//}

//bool SuperlumBS840VM :: onClickedSetSweptMode(const int SweptMode)
//{
//    return mSuperlumBS840.setSweptMode(SweptMode);
//}

//bool SuperlumBS840VM :: onClickedSetControlMode(const int ControlMode)
//{
//    return mSuperlumBS840.setControlMode(ControlMode);
//}


MGEN_NAMESPACE_END
