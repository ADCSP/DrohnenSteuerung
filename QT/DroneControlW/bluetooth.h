#ifndef BLUETOOTH_H
#define BLUETOOTH_H
#include <QObject>

class Bluetooth:public QObject
{
Q_OBJECT

public:
    Bluetooth();


public slots:

    void connectBT();

};

#endif // BLUETOOTH_H
