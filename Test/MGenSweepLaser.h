#include <MGenDeviceDef.h>
#include <QObject>

MGEN_NAMESPACE_START

class MGenSweepLaser : public QObject
{
    Q_OBJECT
    Q_PROPERTY(ESuperlumLaserSweepMode SweepMode READ SweepMode WRITE setMSweepMode(ESuperlumLaserSweepMode SweepMode) NOTIFY mSweepModeChanged)
    Q_PROPERTY(float SingleToneWaveLength READ SingleToneWaveLength WRITE setMSingleToneWaveLength(float SingleToneWaveLength) NOTIFY mSingleToneWaveLengthChanged)
    Q_PROPERTY(float StartWaveLength READ StartWaveLength WRITE setMStartWaveLength(float StartWaveLength) NOTIFY mStartWaveLengthChanged)
    Q_PROPERTY(float StopWaveLength READ StopWaveLength WRITE setMStopWaveLength(float StopToneWaveLength) NOTIFY mStopWaveLengthChanged)
    Q_PROPERTY(float SweepSpeed READ SweepSpeed WRITE setMSweepSpeed(float SweepSpeed) NOTIFY mSweepSpeedChanged)
    Q_PROPERTY(int PauseTime READ PauseTime WRITE setMPauseTime(float PauseTime) NOTIFY mPauseTimeChanged)

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
    ESuperlumLaserSweepMode SweepMode() const;
    float SingleToneWaveLength() const;
    float StartWaveLength() const;
    float StopWaveLength() const;
    float SweepSpeed() const;
    int PauseTime() const;

    // 그 외 필요한 함수
    bool isConnected() const;
    bool isLaserOn() const;
    ESuperlumLaserControlMode GetControlMode() const;

protected:
    bool mbConnected = false;
    ELaserStatusMode mPowerMode = ELaserStatusMode :: PowerOff;
    ESuperlumLaserSweepMode mSweepMode = ESuperlumLaserSweepMode :: ContinuousSweep;
    float mSingleToneWaveLength = 0.0f;
    float mStartWaveLength = 0.0f;
    float mStopWaveLength = 0.0f;
    float mSweepSpeed = 0.0f;
    int mPauseTime = 0;




};





MGEN_NAMESPACE_END
