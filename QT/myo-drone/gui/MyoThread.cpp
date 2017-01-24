#include "MyoThread.h"

#include <QThread>
#include <QDebug>

MyoThraed::MyoThraed()
{
    this->b = true;
    //this->msb = msb;
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
                msb = myoDL.msb;
                connect(msb,    SIGNAL(fist()),     this,   SIGNAL(fist()));
                connect(msb,    SIGNAL(spread()),   this,   SIGNAL(spread()));
                connect(msb,    SIGNAL(locked()),   this,   SIGNAL(locked()));
                connect(msb,    SIGNAL(unlocked()), this,   SIGNAL(unlocked()));
                connect(msb,    SIGNAL(wave_in()),  this,   SIGNAL(wave_in()));
                connect(msb,    SIGNAL(wave_out()), this,   SIGNAL(wave_out()));
                connect(msb,    SIGNAL(synced()),   this,   SIGNAL(synced()));
                connect(msb,    SIGNAL(unsynced()), this,   SIGNAL(unsynced()));
                connect(msb,    SIGNAL(connected()),this,   SIGNAL(connected()));
                connect(msb,    SIGNAL(disconnected()),this, SIGNAL(disconnected()));
                 hub.addListener(&myoDL);
               // hub.addListener(myoDL);


                while (b)
                {
                    hub.run(1000/20);
                    // falls notwendig communication erlauben
                }
            }
    }
    catch(std::exception& e )
    {
        qDebug()<<"error: "<<e.what();
    }

    emit iFinished();
}
