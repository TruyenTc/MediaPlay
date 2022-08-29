#include "folder.h"
#include <QApplication>
#include <QQmlApplicationEngine>
#include "folder.h"
#include "readfile.h"
#include "objectmodel1.h"
#include <QQmlContext>
#include "qplayer.h"
#include <translator.h>
#include "songloader.h"



int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QApplication app(argc, argv);



    folder FolDer;
    ObjectModel12 OBJ;
    Qplayer Play;



    QQmlApplicationEngine engine;
    Translator translator(&engine, &app);
    const QUrl url(QStringLiteral("qrc:/main.qml"));

    QQmlContext *approot = engine.rootContext();

    approot->setContextProperty("folder", &FolDer);

    approot->setContextProperty("playlist", &OBJ);

    approot->setContextProperty("play", &Play);

    approot->setContextProperty("translator", &translator);


    QObject::connect(&FolDer, &folder::addressChanged,
                     &OBJ, &ObjectModel12::add_Data);

    QObject::connect(&FolDer, &folder::folderChanged,
                     &Play, &Qplayer::stop);

    QObject::connect(&FolDer, &folder::changIndex,
                     &OBJ, &ObjectModel12::setIndex);

    QObject::connect(&OBJ, &ObjectModel12::getsourceChanged,
                     &Play, &Qplayer::setsource);


    QObject::connect(&OBJ, &ObjectModel12::getindex_player,
                     &Play, &Qplayer::index_listmodel);

    QObject::connect(&Play, &Qplayer::setIndex_model,
                     &OBJ, &ObjectModel12::setIndex);



    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
