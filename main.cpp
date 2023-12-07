#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "core/databasehandler.h"

int main(int argc, char *argv[]){
    QApplication app(argc, argv);

    bool status = true;
    DatabaseHandler *bdd = new DatabaseHandler(&status);

    if(!status){
        delete bdd;
        return -1;
    }

    QQmlApplicationEngine engine;

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated, &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl) QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    QQmlContext *context = engine.rootContext();

    context->setContextProperty("handler", bdd);

    engine.load(url);

    return app.exec();
}

