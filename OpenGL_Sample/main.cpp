#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "squircle.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/OpenGL_Sample/Main.qml"_qs);
    qmlRegisterType<Squircle>("Squircle", 1, 0, "Squircle");

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
