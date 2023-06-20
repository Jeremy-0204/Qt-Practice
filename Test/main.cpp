#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext> // 이 부분 추가
#include <QQmlEngine>
#include "serialport.h"
#include "superlumbs840.h"

MGEN_NAMESPACE_USE;

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    qmlRegisterType<SerialPort>("SerialPort", 1, 0, "SerialPort");
//    SuperlumBS840 mySuperlumBS840; // SuperlumBS840 인스턴스 생성

    // QML 컨텍스트에 SuperlumBS840 인스턴스 등록
//    engine.rootContext()->setContextProperty("SuperlumBS840", &mySuperlumBS840);
    qmlRegisterType<SuperlumBS840>("SuperlumBS840", 1, 0, "SuperlumBS840");

    const QUrl url(QStringLiteral("qrc:/Test/Main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    engine.load(url);

    return app.exec();
}
