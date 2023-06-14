#include "serialport.h"

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

//QStringList SerialPort::dataBits() const
//{
//    QStringList dataBitsOptions;
//    dataBitsOptions.append(QString::number(QSerialPort::Data5));
//    dataBitsOptions.append(QString::number(QSerialPort::Data6));
//    dataBitsOptions.append(QString::number(QSerialPort::Data7));
//    dataBitsOptions.append(QString::number(QSerialPort::Data8));
//    return dataBitsOptions;
//}

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

void SerialPort::connectToPort(const QString &portName, int baudRate, int flowControl, int parity, int dataBits, int stopBits)
{
    QSerialPort *serial = new QSerialPort(portName);

    // Baud rate 설정
    serial->setBaudRate(static_cast<QSerialPort::BaudRate>(baudRate));

    // Flow control 설정
    serial->setFlowControl(static_cast<QSerialPort::FlowControl>(flowControl));

    // Parity 설정
    serial->setParity(static_cast<QSerialPort::Parity>(parity));

    // Data bits 설정
    serial->setDataBits(static_cast<QSerialPort::DataBits>(dataBits));

    // Stop bits 설정
    serial->setStopBits(static_cast<QSerialPort::StopBits>(stopBits));

    if (serial->open(QIODevice::ReadWrite)) {
        // 시리얼 포트가 성공적으로 열렸을 때의 로직
        // 연결된 시리얼 포트 사용 가능
    } else {
        // 시리얼 포트 열기 실패한 경우의 로직
        // 연결에 실패했음을 사용자에게 알릴 수 있습니다.
    }
}
