#include <QObject>
#include <QSerialPortInfo>

class SerialPortInfoWrapper : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList availablePorts READ availablePorts NOTIFY availablePortsChanged)

public:
    explicit SerialPortInfoWrapper(QObject *parent = nullptr) : QObject(parent) {}

    QStringList availablePorts()
    {
        QStringList portNames;
        QList<QSerialPortInfo> portInfos = QSerialPortInfo::availablePorts();
        for (const QSerialPortInfo &portInfo : portInfos) {
            portNames.append(portInfo.portName());
        }
        return portNames;
    }

signals:
    void availablePortsChanged();
};
