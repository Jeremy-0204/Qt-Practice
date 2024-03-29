#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    qmlRegisterType<QSerialPort>("SerialPort", 1, 0, "QSerialPort");
    qmlRegisterType<QSerialPortInfo>("SerialPortInfo", 1, 0, "QSerialPortInfo");

    const QUrl url(QStringLiteral("qrc:/Qt_SerialCommunicarion/Main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
