#pragma once

#include <MGenDeviceDef.h>
#include <QObject>
#include <string>

MGEN_NAMESPACE_START
using namespace std;

class MGenSweepLaser : public QObject
{
    Q_OBJECT

public:
    explicit MGenSweepLaser(QObject *parent = nullptr);
    virtual ~MGenSweepLaser();

    //virtual bool connect() = 0;
    virtual bool connectPort(const QString &portName, int baudRate, const QString &flowControl, const QString &parity, const QString &dataBits, const QString &stopBits) = 0;
    virtual bool close() = 0;
    virtual bool sendPacket(const QString &Packet) = 0;
    virtual bool powerOn() = 0;
    virtual bool powerOff() = 0;

    virtual bool laserOn() = 0;
    virtual bool laserOff() = 0;

    // 그 외 필요한 함수
    bool isConnected() const;
    ELaserStatusMode isLaserOn() const;

protected:
    bool mbConnected = false;
    bool mbWritten = false;
    bool mbPowerOn = false;

    float mSingleToneWaveLength = 0.0f;
    float mStartWaveLength = 0.0f;
    float mStopWaveLength = 0.0f;
    float mSweepSpeed = 0.0f;
    int mPauseTime = 0;

    ESuperlumLaserSweepMode mSweepMode = ESuperlumLaserSweepMode :: ContinuousSweep;
    ELaserStatusMode mLaserStatusMode = ELaserStatusMode :: PowerOff;

};

MGEN_NAMESPACE_END
