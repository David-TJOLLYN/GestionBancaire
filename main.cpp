#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "core/databasehandler.h"

int main(int argc, char *argv[]){
    QApplication app(argc, argv);

    DatabaseHandler *bdd = new DatabaseHandler();

    QQmlApplicationEngine engine;

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated, &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl) QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    QQmlContext *context = engine.rootContext();

    context->setContextProperty("handler", bdd);
    context->setContextProperty("list_categories", bdd->getCategories());

    engine.load(url);

    return app.exec();
}

