#include "MyoThreadHandler.h"


ThreadHandler::ThreadHandler()
{
    thread          = new QThread();
    worker          = new MyoThraed();
    //this->msb       = msb;

    worker->moveToThread(thread);
    connect(worker,     SIGNAL(fist()),         this,       SIGNAL(fist()));
    connect(worker,     SIGNAL(spread()),       this,       SIGNAL(spread()));
    connect(worker,     SIGNAL(wave_in()),      this,       SIGNAL(wave_in()));
    connect(worker,     SIGNAL(wave_out()),     this,       SIGNAL(wave_out()));
    connect(worker,     SIGNAL(locked()),       this,       SIGNAL(locked()));
    connect(worker,     SIGNAL(unlocked()),     this,       SIGNAL(unlocked()));
    connect(worker,     SIGNAL(synced()),       this,       SIGNAL(synced()));
    connect(worker,     SIGNAL(unsynced()),     this,       SIGNAL(unsynced()));
    connect(thread,     SIGNAL(started()),      worker,     SLOT(runAgain()));
    connect(worker,     SIGNAL(iFinished()),    this,       SLOT(functionFinished()));
    connect(thread,     SIGNAL(finished()),     this,       SLOT(threadTerminated()));
}

ThreadHandler::~ThreadHandler() {
    disconnect(thread,  SIGNAL(started()),      worker,     SLOT(runAgain()));
    disconnect(worker,  SIGNAL(iFinished()),    this,       SLOT(functionFinished()));
    disconnect(thread,  SIGNAL(finished()),     this,       SLOT(threadTerminated()));
}

void ThreadHandler::functionFinished() {
    qDebug() << "Worker has finished. (" << QThread::currentThreadId() << ")";

}

void ThreadHandler::threadTerminated() {
    //thread->destroyed();
    qDebug() << "Thread stopped.";
}

void ThreadHandler::StartThread() {
    thread->start();
}

void ThreadHandler::StopThread() {
    qDebug() << "Thread stopped.";
    thread->terminate();
}
