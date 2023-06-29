#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "OpenGLTriangleItem.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    // Register OpenGLItem as a QML type
    qmlRegisterType<OpenGLTriangleItem>("OpenGLTriangleItem", 1, 0, "OpenGLTriangleItem");

    // Load the main QML file
    const QUrl url(QStringLiteral("qrc:/OpenGL_Sample/Main.qml"));
    engine.load(url);

    return app.exec();
}
