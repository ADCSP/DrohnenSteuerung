#include "myothraed.h"

#include <QThread>
#include <QDebug>
MyoThraed::MyoThraed()
{
    this->b = true;
}

void MyoThraed::runAgain() {
    doWork();
}

void MyoThraed::doWork() {
    qDebug() << "I WORK...\t(" << QThread::currentThreadId() << ")";


    try
    {
        //Application Identifier muss ein reverse String sein
        myo::Hub hub("com.adcsp.myo");

        qDebug()<<"Verbundenes Myo wird gesucht...";
        myo::Myo* myo =hub.waitForMyo(10000);


        if(!myo)
            {
                qDebug()<<"Myo nicht gefunden.";
            }
         else
            {
                qDebug()<<"Myo wurde gefunden.";
                MyoDeviceListener myoDL;

                hub.addListener(&myoDL);

                while (b)
                {
                    hub.run(1000/20);
                }
            }
    }
    catch(std::exception& e )
    {
        qDebug()<<"error: "<<e.what();
    }

    emit iFinished();
}
