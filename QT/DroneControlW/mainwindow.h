#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:



    void on_actionArmband_triggered();

    void on_DroneControl_clicked();

    void on_actionSprachsteuerung_triggered();

    void on_actionJoystick_triggered();

    void startMyo();
    void on_pushButton_clicked();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
