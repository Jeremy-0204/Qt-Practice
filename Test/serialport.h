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
    Q_PROPERTY(QStringList availablePorts READ availablePorts NOTIFY availablePortsChanged)
    Q_PROPERTY(QStringList baudRates READ baudRates CONSTANT)
    Q_PROPERTY(QStringList flowControls READ flowControls CONSTANT)
    Q_PROPERTY(QStringList parityOptions READ parityOptions CONSTANT)
    Q_PROPERTY(QStringList dataBits READ dataBits CONSTANT)
    Q_PROPERTY(QStringList stopBits READ stopBits CONSTANT)

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
    bool connectToPort(const QString &portName, int baudRate, string flowControl, string parity, string dataBits, string stopBits);
    bool closePort();
    bool writePacket(const QString &Packet);

signals:
    void availablePortsChanged();

private:
    QStringList m_availablePorts;
};

#endif // SERIALPORT_H
