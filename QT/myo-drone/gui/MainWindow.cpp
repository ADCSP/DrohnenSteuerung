#include "MainWindow.h"
#include "ui_MainWindow.h"

/*
 * CV-Drone
 * Copyright (C) 2015 www.burntbunch.org
 *
 * This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation; either version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License along with this library;
 * if not, write to the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110, USA
 */

/*!
 * \brief MainWindow::MainWindow creates a MainWindow and connects all signals and slots
 *
 * \param *cvDrone
 * \param *objectDetector
 * \param *parent
 */
MainWindow::MainWindow(Drone::CVDrone *cvDrone, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->cvDrone           = cvDrone;
    this->commandService    = cvDrone->getCommandService();
    this->navdataService    = cvDrone->getNavdataService();

    ui->videoContainer->setScaledContents(true);

    connect(ui->actionControl_Window,   SIGNAL(toggled(bool)),              this,           SLOT(toggleControlWindow(bool)));
    connect(ui->actionCommands,         SIGNAL(toggled(bool)),              this,           SLOT(toggleCommandDebug(bool)));
    connect(ui->actionNavdata,          SIGNAL(toggled(bool)),              this,           SLOT(toggleNavdataDebug(bool)));

    connect(ui->actionReconnect,        SIGNAL(triggered()),                commandService, SLOT(reconnect()));
    connect(ui->actionNavdata_Service,  SIGNAL(triggered()),                navdataService, SLOT(reconnect()));

    connect(ui->buttonStart,            SIGNAL(clicked(bool)),              this,           SLOT(toggleTakeOffLand(bool)));
    connect(ui->buttonEmergency,        SIGNAL(clicked()),                  cvDrone,        SLOT(emergency()));
    connect(ui->buttonDetect,           SIGNAL(toggled(bool)),              this,           SLOT(detectToggled(bool)));

}

/*!
 * \brief MainWindow::MainWindow deletes the MainWindow.
 */
MainWindow::~MainWindow()
{
    disconnect();
    delete ui;
}

/*!
 * \brief MainWindow::closeEvent emits the closed() event
 * \param event this parameter is ignored, but requiered by the super class
 */
void MainWindow::closeEvent(QCloseEvent *event)
{
    emit closed();
}

/*!
 * \brief MainWindow::toggleControlWindow either opens or closes the ControlWindow
 */
void MainWindow::toggleControlWindow(bool toggle)
{
    if(toggle)
    {
        controlWindow = new ControlWindow(cvDrone);
        connect(controlWindow,  SIGNAL(closed()),   this,           SLOT(controlWindowClosed()));
        connect(this,           SIGNAL(closed()),   controlWindow,  SLOT(close()));
        controlWindow->show();
    }
    else
        controlWindow->close();
}


/*!
 * \brief MainWindow::toggleCommandDebug either opens or closes the CommandDebugWindow
 */
void MainWindow::toggleCommandDebug(bool toggle)
{
    if(toggle)
    {
        commandDebug = new CommandDebugWindow(commandService);
        connect(commandDebug,  SIGNAL(closed()),   this,            SLOT(commandDebugWindowClosed()));
        connect(this,          SIGNAL(closed()),   commandDebug,    SLOT(close()));
        commandDebug->show();
    }
    else
        commandDebug->close();
}

/*!
 * \brief MainWindow::toggleNavdataDebug either opens or closes the NavdataDebugWindow
 */
void MainWindow::toggleNavdataDebug(bool toggle)
{
    if(toggle)
    {
        navdataDebug = new NavdataDebugWindow(navdataService);
        connect(navdataDebug,  SIGNAL(closed()),   this,            SLOT(navdataDebugWindowClosed()));
        connect(this,          SIGNAL(closed()),   navdataDebug,    SLOT(close()));
        navdataDebug->show();
    }
    else
        navdataDebug->close();
}

/*!
 * \brief MainWindow::toggleTakeOffLand either starts or lands the Drone
 */
void MainWindow::toggleTakeOffLand(bool toggle)
{
    if(toggle)
    {
        ui->buttonStart->setText("Land");
        cvDrone->takeOff();
    }
    else
    {
        ui->buttonStart->setText("Start");
        cvDrone->land();
    }
}

void MainWindow::detectToggled(bool toggle)
{
    if(!toggle)
        ui->buttonAutopilot->setChecked(false);
}

/*!
 * \brief MainWindow::controlWindowClosed is processed when ethe ControlWindow is closed.
 * The corresponding checkBox will be unchecked.
 */
void MainWindow::controlWindowClosed()
{
    ui->actionControl_Window->setChecked(false);
    controlWindow->disconnect();
    delete controlWindow;
}

/*!
 * \brief MainWindow::commandDebugWindowClosed is processed when ethe CommandDebugWindow is closed.
 * The corresponding checkBox will be unchecked.
 */
void MainWindow::commandDebugWindowClosed()
{
    ui->actionCommands->setChecked(false);
    commandDebug->disconnect();
    delete commandDebug;
}

/*!
 * \brief MainWindow::navdataDebugWindowClosed is processed when ethe NavdataDebugWindow is closed.
 * The corresponding checkBox will be unchecked.
 */
void MainWindow::navdataDebugWindowClosed()
{
    ui->actionNavdata->setChecked(false);
    navdataDebug->disconnect();
    delete navdataDebug;
}

/*!
 * \brief MainWindow::showFrame shows the pixmap on the videoLabel.
 * \param pixmap the pixmap to show.
 */
void MainWindow::showFrame(QPixmap pixmap)
{
    ui->videoContainer->setPixmap(pixmap);
}
