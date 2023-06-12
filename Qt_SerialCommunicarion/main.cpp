#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    // C++에서 사용할 객체 생성
    QSerialPort serialPort;
    QList<QSerialPortInfo> SerialPortInfo = QSerialPortInfo::availablePorts();

    // QVariantList에 포트 이름 저장
    QVariantList serialPortList;
    foreach (const QSerialPortInfo &SerialPortInfo, SerialPortInfo) {
        serialPortList.append(SerialPortInfo.portName());
    }

    // 시리얼 포트 객체와 포트 목록을 QML 컨텍스트에 등록
    engine.rootContext()->setContextProperty("serialPort", &serialPort);
    engine.rootContext()->setContextProperty("SerialPortInfo", QVariant::fromValue(serialPortList));


    const QUrl url(u"qrc:/Qt_SerialCommunicarion/Main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
