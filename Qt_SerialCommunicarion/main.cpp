#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "SerialPortWrapper.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    qmlRegisterType<SerialPortWrapper>("SerialPort", 1, 0, "SerialPortWrapper");

    const QUrl url(u"qrc:/Qt_SerialCommunicarion/Main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
