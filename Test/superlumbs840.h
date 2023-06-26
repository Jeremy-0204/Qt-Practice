#pragma once

#include <MGenSweepLaser.h>
#include <serialport.h>
#include <QDebug>
MGEN_NAMESPACE_START


class SuperlumBS840 : public MGenSweepLaser
{
    Q_OBJECT
public:
    explicit SuperlumBS840(QObject *parent = nullptr);
    virtual ~SuperlumBS840();

    Q_INVOKABLE virtual bool connectPort(const QString &portName, int baudRate, const QString &flowControl, const QString &parity, const QString &dataBits, const QString &stopBits);
    Q_INVOKABLE bool close();
    Q_INVOKABLE bool sendPacket(const QString &Packet);

    Q_INVOKABLE bool setSingleToneWaveLength(const QString waveLength);
    Q_INVOKABLE bool setStartWaveLength(const QString WaveLength);
    Q_INVOKABLE bool setStopWaveLength(const QString WaveLength);
    Q_INVOKABLE bool setSweptSpeed(const QString sweptSpeed);
    Q_INVOKABLE bool setPauseTime(const QString Pause);
    Q_INVOKABLE bool setSweptMode(const int SweptMode);
    Q_INVOKABLE bool setControlMode(const int ControlMode);

    Q_INVOKABLE virtual bool powerOn();
    Q_INVOKABLE virtual bool powerOff();

    Q_INVOKABLE virtual bool laserOn();
    Q_INVOKABLE virtual bool laserOff();


public slots:
    void handleReadyRead();

private:
    bool RequestDeviceName();
    bool RequestDeviceStatus();
    bool RequestDeviceParam();

    void ParseDataI(const char* Data, const int Size);
    void ParseDataM(const char* Data, const int Size);
    void ParseDataP(const char* Data, const int Size);

    QObject* mSingleton;


private:
    SerialPort mSerialPort;
    SuperlumLaserParam mSuperlumParam;
    QByteArray mDataRead;
};

MGEN_NAMESPACE_END
