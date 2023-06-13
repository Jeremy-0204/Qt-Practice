#include "SerialPortWrapper.h"

SerialPortWrapper::SerialPortWrapper(QObject *parent) : QObject(parent)
{
    connect(&m_serialPort, &QSerialPort::readyRead, this, &SerialPortWrapper::handleReadyRead);
}

bool SerialPortWrapper::open(const QString &portName, qint32 baudRate)
{
    m_serialPort.setPortName(portName);
    m_serialPort.setBaudRate(baudRate);

    if (!m_serialPort.open(QIODevice::ReadWrite))
        return false;

    return true;
}

void SerialPortWrapper::close()
{
    m_serialPort.close();
}

void SerialPortWrapper::write(const QString &data)
{
    m_serialPort.write(data.toUtf8());
}

void SerialPortWrapper::handleReadyRead()
{
    QByteArray data = m_serialPort.readAll();
    emit dataReceived(QString::fromUtf8(data));
}

QStringList SerialPortWrapper::availablePorts()
{
    QStringList portNames;
    QList<QSerialPortInfo> portInfoList = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo& portInfo : portInfoList) {
        portNames.append(portInfo.portName());
    }
    return portNames;
}

