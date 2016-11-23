#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->actionArmband->setEnabled(false);
    ui->fSprache->setVisible(false);
    ui->fJoystick->setVisible(false);

}

MainWindow::~MainWindow()
{
    delete ui;

}


void MainWindow::on_DroneControl_clicked()
{
    qApp->quit();
}

void MainWindow::on_actionArmband_triggered()
{
    ui->actionArmband->setEnabled(false);
    ui->actionJoystick->setEnabled(true);
    ui->actionSprachsteuerung->setEnabled(true);

    ui->fSprache->setVisible(false);
    ui->frArmband->setVisible(true);
    ui->fJoystick->setVisible(false);
}


void MainWindow::on_actionSprachsteuerung_triggered()
{
    ui->actionArmband->setEnabled(true);
    ui->actionJoystick->setEnabled(true);
    ui->actionSprachsteuerung->setEnabled(false);

    ui->frArmband->setVisible(false);
    ui->fSprache->setVisible(true);
    ui->fJoystick->setVisible(false);
}

void MainWindow::on_actionJoystick_triggered()
{
    ui->actionArmband->setEnabled(true);
    ui->actionJoystick->setEnabled(false);
    ui->actionSprachsteuerung->setEnabled(true);

    ui->frArmband->setVisible(false);
    ui->fSprache->setVisible(false);
    ui->fJoystick->setVisible(true);
}
