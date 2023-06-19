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


    Q_INVOKABLE virtual bool connectPort(const QString &portName, int baudRate, int flowControl, int parity, int dataBits, int stopBits);
    Q_INVOKABLE bool close();
    Q_INVOKABLE bool sendPacket(const QString &Packet);

    //virtual bool Connect() override;
    //virtual bool Disconnect() override;

//    Q_INVOKABLE virtual bool powerOn();
//    Q_INVOKABLE virtual bool powerOff();

    bool RequestDeviceName();

    bool RequestDeviceStatus();

    bool RequestDeviceParam();

//    virtual bool LaserOn() override;
//    virtual bool LaserOff() override;

//    // Q_PROPERTY 변수들에 대한 Setter 함수
//    virtual bool setMSweepMode(ESuperlumLaserSweepMode SweepMode) override;
//    virtual bool setMSingleToneWaveLength(float SingleToneWaveLength) override;
//    virtual bool setMStartWaveLength(float StartWaveLength) override;
//    virtual bool setMStopWaveLength(float StopToneWaveLength) override;
//    virtual bool setMSweepSpeed(float SweepSpeed) override;
//    virtual bool setMPauseTime(float PauseTime) override;

//public slots:
//    bool connectToPort(const QString &portName, int baudRate, int flowControl, int parity, int dataBits, int stopBits);

//private:
//    bool SendPacket(const char* Packet);

//    bool RequestDeviceName();
//    bool RequestDeviceStatus();
//    bool RequestDeviceParam();

private:
    SerialPort mSerialPort;
    SuperlumLaserParam mSuperlumParam;
};

MGEN_NAMESPACE_END
