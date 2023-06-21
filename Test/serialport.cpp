#include "serialport.h"
#include "QDebug"
#include "qmetaobject.h"

SerialPort::SerialPort(QObject *parent)
    : QObject(parent), mSerial(new QSerialPort(this))
{
    // QSerialPort 객체 초기화
    refreshAvailablePorts();
    //connect(mSerial, &QSerialPort::readyRead, this, &SerialPort::handleReadyRead);

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
    QMetaEnum metaEnum = QMetaEnum::fromType<QSerialPort::FlowControl>();
    QStringList flowControlOptions;

    for (int i = 0; i < metaEnum.keyCount(); ++i) {
        const char* key = metaEnum.key(i);
        flowControlOptions.append(QString::fromUtf8(key));
    }

    return flowControlOptions;
}

QStringList SerialPort::parityOptions() const
{

    QMetaEnum metaEnum = QMetaEnum::fromType<QSerialPort::Parity>();
    QStringList parityOptions;

    for (int i = 0; i < metaEnum.keyCount(); ++i) {
        const char* key = metaEnum.key(i);
        parityOptions.append(QString::fromUtf8(key));
    }

    return parityOptions;
}

QStringList SerialPort::dataBits() const
{
    QMetaEnum metaEnum = QMetaEnum::fromType<QSerialPort::DataBits>();
    QStringList dataBitsOptions;

    for (int i = 0; i < metaEnum.keyCount(); ++i) {
        const char* key = metaEnum.key(i);
        dataBitsOptions.append(QString::fromUtf8(key));
    }

    return dataBitsOptions;
}

QStringList SerialPort::stopBits() const
{
    QMetaEnum metaEnum = QMetaEnum::fromType<QSerialPort::StopBits>();
    QStringList stopBitsOptions;

    for (int i = 0; i < metaEnum.keyCount(); ++i) {
        const char* key = metaEnum.key(i);
        stopBitsOptions.append(QString::fromUtf8(key));
    }
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

bool SerialPort::connectToPort(const QString &portName, int baudRate, string flowControl, string parity, string dataBits, string stopBits)
{
    qDebug() << baudRate << flowControl << parity;

    mSerial->setPortName(portName);
    qDebug() << mSerial->portName();


    // Baud rate 설정
    if(mSerial->setBaudRate(static_cast<QSerialPort::BaudRate>(baudRate)))
    {
        qDebug() << "SET baudRate" << baudRate;
    }
    else{
        qDebug() << "SET baudRate FAILED";
    }

    // Flow control 설정
    QMetaEnum flowControlEnum = QMetaEnum::fromType<QSerialPort::DataBits>();
    int flowControlValueIndex = flowControlEnum.keyToValue(flowControl.c_str());
    if (flowControlValueIndex != -1) {
        QSerialPort::FlowControl flowControlValue = static_cast<QSerialPort::FlowControl>(flowControlEnum.value(flowControlValueIndex));
        mSerial->setFlowControl(flowControlValue);
    }
    else {
        qDebug() << "Invalid dataBits value: " << QString::fromStdString(dataBits);
    }

    // Parity 설정
    mSerial->setParity(static_cast<QSerialPort::Parity>(parity));
    qDebug() << "SET parity" << parity;

    // Data bits 설정
    QMetaEnum dataBitsEnum = QMetaEnum::fromType<QSerialPort::DataBits>();
    int dataBitsValueIndex = dataBitsEnum.keyToValue(dataBits.c_str());
    if (dataBitsValueIndex != -1) {
        QSerialPort::DataBits dataBitsValue = static_cast<QSerialPort::DataBits>(dataBitsEnum.value(dataBitsValueIndex));
        mSerial->setDataBits(dataBitsValue);
    }
    else {
        qDebug() << "Invalid dataBits value: " << QString::fromStdString(dataBits);
    }
    //mSerial->setDataBits(static_cast<QSerialPort::DataBits>(dataBits));

    // Stop bits 설정
    mSerial->setStopBits(static_cast<QSerialPort::StopBits>(stopBits));
    qDebug() << "CONNECTED CALLED";

    if (mSerial->open(QIODevice::ReadWrite)) {
        qDebug() << "CONNECTED";

        // 시리얼 포트 열기 실패한 경우의 로직
        // 연결에 실패했음을 사용자에게 알릴 수 있습니다.
        return true;
    } else {
        // 시리얼 포트가 성공적으로 열렸을 때의 로직
        // 연결된 시리얼 포트 사용 가능
        qDebug() << "FAILED: " << mSerial->error() << mSerial->errorString();
        return false;
    }
}

bool SerialPort :: closePort()
{
    if (mSerial->isOpen()){
        qDebug() << "PORT IS CURRENTLY OPENED";
        mSerial->close();
        qDebug() << "PORT CLOSED";
    }
    else{
        qDebug() << "PORT IS NOT OPENED";
    }

}

bool SerialPort :: writePacket(const QString &Packet)
{
    //const char* Packet = "THIS MESSAGE IS FROM PORT ";
    // -1 if failed, else returns number of bytes sent
    qint64 bytesWritten;

    const char * cstr = Packet.toUtf8().constData();

    if (mSerial->isOpen()){
        bytesWritten = mSerial->write(cstr);
        qDebug() << "PORT IS CURRENTLY OPENED";
        qDebug() << bytesWritten << " " << sizeof(cstr);
    }

    else
    {
        qDebug() << "PORT IS NOT OPENED";
    }

    if (/*bytesWritten != sizeof(cstr) || */ bytesWritten == -1)
    {
        return false;
    }

    return true;

}
