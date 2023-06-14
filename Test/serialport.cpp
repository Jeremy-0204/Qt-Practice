#include "serialport.h"
#include "QDebug"

SerialPort::SerialPort(QObject *parent)
    : QObject(parent)
{
    refreshAvailablePorts();
}

QStringList SerialPort::availablePorts() const
{
    return m_availablePorts;
}

QStringList SerialPort::baudRates() const
{
    QStringList baudRateOptions;

    const QList<int> baudRates = QSerialPortInfo::standardBaudRates();
    for (int baudRate : baudRates) {
        baudRateOptions.append(QString::number(baudRate));
    }

    return baudRateOptions;
}

QStringList SerialPort::flowControls() const
{
    QStringList flowControlOptions;
    flowControlOptions.append("NoFlowControl");
    flowControlOptions.append("HardwareControl");
    flowControlOptions.append("SoftwareControl");
    return flowControlOptions;
}

QStringList SerialPort::parityOptions() const
{
    QStringList parityOptions;
    parityOptions.append("NoParity");
    parityOptions.append("EvenParity");
    parityOptions.append("OddParity");
    parityOptions.append("SpaceParity");
    parityOptions.append("MarkParity");
    return parityOptions;
}

QStringList SerialPort::dataBits() const
{
    QStringList dataBitsOptions;
    dataBitsOptions.append("Data5");
    dataBitsOptions.append("Data6");
    dataBitsOptions.append("Data7");
    dataBitsOptions.append("Data8");
    return dataBitsOptions;
}

QStringList SerialPort::stopBits() const
{
    QStringList stopBitsOptions;
    stopBitsOptions.append("OneStop");
    stopBitsOptions.append("OneAndHalfStop");
    stopBitsOptions.append("TwoStop");
    return stopBitsOptions;
}

void SerialPort::refreshAvailablePorts()
{
    m_availablePorts.clear();

    const QList<QSerialPortInfo> ports = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &port : ports) {
        m_availablePorts.append(port.portName());
    }

    emit availablePortsChanged();
}
