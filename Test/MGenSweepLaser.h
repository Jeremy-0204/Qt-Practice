#include <MGenDeviceDef.h>
#include <QObject>

MGEN_NAMESPACE_START

class MGenSweepLaser : public QObject
{
    Q_OBJECT
    Q_PROPERTY(ESuperlumLaserSweepMode mSweepMode READ mSweepMode WRITE setMSweepMode(ESuperlumLaserSweepMode SweepMode) NOTIFY mSweepModeChanged)
    Q_PROPERTY(float mSingleToneWaveLength READ mSingleToneWaveLength WRITE setMSingleToneWaveLength(float SingleToneWaveLength) NOTIFY mSingleToneWaveLengthChanged)
    Q_PROPERTY(float mStartWaveLength READ mStartWaveLength WRITE setMStartWaveLength(float StartWaveLength) NOTIFY mStartWaveLengthChanged)
    Q_PROPERTY(float mStopWaveLength READ mStopWaveLength WRITE setMStopWaveLength(float StopToneWaveLength) NOTIFY mStopWaveLengthChanged)
    Q_PROPERTY(float mSweepSpeed READ mSweepSpeed WRITE setMSweepSpeed(float SweepSpeed) NOTIFY mSweepSpeedChanged)
    Q_PROPERTY(int mPauseTime READ mPauseTime WRITE setMPauseTime(float PauseTime) NOTIFY mPauseTimeChanged)

public:
    explicit MGenSweepLaser(QObject *parent = nullptr);
    virtual ~MGenSweepLaser();

    virtual bool Connect() = 0;
    virtual bool Disconnect() = 0;

    virtual bool PowerOn() = 0;
    virtual bool PowerOff() = 0;

    virtual bool LaserOn() = 0;
    virtual bool LaserOff() = 0;

    // Q_PROPERTY 변수들에 대한 Setter 함수
    virtual bool setMSweepMode(ESuperlumLaserSweepMode SweepMode) = 0;
    virtual bool setMSingleToneWaveLength(float SingleToneWaveLength) = 0;
    virtual bool setMStartWaveLength(float StartWaveLength) = 0;
    virtual bool setMStopWaveLength(float StopToneWaveLength) = 0;
    virtual bool setMSweepSpeed(float SweepSpeed) = 0;
    virtual bool setMPauseTime(float PauseTime) = 0;

    // Q_PROPERTY 변수들에 대한 Getter 함수
    ESuperlumLaserSweepMode mSweepMode();
    float mSingleToneWaveLength();
    float mStartWaveLength();
    float mStopWaveLength();
    float mSweepSpeed();
    int mPauseTime();



};





MGEN_NAMESPACE_END
