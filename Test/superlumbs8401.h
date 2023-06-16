#ifndef SUPERLUMBS8401_H
#define SUPERLUMBS8401_H

#include <QObject>
#include <QSerialPort>

class SuperlumBS8401 : public QObject
{
    Q_OBJECT
    Q_ENUMS(ELasorStatus)
    Q_ENUMS(ELasorSweepMode)

public:
    explicit SuperlumBS8401(QObject *parent = nullptr);

    enum ELaserStatus
    {
        PowerOFF,
        PowerON,
        ReadyToFire,
        Fire,
        Error
    };

    enum ELaserSweepMode
    {
        SingleTone,
        SingleSweep,
        ContinuousSweep
    };

    bool PowerOn();
    bool PowerOff();
    bool LaserOn();
    bool LaserOff();

    bool SetSweepMode(ELaserSweepMode SweepMode);
    bool SetSingleWaveLength(const float WaveLength);
    bool SetStartWaveLength(const float WaveLength);
    bool SetStopWaveLength(const float WaveLength);
    bool SetSweepSpeed(const float WaveLength);
    bool SetPauseTime(const float WaveLength);

public slots:
    bool connectToPort(const QString &portName, int baudRate, int flowControl, int parity, int dataBits, int stopBits);

private:
    bool SendPacket(const char* Packet);
    QSerialPort *serial;
    ELaserStatus mStatus;
    ELaserSweepMode mSweepMode;
};

#endif // SUPERLUMBS840_H
