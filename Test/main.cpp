#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "SerialPort.h"
#include "superlumbs840.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    qmlRegisterType<SerialPort>("SerialPort", 1, 0, "SerialPort");
    qmlRegisterType<SuperlumBS840>("SuperlumBS840", 1, 0, "SuperlumBS840");

    const QUrl url(QStringLiteral("qrc:/Test/Main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    engine.load(url);

    return app.exec();
}
