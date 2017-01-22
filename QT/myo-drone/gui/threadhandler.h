#ifndef THREADHANDLER_H
#define THREADHANDLER_H

#include <QObject>
#include <QThread>
#include <QDebug>

#include "myothraed.h"



class ThreadHandler: public QObject
{
    Q_OBJECT
public:
    ThreadHandler();
    ~ThreadHandler();
    void StartThread();
    void StopThread();

public slots:
    void functionFinished();
    void threadTerminated();

private:
    //QTimer*     shutdown;
    QThread*    thread;
    MyoThraed*    worker;
};

#endif // THREADHANDLER_H
