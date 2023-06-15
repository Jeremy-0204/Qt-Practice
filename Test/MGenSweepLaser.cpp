#include <MGenSweepLaser.h>
MGEN_NAMESPACE_START

MGenSweepLaser :: MGenSweepLaser(QObject *parent)
    : QObject(parent)
{}

ESuperlumLaserSweepMode MGenSweepLaser :: SweepMode() const
{
    return mSweepMode;
}

float MGenSweepLaser :: SingleToneWaveLength() const
{
    return mSingleToneWaveLength;
}

float MGenSweepLaser :: StartWaveLength() const
{
    return mStartWaveLength;
}

float MGenSweepLaser :: StopWaveLength() const
{
    return mStopWaveLength;
}

float MGenSweepLaser :: SweepSpeed() const
{
    return mSweepSpeed;
}

int MGenSweepLaser :: PauseTime() const
{
    return mPauseTime;
}

bool MGenSweepLaser :: isConnected() const
{
    return mbConnected;
}

ELaserStatusMode MGenSweepLaser :: isLaserOn() const
{
    return mStatusMode;
}

MGEN_NAMESPACE_END
