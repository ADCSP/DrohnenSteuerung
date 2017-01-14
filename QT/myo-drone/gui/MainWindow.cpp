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
MainWindow::MainWindow(Drone::CVDrone *cvDrone, ObjectDetection::ObjectDetector *objectDetector, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->objectDetector    = objectDetector;
    this->cvDrone           = cvDrone;
    this->commandService    = cvDrone->getCommandService();
    this->navdataService    = cvDrone->getNavdataService();
    this->videoService      = cvDrone->getVideoService();

    this->fist_small        = QPixmap("/home/luna/git/DrohnenSteuerung/QT/myo-drone/gui/Icons/fist50.png");
    this->unlock_small      = QPixmap("/home/luna/git/DrohnenSteuerung/QT/myo-drone/gui/Icons/unlock50.png");
    this->wave_left_small   = QPixmap("/home/luna/git/DrohnenSteuerung/QT/myo-drone/gui/Icons/wave_left50.png");
    this->wave_right_small  = QPixmap("/home/luna/git/DrohnenSteuerung/QT/myo-drone/gui/Icons/wave_right50.png");
    this->spread_small      = QPixmap("/home/luna/git/DrohnenSteuerung/QT/myo-drone/gui/Icons/spread50.png");
    this->connect_myo_on    = QPixmap("/home/luna/git/DrohnenSteuerung/QT/myo-drone/gui/Icons/thalmic_logo_colo50.png");
    this->connect_myo_off   = QPixmap("/home/luna/git/DrohnenSteuerung/QT/myo-drone/gui/Icons/thalmic_logo_grey50.png");
    this->myo_detail        = QPixmap("/home/luna/git/DrohnenSteuerung/QT/myo-drone/gui/Icons/myo.png");

    //this->fist_small        = QPixmap(":/small/fist50.png");
    //this->unlock_small      = QPixmap(":/small/unlock");
    //this->wave_left_small   = QPixmap(":/small/wave_left");
    //this->wave_right_small  = QPixmap(":/small/wave_right");
    //this->spread_small      = QPixmap(":/small/spread");
    //this->connect_myo_on    = QPixmap(":/small/connection_on");
    //this->connect_myo_off   = QPixmap(":/small/connection_off");
    //this->myo_detail        = QPixmap(":/big/myo");

    this->setWindowIcon(connect_myo_on);

    ui->lbFist      ->setPixmap(fist_small);
    ui->lbUnlock    ->setPixmap(unlock_small);
    ui->lbLeft      ->setPixmap(wave_left_small);
    ui->lbRight     ->setPixmap(wave_right_small);
    ui->lbSpread    ->setPixmap(spread_small);
    ui->lbThalmic   ->setPixmap(connect_myo_off);
    ui->lbMyo       ->setPixmap(myo_detail);

    setFocusPolicy(Qt::StrongFocus);

    ui->videoContainer->setScaledContents(true);

    connect(ui->actionControl_Window,   SIGNAL(toggled(bool)),              this,           SLOT(toggleControlWindow(bool)));
    connect(ui->actionCommands,         SIGNAL(toggled(bool)),              this,           SLOT(toggleCommandDebug(bool)));
    connect(ui->actionNavdata,          SIGNAL(toggled(bool)),              this,           SLOT(toggleNavdataDebug(bool)));

    connect(ui->actionReconnect,        SIGNAL(triggered()),                commandService, SLOT(reconnect()));
    connect(ui->actionNavdata_Service,  SIGNAL(triggered()),                navdataService, SLOT(reconnect()));
    connect(ui->actionVideo_Service,    SIGNAL(triggered()),                videoService,   SLOT(reconnect()));

    connect(ui->buttonStart,            SIGNAL(clicked(bool)),              this,           SLOT(toggleTakeOffLand(bool)));
    connect(ui->buttonEmergency,        SIGNAL(clicked()),                  cvDrone,        SLOT(emergency()));

    connect(ui->bttnForward,            SIGNAL(pressed()),                  cvDrone,        SLOT(moveForward()));
    connect(ui->bttnBackward,           SIGNAL(pressed()),                  cvDrone,        SLOT(moveBackward()));
    connect(ui->bttnLeft,               SIGNAL(pressed()),                  cvDrone,        SLOT(moveLeft()));
    connect(ui->bttnRight,              SIGNAL(pressed()),                  cvDrone,        SLOT(moveRight()));
    connect(ui->bttnUp,                 SIGNAL(pressed()),                  cvDrone,        SLOT(moveUp()));
    connect(ui->bttnDown,               SIGNAL(pressed()),                  cvDrone,        SLOT(moveDown()));
    connect(ui->bttnTurnLeft,           SIGNAL(pressed()),                  cvDrone,        SLOT(turnLeft()));
    connect(ui->bttnTurnRight,          SIGNAL(pressed()),                  cvDrone,        SLOT(turnRight()));

    connect(ui->bttnForward,            SIGNAL(released()),                 cvDrone,        SLOT(hover()));
    connect(ui->bttnBackward,           SIGNAL(released()),                 cvDrone,        SLOT(hover()));
    connect(ui->bttnLeft,               SIGNAL(released()),                 cvDrone,        SLOT(hover()));
    connect(ui->bttnRight,              SIGNAL(released()),                 cvDrone,        SLOT(hover()));
    connect(ui->bttnUp,                 SIGNAL(released()),                 cvDrone,        SLOT(hover()));
    connect(ui->bttnDown,               SIGNAL(released()),                 cvDrone,        SLOT(hover()));
    connect(ui->bttnTurnLeft,           SIGNAL(released()),                 cvDrone,        SLOT(hover()));
    connect(ui->bttnTurnRight,          SIGNAL(released()),                 cvDrone,        SLOT(hover()));

    connect(ui->actionQuit,             SIGNAL(triggered()),                this,           SLOT(close()));

    connect(videoService,               SIGNAL(nextFrameReady()),           objectDetector, SLOT(colorFilter()));
    connect(videoService,               SIGNAL(connectionLost()),           objectDetector, SLOT(connectionLost()));

    connect(objectDetector,             SIGNAL(nextFrameReady(QPixmap)),    this,           SLOT(showFrame(QPixmap)));


    ui->actionOpenCV->setVisible(false);
    ui->actionVideo_Options->setVisible(false);

    ui->actionArmband->setEnabled(false);
    ui->actionControl_Window->setVisible(false);
    ui->frSprache->setVisible(false);
    ui->frJoystick->setVisible(false);
    ui->buttonDetect->setVisible(false);
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
 * \brief MainWindow::toggleVideoSettings either opens or closes the VideoSettingsWindow
 */
void MainWindow::toggleVideoSettings(bool toggle)
{
    if(toggle)
    {
        videoSettings = new VideoSettingsWindow(objectDetector);
        connect(videoSettings,  SIGNAL(closed()),   this,           SLOT(videoSettingsWindowClosed()));
        connect(this,           SIGNAL(closed()),   videoSettings,  SLOT(close()));
        videoSettings->show();
    }
    else
        videoSettings->close();
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
 * \brief MainWindow::toggleOpenCVDebug either opens or closes the OpenCVDebugWindow
 */
void MainWindow::toggleOpenCVDebug(bool toggle)
{
    if(toggle)
    {
        openCVDebug = new OpenCVDebugWindow(videoService, objectDetector);
        connect(openCVDebug,    SIGNAL(closed()),   this,           SLOT(openCVDebugWindowClosed()));
        connect(this,           SIGNAL(closed()),   openCVDebug,    SLOT(close()));
        openCVDebug->show();
    }
    else
        openCVDebug->close();
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
    //if(!toggle)
      //  ui->buttonAutopilot->setChecked(false);
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
 * \brief MainWindow::openCVDebugWindowClosed is processed when ethe OpenCVDebugWindow is closed.
 * The corresponding checkBox will be unchecked.
 */
void MainWindow::openCVDebugWindowClosed()
{
    ui->actionOpenCV->setChecked(false);
    openCVDebug->disconnect();
    delete openCVDebug;
}

/*!
 * \brief MainWindow::videoSettingsWindowClosed is processed when ethe VideoSettingsWindow is closed.
 * The corresponding checkBox will be unchecked.
 */
void MainWindow::videoSettingsWindowClosed()
{
    ui->actionVideo_Options->setChecked(false);
    videoSettings->disconnect();
    delete videoSettings;
}

/*!
 * \brief MainWindow::showFrame shows the pixmap on the videoLabel.
 * \param pixmap the pixmap to show.
 */
void MainWindow::showFrame(QPixmap pixmap)
{
    ui->videoContainer->setPixmap(pixmap);
}

/*!
 * \brief MainWindow::on_actionJoystick_triggered hides Armband and Sprache, and disables the menuentry
 */
void MainWindow::on_actionJoystick_triggered()
{
    ui->actionArmband->setEnabled(true);
    ui->actionJoystick->setEnabled(false);
    ui->actionSprache->setEnabled(true);

    ui->frArmband->setVisible(false);
    ui->frSprache->setVisible(false);
    ui->frJoystick->setVisible(true);
}

void MainWindow::on_actionArmband_triggered()
{
    ui->actionArmband->setEnabled(false);
    ui->actionJoystick->setEnabled(true);
    ui->actionSprache->setEnabled(true);

    ui->frSprache->setVisible(false);
    ui->frArmband->setVisible(true);
    ui->frJoystick->setVisible(false);
}

void MainWindow::on_actionSprache_triggered()
{
    ui->actionArmband->setEnabled(true);
    ui->actionJoystick->setEnabled(true);
    ui->actionSprache->setEnabled(false);

    ui->frArmband->setVisible(false);
    ui->frSprache->setVisible(true);
    ui->frJoystick->setVisible(false);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(!event->isAutoRepeat())
    {
        switch (event->key()) {
        case Qt::Key_W:
            ui->lbButtonOut->setText("Forward");
            cvDrone->moveForward();
            return;
        case Qt::Key_A:
            ui->lbButtonOut->setText("Left");
            cvDrone->moveLeft();
            return;
        case Qt::Key_S:
            ui->lbButtonOut->setText("Backward");
            cvDrone->moveBackward();
            return;
        case Qt::Key_D:
            ui->lbButtonOut->setText("Right");
            cvDrone->moveRight();
            return;
        case Qt::Key_Up:
            ui->lbButtonOut->setText("Up");
            cvDrone->moveUp();
            return;
        case Qt::Key_Down:
            ui->lbButtonOut->setText("Down");
            cvDrone->moveDown();
            return;
        case Qt::Key_Left:
            ui->lbButtonOut->setText("AX L");
            cvDrone->turnLeft();
            return;
        case Qt::Key_Right:
            ui->lbButtonOut->setText("AX R");
            cvDrone->turnRight();
            return;
        case Qt::Key_Escape:
            ui->lbButtonOut->setText("Emergency");
            cvDrone->emergency();
            return;
        }
        QWidget::keyPressEvent(event);
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if( !event->isAutoRepeat() && (event->key() != Qt::Key_Escape) )
    {
        ui->lbButtonOut->setText("");
        cvDrone->hover();
        return;
    }
    QWidget::keyReleaseEvent(event);
}
