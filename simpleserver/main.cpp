#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickWindow>
#include "server.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    server *mServer = new server(&app);

    QQmlApplicationEngine engine;
    QQmlContext* context = engine.rootContext();
    context->setContextProperty("server",mServer);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    auto topLevelObject = engine.rootObjects().value(0);
    auto window = qobject_cast<QQuickWindow *>(topLevelObject);
    window->show();

    qDebug() << window->width() << window->height();

    QObject::connect(window, &QQuickWindow::heightChanged, [&](){
    mServer->heightChangedHandler(window->height());
    });

    QObject::connect(window, &QQuickWindow::widthChanged, [&](){
    mServer->widthChangedHandler(window->width());
    });

    return app.exec();
}
