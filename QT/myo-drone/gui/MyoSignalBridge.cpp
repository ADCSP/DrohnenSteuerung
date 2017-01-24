#include "MyoSignalBridge.h"

MyoSignalBridge::MyoSignalBridge()
{

}

void MyoSignalBridge::sendFist()
{
    emit fist();
}

void MyoSignalBridge::sendSpread()
{
    emit spread();
}

void MyoSignalBridge::sendWaveIn()
{
    emit wave_in();
}

void MyoSignalBridge::sendWaveOut()
{
    emit wave_out();
}

void MyoSignalBridge::sendLocked()
{
    emit locked();
}

void MyoSignalBridge::sendUnlocked()
{
    emit unlocked();
}

void MyoSignalBridge::sendSynced()
{
    emit synced();
}

void MyoSignalBridge::sendUnsynced()
{
    emit unsynced();
}

void MyoSignalBridge::sendConnected()
{
    emit connected();
}

void MyoSignalBridge::sendDisconncted()
{
    emit disconnected();
}
