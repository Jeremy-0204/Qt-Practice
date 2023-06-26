#include <superlumbs840.h>
#include <QObject>

MGEN_NAMESPACE_START

class SuperlumBS840VM
{
    Q_OBJECT

public:
    explicit SuperlumBS840VM(QObject *parent = nullptr);
    virtual ~SuperlumBS840VM();

// * 필요한 함수 모음
    Q_INVOKABLE bool onClickedConnect(const QString &portName, int baudRate, const QString &flowControl, const QString &parity, const QString &dataBits, const QString &stopBits);
    Q_INVOKABLE bool onClickedClose();
    //Q_INVOKABLE bool onClickedRefresh();
    Q_INVOKABLE bool onClickedPowerOn();
    Q_INVOKABLE bool onClickedPowerOff();
    Q_INVOKABLE bool onClickedLaserOn();
    Q_INVOKABLE bool onClickedLaserOff();

    Q_INVOKABLE bool onClickedSetSingleTone(const int SweptMode, const QString WaveLength);
    Q_INVOKABLE bool onClickedSetSingleSwept(const int SweptMode, const QString StartWaveLength, const QString StopWaveLength, const QString SweptSpeed);
    Q_INVOKABLE bool onClickedSetContinuousSwept(const int SweptMode, const QString StartWaveLength, const QString StopWaveLength, const QString SweptSpeed, const QString Pause);

//    Q_INVOKABLE bool onClickedSetSingleToneWaveLength(const QString WaveLength);
//    Q_INVOKABLE bool onClickedSetStartWaveLength(const QString WaveLength);
//    Q_INVOKABLE bool onClickedSetStopWaveLength(const QString WaveLength);
//    Q_INVOKABLE bool onClickedSetSweptSpeed(const QString sweptSpeed);
//    Q_INVOKABLE bool onClickedSetPauseTime(const QString Pause);
//    Q_INVOKABLE bool onClickedSetSweptMode(const int SweptMode);
//    Q_INVOKABLE bool onClickedSetControlMode(const int ControlMode);

private:
    SuperlumBS840 mSuperlumBS840;
};

MGEN_NAMESPACE_END
