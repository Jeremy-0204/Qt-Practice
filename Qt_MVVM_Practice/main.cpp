#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <model.h>
#include <viewmodel.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    ViewModel viewModel;

    const QUrl url(u"qrc:/Qt_MVVM_Practice/Main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.rootContext()->setContextProperty("viewModel", &viewModel);
    engine.load(url);

    return app.exec();
}
