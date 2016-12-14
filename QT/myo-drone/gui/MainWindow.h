#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <vector>
#include <QMainWindow>
#include <CommandDebugWindow.h>
#include <NavdataDebugWindow.h>
#include <ControlWindow.h>
#include <CVDrone.h>
#include <VideoService.h>
#include <CommandService.h>
#include <NavdataService.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(Drone::CVDrone *cvDrone, QWidget *parent = 0);
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
};

#endif // MAINWINDOW_H
