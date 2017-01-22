#ifndef MYOSIGNALBRIDGE_H
#define MYOSIGNALBRIDGE_H

#include <QObject>

class MyoSignalBridge : public QObject
{
    Q_OBJECT
public:
    static MyoSignalBridge* instance();
    void sendFist();
    void sendSpread();
    void sendWaveIn();
    void sendWaveOut();
    void sendLocked();
    void sendUnlocked();
    void sendSynced();
    void sendUnsynced();

private:
    MyoSignalBridge();
    static MyoSignalBridge* msb;

signals:
   void fist();
   void spread();
   void wave_in();
   void wave_out();
   void locked();
   void unlocked();
   void synced();
   void unsynced();
};

#endif // MYOSIGNALBRIDGE_H
