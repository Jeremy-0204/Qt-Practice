#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <connectevent.h>
#include <QQuickView>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    ConnectEvent *event = new ConnectEvent();

    const QUrl url(u"qrc:/QT_SignalPractice_2/Main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    QObject *root = engine.rootObjects()[0];

    event->SetWindow(qobject_cast<QQuickWindow *>(root));

    return app.exec();
}
