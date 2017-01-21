#ifndef MYOTHRAED_H
#define MYOTHRAED_H

#include <QObject>
#include  <myodevicelistener.h>

class MyoThraed : public QObject
{
    Q_OBJECT
public:
    MyoThraed();
    bool b;
public slots:
    void runAgain();

signals:
    void iFinished();

private:
    void doWork();
};

#endif // MYOTHRAED_H
