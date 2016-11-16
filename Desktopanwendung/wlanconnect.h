#ifndef WLANCONNECT_H
#define WLANCONNECT_H
#include <iostream>

using namespace std;

#include <QDebug>
#include <QObject>

class WlanConnect : public QObject
{
    Q_OBJECT
public:
    void test(const QString &msg)
    {
       qDebug() << "test mit: "<<msg;
    }
public slots:

    void cppSlot(const QString &msg)
    {
        test(msg);

    }
    WlanConnect();
};

#endif // WLANCONNECT_H
