#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlEngine>
#include "superlumbs840VM.h"

MGEN_NAMESPACE_USE;

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    qmlRegisterType<SuperlumBS840VM>("SuperlumBS840VM", 1, 0, "SuperlumBS840VM");

    const QUrl url(QStringLiteral("qrc:/Test/Main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    engine.load(url);

    return app.exec();
}
