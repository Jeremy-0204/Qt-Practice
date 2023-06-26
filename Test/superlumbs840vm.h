#include <superlumbs840.h>
#include <QObject>

MGEN_NAMESPACE_START

class SuperlumBS840VM : public QObject
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

    Q_INVOKABLE QStringList onClickedRefresh();
    Q_INVOKABLE QStringList onBaudRates();
    Q_INVOKABLE QStringList onFlowControls();
    Q_INVOKABLE QStringList onParityOptions();
    Q_INVOKABLE QStringList onDataBits();
    Q_INVOKABLE QStringList onStopBits();

private:
    SuperlumBS840 mSuperlumBS840;
};

MGEN_NAMESPACE_END
