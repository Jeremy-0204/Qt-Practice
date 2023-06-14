#ifndef SUPERLUMBS840_H
#define SUPERLUMBS840_H

#include <QObject>

class SuperlumBS840 : public QObject
{
    Q_OBJECT


public:
    explicit SuperlumBS840(QObject *parent = nullptr);

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
