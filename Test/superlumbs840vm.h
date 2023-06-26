#include <MGenDeviceDef.h>
#include <QObject>

MGEN_NAMESPACE_START

class SuperlumBS840VM
{
    Q_OBJECT

public:
    explicit SuperlumBS840VM(QObject *parent = nullptr);
    virtual ~SuperlumBS840VM();

/*
 * 필요한 함수 모음
 * Q_INVOKABLE bool onClickedConnect(const QString &portName, int baudRate, const QString &flowControl, const QString &parity, const QString &dataBits, const QString &stopBits);
 * Q_INVOKABLE bool onClickedClose();
 * Q_INVOKABLE bool onClickedRefresh();
 * Q_INVOKABLE bool onClickedPowerOn();
 * Q_INVOKABLE bool onClickedPowerOff();
 * Q_INVOKABLE bool onClickedLaserOn();
 * Q_INVOKABLE bool onClickedLaserOff();
 *
 * Q_INVOKABLE bool OnClickedSetSingleToneWaveLength(const QString waveLength);
 * Q_INVOKABLE bool OnClickedSetStartWaveLength(const QString WaveLength);
 * Q_INVOKABLE bool OnClickedSetStopWaveLength(const QString WaveLength);
 * Q_INVOKABLE bool OnClickedSetSweptSpeed(const QString sweptSpeed);
 * Q_INVOKABLE bool OnClickedSetPauseTime(const QString Pause);
 * Q_INVOKABLE bool OnClickedSetSweptMode(const int SweptMode);
 * Q_INVOKABLE bool OnClickedSetControlMode(const int ControlMode);
 *
*/


};

MGEN_NAMESPACE_END
