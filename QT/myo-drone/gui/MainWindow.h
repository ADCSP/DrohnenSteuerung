#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <vector>
#include <QMainWindow>
//#include <VideoSettingsWindow.h>
#include <CommandDebugWindow.h>
#include <NavdataDebugWindow.h>
//#include <OpenCVDebugWindow.h>
#include <ControlWindow.h>
#include <CVDrone.h>
//#include <VideoService.h>
#include <CommandService.h>
#include <NavdataService.h>
//#include <ObjectDetector.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //explicit MainWindow(Drone::CVDrone *cvDrone, ObjectDetection::ObjectDetector *objectDetector, QWidget *parent = 0);
    explicit MainWindow(Drone::CVDrone *cvDrone, QWidget *parent = 0);
    void keyPressEvent(QKeyEvent *e) override;
    void keyReleaseEvent(QKeyEvent *e) override;
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent *event) override;

private:
    Ui::MainWindow *ui;
    //VideoSettingsWindow *videoSettings;
    CommandDebugWindow *commandDebug;
    NavdataDebugWindow *navdataDebug;
   // OpenCVDebugWindow *openCVDebug;
    ControlWindow *controlWindow;
    //ObjectDetection::ObjectDetector *objectDetector;
    Drone::CVDrone *cvDrone;
    Drone::CommandService *commandService;
    Drone::NavdataService *navdataService;
    //Drone::VideoService *videoService;
    //cv::Mat img;

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
    QPixmap myo_detail;
    void changeArm(bool);

signals:
    void closed();

public slots:
    void toggleControlWindow(bool toggle);
    //void toggleVideoSettings(bool toggle);
    void toggleCommandDebug(bool toggle);
    void toggleNavdataDebug(bool toggle);
    //void toggleOpenCVDebug(bool toggle);
    void toggleTakeOffLand(bool toggle);
    void detectToggled(bool toggle);
    void controlWindowClosed();
    void commandDebugWindowClosed();
    void navdataDebugWindowClosed();
   // void openCVDebugWindowClosed();
    //void videoSettingsWindowClosed();
    void showFrame(QPixmap pixmap);
private slots:
    void on_actionJoystick_triggered();
    void on_actionArmband_triggered();
    void on_actionSprache_triggered();
};

#endif // MAINWINDOW_H
