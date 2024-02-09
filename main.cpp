#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QTranslator>

#include "core/databasehandler.h"

int main(int argc, char *argv[]){
    QApplication app(argc, argv);

    QTranslator translator;
    if(!translator.load("bankhandler_en.qm")){
        qDebug()<<"Fail to load translator";
        return 1;
    }
    app.installTranslator(&translator);


    bool status = true;
    DatabaseHandler *bdd = new DatabaseHandler(&status);

    if(!status){
        delete bdd;
        return 2;
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

