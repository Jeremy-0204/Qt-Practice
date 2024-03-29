#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <string>

using namespace std;

class SerialPort : public QObject
{
    Q_OBJECT

public:
    explicit SerialPort(QObject *parent = nullptr);
    QStringList availablePorts() const;
    QStringList baudRates() const;
    QStringList flowControls() const;
    QStringList parityOptions() const;
    QStringList dataBits() const;
    QStringList stopBits() const;

    QSerialPort *mSerial = nullptr;

public slots:
    void refreshAvailablePorts();
    bool connectToPort(const QString &portName, int baudRate, const QString &flowControl, const QString &parity, const QString &dataBits, const QString &stopBits);
    bool closePort();
    bool writePacket(const QString &Packet);

signals:
    void availablePortsChanged();

private:
    QStringList m_availablePorts;
};

#endif // SERIALPORT_H
