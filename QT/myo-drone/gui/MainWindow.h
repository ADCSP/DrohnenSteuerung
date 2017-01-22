#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <vector>
#include <QMainWindow>
#include <CommandDebugWindow.h>
#include <NavdataDebugWindow.h>
#include <ControlWindow.h>
#include <CVDrone.h>
#include <CommandService.h>
#include <NavdataService.h>
#include "threadhandler.h"
#include "MyoSignalBridge.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    ThreadHandler* handler();
    explicit MainWindow(Drone::CVDrone *cvDrone, QWidget *parent = 0);
    void keyPressEvent(QKeyEvent *e) override;
    void keyReleaseEvent(QKeyEvent *e) override;
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent *event) override;

private:
    Ui::MainWindow *ui;
    CommandDebugWindow *commandDebug;
    NavdataDebugWindow *navdataDebug;
    ControlWindow *controlWindow;
    Drone::CVDrone *cvDrone;
    Drone::CommandService *commandService;
    Drone::NavdataService *navdataService;
    MyoSignalBridge *msb;
    ThreadHandler *handler;

    QPixmap fist_R;
    QPixmap fist_Rs;
    QPixmap fist_L;
    QPixmap fist_Ls;
    QPixmap unlock_R;
    QPixmap unlock_Rs;
    QPixmap unlock_L;
    QPixmap unlock_Ls;
    QPixmap wave_in_R;
    QPixmap wave_in_Rs;
    QPixmap wave_in_L;
    QPixmap wave_in_Ls;
    QPixmap wave_out_R;
    QPixmap wave_out_Rs;
    QPixmap wave_out_L;
    QPixmap wave_out_Ls;
    QPixmap spread_R;
    QPixmap spread_Rs;
    QPixmap spread_L;
    QPixmap spread_Ls;
    QPixmap connect_myo_on;
    QPixmap connect_myo_off;
    QPixmap myo_locked;
    QPixmap myo_unlocked;
    QPixmap myo_detail;
    void changeArm(bool);

signals:
    void closed();

public slots:

    void toggleControlWindow(bool toggle);
    void toggleCommandDebug(bool toggle);
    void toggleNavdataDebug(bool toggle);
    void toggleTakeOffLand(bool toggle);
    void detectToggled(bool toggle);
    void controlWindowClosed();
    void commandDebugWindowClosed();
    void navdataDebugWindowClosed();
    void showFrame(QPixmap pixmap);
    void startMyo(bool active);


private slots:
    void on_actionJoystick_triggered();
    void on_actionArmband_triggered();
    void on_actionSprache_triggered();
    void on_actionVideo_toggled(bool toggle);
    void on_myo_fist();
    void on_myo_spread();
    void on_myo_wave_in();
    void on_myo_wave_out();
    void on_myo_no_gesture();
    void on_myo_connect();
    void on_myo_disconnect();
    void on_myo_sync();
    void on_myo_unsync();
    void on_myo_locked();
    void on_myo_unlocked();
};

#endif // MAINWINDOW_H
