#include <MGenDeviceDef.h>
#include <QObject>

MGEN_NAMESPACE_START

class MGenSweepLaser : public QObject
{
    Q_OBJECT
    Q_PROPERTY(ELaserSweepMode mSweepMode READ mSweepMode WRITE setMSweepMode NOTIFY mSweepModeChanged)
    Q_PROPERTY(float mSingleToneWaveLength READ mSingleToneWaveLength WRITE setMSingleToneWaveLength NOTIFY mSingleToneWaveLengthChanged)
    Q_PROPERTY(float mStartWaveLength READ mStartWaveLength WRITE setMStartWaveLength NOTIFY mStartWaveLengthChanged)
    Q_PROPERTY(float mStopWaveLength READ mStopWaveLength WRITE setMStopWaveLength NOTIFY mStopWaveLengthChanged)
    Q_PROPERTY(float mSweepSpeed READ mSweepSpeed WRITE setMSweepSpeed NOTIFY mSweepSpeedChanged)
    Q_PROPERTY(int mPauseTime READ mPauseTime WRITE setMPauseTime NOTIFY mPauseTimeChanged)

public:
    explicit MGenSweepLaser(QObject *parent = nullptr);
    virtual ~MGenSweepLaser();

    virtual bool Connect() = 0;
    virtual bool Disconnect() = 0;

    virtual bool PowerOn() = 0;
    virtual bool PowerOff() = 0;

    virtual bool LaserOn() = 0;
    virtual bool LaserOff() = 0;


};





MGEN_NAMESPACE_END
