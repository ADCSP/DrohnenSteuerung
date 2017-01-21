#include "threadhandler.h"


ThreadHandler::ThreadHandler()
{
    thread          = new QThread();
    worker          = new MyoThraed();

    worker->moveToThread(thread);
    QObject::connect(thread, SIGNAL(started()), worker, SLOT(runAgain()));
    //QObject::connect(timer, SIGNAL(timeout()), worker, SLOT(runAgain()));
    QObject::connect(worker, SIGNAL(iFinished()), this, SLOT(functionFinished()));
    //QObject::connect(shutdown, SIGNAL(timeout()), thread, SLOT(quit()));
    QObject::connect(thread, SIGNAL(finished()), this, SLOT(threadTerminated()));

}

ThreadHandler::~ThreadHandler() {
    QObject::disconnect(thread, SIGNAL(started()), worker, SLOT(runAgain()));
    //QObject::disconnect(timer, SIGNAL(timeout()), worker, SLOT(runAgain()));
    QObject::disconnect(worker, SIGNAL(iFinished()), this, SLOT(functionFinished()));
    //QObject::disconnect(shutdown, SIGNAL(timeout()), thread, SLOT(quit()));
    QObject::disconnect(thread, SIGNAL(finished()), this, SLOT(threadTerminated()));

}

void ThreadHandler::functionFinished() {
    qDebug() << "Worker has finished. (" << QThread::currentThreadId() << ")";

}

void ThreadHandler::threadTerminated() {
    qDebug() << "Thread stopped.";
}

void ThreadHandler::StartThread() {
    thread->start();
}
