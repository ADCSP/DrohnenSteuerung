#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "myodevicelistener.h"
#include "myo/myo.hpp"

//später Qdebug löschen
#include <QDebug>

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



void MainWindow::startMyo()
{

    try

    {
        //Application Identifier muss ein reverse String sein
        myo::Hub hub("com.adcsp.myo");

        qDebug()<<"Verbundenes Myo wird gesucht...";

        myo::Myo* myo =hub.waitForMyo(10000);

        if(!myo)
        {
            qDebug()<<"Myo nicht gefunden.";
        }

            qDebug()<<"Myo wurde gefunden.";

            MyoDeviceListener myoDL;

            hub.addListener(&myoDL);

            while (1)
            {
            hub.run(1000/20);

            }
    }


catch(std::exception& e )
    {
        qDebug()<<"error: "<<e.what();
    }


}

void MainWindow::on_pushButton_clicked()
{
    startMyo();
}
