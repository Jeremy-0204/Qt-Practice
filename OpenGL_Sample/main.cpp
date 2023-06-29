#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "OpenGLTriangleItem.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    // Register OpenGLItem as a QML type
    // qmlRegisterType<OpenGLTriangleItem>("OpenGLTriangleItem", 1, 0, "OpenGLTriangleItem");

    // Create an OpenGLTriangleItem
    OpenGLTriangleItem *triangleItem = new OpenGLTriangleItem();

    // Initialize the OpenGLTriangleItem
    triangleItem->initializeOpenGL();

    // Add the OpenGLTriangleItem to the scene
    engine.rootContext()->setContextProperty("triangleItem", triangleItem);

    // Load the main QML file
    const QUrl url(QStringLiteral("qrc:/OpenGL_Sample/Main.qml"));
    engine.load(url);

    return app.exec();
}
