#ifndef MYOTHRAED_H
#define MYOTHRAED_H

#include <QObject>
#include <MyoDeviceListener.h>
#include "MyoSignalBridge.h"

class MyoThraed : public QObject
{
    Q_OBJECT
public:
   // MyoThraed(MyoSignalBridge msb);
    MyoThraed();
    bool b;
    MyoSignalBridge* msb;

public slots:
    void runAgain();

signals:
    void iFinished();
    void fist();
    void spread();
    void wave_in();
    void wave_out();
    void locked();
    void unlocked();
    void synced();
    void unsynced();
    void connected();
    void disconnected();
private:
    void doWork();
};

#endif // MYOTHRAED_H
