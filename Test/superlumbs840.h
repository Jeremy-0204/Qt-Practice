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

    virtual bool connectPort(const QString &portName, int baudRate, const QString &flowControl, const QString &parity, const QString &dataBits, const QString &stopBits);
    virtual bool close();
    virtual bool sendPacket(const QString &Packet);

    virtual bool powerOn();
    virtual bool powerOff();

    virtual bool laserOn();
    virtual bool laserOff();

    bool setSingleToneWaveLength(const QString waveLength);
    bool setStartWaveLength(const QString WaveLength);
    bool setStopWaveLength(const QString WaveLength);
    bool setSweptSpeed(const QString sweptSpeed);
    bool setPauseTime(const QString Pause);
    bool setSweptMode(const int SweptMode);
    bool setControlMode(const int ControlMode);

public slots:
    void handleReadyRead();

private:
    bool RequestDeviceName();
    bool RequestDeviceStatus();
    bool RequestDeviceParam();

    void ParseDataI(const char* Data, const int Size);
    void ParseDataM(const char* Data, const int Size);
    void ParseDataP(const char* Data, const int Size);

private:
    SerialPort mSerialPort;
    SuperlumLaserParam mSuperlumParam;
    QByteArray mDataRead;
};

MGEN_NAMESPACE_END
