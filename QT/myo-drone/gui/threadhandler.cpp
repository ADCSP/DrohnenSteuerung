#include "threadhandler.h"


ThreadHandler::ThreadHandler()
{
    thread          = new QThread();
    worker          = new MyoThraed();

    worker->moveToThread(thread);
    connect(worker,     SIGNAL(fist()),         this,       SIGNAL(fist()));
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
