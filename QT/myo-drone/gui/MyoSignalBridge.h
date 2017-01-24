#ifndef MYOSIGNALBRIDGE_H
#define MYOSIGNALBRIDGE_H

#include <QObject>

class MyoSignalBridge : public QObject
{
    Q_OBJECT
public:
    void sendFist();
    void sendSpread();
    void sendWaveIn();
    void sendWaveOut();
    void sendLocked();
    void sendUnlocked();
    void sendSynced();
    void sendUnsynced();
    void sendConnected();
    void sendDisconncted();
    MyoSignalBridge();

signals:
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
};

#endif // MYOSIGNALBRIDGE_H
