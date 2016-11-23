#include <QApplication>
#include <QQmlApplicationEngine>
#include "wlanconnect.h"

void connectNow()
{

}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    QObject *item = engine.rootObjects().first();

    WlanConnect wConnect;
    QObject::connect(item, SIGNAL(qmlSignal(QString)),
                     &wConnect, SLOT(cppSlot(QString)));


    return app.exec();
}
