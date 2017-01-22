#ifndef MYOTHRAED_H
#define MYOTHRAED_H

#include <QObject>
#include <myodevicelistener.h>
#include "MyoSignalBridge.h"

class MyoThraed : public QObject
{
    Q_OBJECT
public:
    MyoThraed();
    bool b;
    MyoSignalBridge* msb;
public slots:
    void runAgain();

signals:
    void iFinished();
    void fist();

private:
    void doWork();
};

#endif // MYOTHRAED_H
