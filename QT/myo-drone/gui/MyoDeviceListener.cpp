#include "MyoDeviceListener.h"
#include <QDebug>


MyoDeviceListener::MyoDeviceListener()
{
    this->msb = new MyoSignalBridge();

    //this->msb = MyoSignalBridge::instance();
}

void MyoDeviceListener:: onArmSync(myo::Myo *myo, uint64_t timestamp, myo::Arm arm, myo::XDirection xDirection, float rotation, myo::WarmupState warmupState)
{
    qDebug()<<"synced";
    // 0 right arm, 1 left arm
    //  qDebug()<<arm;
    msb->sendSynced();
}

void MyoDeviceListener::onArmUnsync(myo::Myo *myo, uint64_t timestamp)
{
    qDebug()<<"unsynced";
    msb->sendUnsynced();
}

void MyoDeviceListener::onBatteryLevelReceived(myo::Myo *myo, uint64_t timestamp, uint8_t level)
{
    qDebug()<<"battery"<<level;
}

void MyoDeviceListener::onPair(myo::Myo *myo, uint64_t timestamp, myo::FirmwareVersion firmwareVersion)
{
    qDebug()<<"Paired";
}

void MyoDeviceListener::onUnpair(myo::Myo *myo, uint64_t timestamp)
{
    qDebug()<<"unpaired";
}
void MyoDeviceListener::onLock(myo::Myo *myo, uint64_t timestamp)
{
    qDebug()<<"locked";
    msb->sendLocked();
}

void MyoDeviceListener:: onUnlock(myo::Myo *myo, uint64_t timestamp)
{
    qDebug()<<"unlocked";
    msb->sendUnlocked();
}

void MyoDeviceListener:: onConnect(myo::Myo *myo, uint64_t timestamp, myo::FirmwareVersion firmwareVersion)
{
    qDebug()<<"Connected";
    //msb->sendConnected();
}

void MyoDeviceListener:: onDisconnect(myo::Myo *myo, uint64_t timestamp)
{
    qDebug()<<"Disconnected";
    //msb->sendDisconnected();
}

void MyoDeviceListener::onPose(myo::Myo *myo, uint64_t timestamp, myo::Pose pose)
{
    switch(pose.type())
    {
    case 1:
        qDebug()<<"Fist";
        myo->notifyUserAction();
        msb->sendFist();
        break;
    case 2:
        qDebug()<<"Wave in";
        myo->notifyUserAction();
        msb->sendWaveIn();
        break;
    case 3:
        qDebug()<<"Wave out";
        myo->notifyUserAction();
        msb->sendWaveOut();
        break;
    case 4:
        qDebug()<<"Spread Fingers";
        myo->notifyUserAction();
        msb->sendSpread();
        break;
    }
    myo->unlock(myo->unlockHold);

    if (pose.type()==5)
    {
        qDebug()<<"double tapped";
        qDebug()<<"Lock.";
        myo->lock();
    }
}
