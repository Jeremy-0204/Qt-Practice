#ifndef SERIALPORTWRAPPER_H
#define SERIALPORTWRAPPER_H

#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>


class SerialPortWrapper : public QObject
{
    Q_OBJECT
public:
    explicit SerialPortWrapper(QObject *parent = nullptr);

    Q_INVOKABLE bool open(const QString &portName, qint32 baudRate);
    Q_INVOKABLE void close();
    Q_INVOKABLE void write(const QString &data);
    Q_INVOKABLE QStringList availablePorts();

signals:
    void dataReceived(const QString &data);

private slots:
    void handleReadyRead();

private:
    QSerialPort m_serialPort;
};

#endif // SERIALPORTWRAPPER_H
