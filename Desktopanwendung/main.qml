import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Window 2.2
import QtQuick.Layouts 1.3
import QtQuick.Extras 1.4

ApplicationWindow {
    id: applicationWindow1
    visible: true
    width: Screen.width *.75
    height: Screen.height * .75
    color: "#085b04"
    title: qsTr("Drohnen Steuerungs System")

    menuBar: MenuBar {
        Menu {
            title: qsTr("File")
            /*MenuItem {
                text: qsTr("&Open")
                onTriggered: console.log("Open action triggered");
            }*/
            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
        }
        Menu {
            title: qsTr("Edit")
            MenuItem {
                text: qsTr("&Telemetry")
                onTriggered: console.log("Telemetry action triggered")
            }
            MenuItem {
                text: qsTr("&Connect")
                onTriggered: {

                    console.log("Connect action triggered")
                }
            }
            /*MenuItem {
                text: r_Video1.visible? qsTr("Hide Cam 1"): qsTr("Show Cam 1")
                onTriggered: {
                    r_Video1.visible = !r_Video1.visible
                    console.log("Cam 1 action triggered")
                }
            }*/
            MenuItem {
                text: r_Video2.visible? qsTr("Hide Cam 2"): qsTr("Show Cam 2")
                onTriggered: {
                    r_Video2.visible = !r_Video2.visible
                    console.log("Cam 2 action triggered")
                }
            }
        }
        Menu {
            title: qsTr("Modus")
             MenuItem {
                 text: qsTr("&Armband")
                 enabled:  q_armband.visible?false:true;
                 onTriggered: {
                     q_armband.visible = true;
                     q_sprache.visible =false;
                     q_joystick.visible = false;


                 }
             }
             MenuItem {
                 text: qsTr("&Sprachsteuerung")
                  enabled:  q_sprache.visible?false:true;
                 onTriggered: {
                     q_armband.visible = false;
                     q_sprache.visible = true;
                     q_joystick.visible = false;
                 }
             }
             MenuItem {
                 text: qsTr("&Joystick")
                 enabled:  q_joystick.visible?false:true;
                 onTriggered: {
                     q_armband.visible = false;
                     q_sprache.visible =false;
                     q_joystick.visible = true;
                 }
             }
        }
    }

    Rectangle {
        id: r_Titel
        height: 80
        color: "#4cd10000"
        radius: 15
        anchors.right: parent.right
        anchors.rightMargin: 300
        anchors.left: parent.left
        anchors.leftMargin: 300
        anchors.top: parent.top
        anchors.topMargin: 20
        border.color: "#fa0505"
        border.width: 10
        opacity: 1

        Text {
            id: t_Text
            color: "#ffffff"
            text: qsTr("DroneControl")
            anchors.fill: parent
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 48
        }

        MouseArea {
            id: ma_TitelButton
            anchors.fill: parent
            hoverEnabled: false
            onClicked: Qt.quit()
        }
    }

    Rectangle {
        id: r_State
        color: "#80c00404"
        radius: 15
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 50
        anchors.top: r_Titel.bottom
        anchors.topMargin: 20
        anchors.right: parent.right
        anchors.rightMargin: 50
        anchors.left: sv_Video.right
        anchors.leftMargin: 20
        border.width: 10

        Armband {
            id: q_armband
            anchors.fill: parent
        }

        Joystick {
            id: q_joystick
            visible: false
            anchors.fill: parent
        }

        Sprachsteuerung {
            id: q_sprache
            anchors.fill: parent
            visible: false
        }
    }

    SplitView {
        id: sv_Video
        width: 404
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 50
        anchors.left: parent.left
        anchors.leftMargin: 50
        anchors.top: r_Titel.bottom
        anchors.topMargin: 20
        orientation: Qt.Vertical

        Rectangle {
            id: r_Video1
            width: 400
            height: 200
            radius: 1
            gradient: Gradient {
                GradientStop {
                    position: 0
                    color: "#f61313"
                }

                GradientStop {
                    position: 1
                    color: "#000000"
                }
            }
            anchors.top: parent.top
            anchors.topMargin: 0
            opacity: 1
            border.width: 10
            Layout.fillHeight: true
            Layout.fillWidth: true

            Text {
                id: t_Video1
                text: qsTr("Cam 1")
                anchors.fill: parent
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.pixelSize: 50
            }
        }

        Rectangle {
            id: r_Video2
            width: 400
            height: 200
            radius: 1
            gradient: Gradient {
                GradientStop {
                    position: 0
                    color: "#f61313"
                }

                GradientStop {
                    position: 1
                    color: "#000000"
                }
            }
            anchors.top: r_Video1.bottom
            anchors.topMargin: 0
            Layout.fillWidth: true
            border.width: 10
            Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
            Layout.fillHeight: true

            Text {
                id: t_Video2
                text: qsTr("Cam 2")
                anchors.fill: parent
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 50
                verticalAlignment: Text.AlignVCenter
            }
        }
    }

}
