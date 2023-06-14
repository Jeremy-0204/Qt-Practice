#ifndef SUPERLUMBS840_H
#define SUPERLUMBS840_H

#include <QObject>
#include <QSerialPort>

class SuperlumBS840 : public QObject
{
    Q_OBJECT
    Q_ENUMS(LasorStatus)

public:
    explicit SuperlumBS840(QObject *parent = nullptr);

    enum LasorStatus
    {
        PowerOFF,
        PowerON,
        ReadyToFire,
        Fire,
        Error
    };

    bool PowerOn();
    bool PowerOff();
    bool LaserOn();
    bool LaserOff();

public slots:
    bool connectToPort(const QString &portName, int baudRate, int flowControl, int parity, int dataBits, int stopBits);

private:
    bool SendPacket(const char* Packet);
    QSerialPort *serial;



    /* powerOn / powerOff
     * LaserOn / LaserOff
     * ==========================
     *
     * SWEEP CONTROL
     * SINGLE TONE / SINGLE SWEEP / CONTINOUS SWEEP
     *
     * ==========================
     *
     * COMMON
     *
     * Full Tuning Range:   805nm ~ 880nm
     *
     * AOTP TEC
     * Laser TEC
     * Sweep
     *
     * Output
     *
     * ==========================
     *
     * SINGLE TONE
     * Light wavelength
     *
     * ==========================
     *
     * SINGLE SWEEP
     * Start Wavelength, Stop Wavelength
     * Sweep Speed
     * Sweep Time
     *
     * ==========================
     *
     * CONTINUOUS SWEEP
     * Wavelength 1, Wavelength 2
     * Sweep Speed
     * Pause
     * Sweep Time
     *
     * =========================
     */


};

#endif // SUPERLUMBS840_H
