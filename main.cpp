#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "core/databasewrapper.h"

int main(int argc, char *argv[]){

    QApplication app(argc, argv);

    QQmlApplicationEngine engine;

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated, &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl) QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    QQmlContext *context = engine.rootContext();

    DatabaseWrapper wrapper;

    context->setContextProperty("accounts", wrapper.getAccounts());
    context->setContextProperty("list_categories", wrapper.getCategories());


    engine.load(url);

    return app.exec();
}
