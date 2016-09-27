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
                onTriggered: console.log("Connect action triggered")
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
    }

    Rectangle {
        id: r_Titel
        height: 80
        color: "#4cd10000"
        radius: 4
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

    RowLayout {
        id: rl_Video
        y: 182
        height: 300
        anchors.right: parent.right
        anchors.rightMargin: 100
        anchors.left: parent.left
        anchors.leftMargin: 100
        anchors.top: r_Titel.bottom
        anchors.topMargin: 20

        Rectangle {
            id: r_Video1
            width: 440
            height: 200
            color: "#80ffffff"
            opacity: 1
            border.width: 8
            Layout.fillHeight: true
            Layout.fillWidth: true

            Text {
                id: t_Video1
                text: qsTr("Cam 1")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                anchors.fill: parent
                font.pixelSize: 50
            }
        }

        Rectangle {
            id: r_Video2
            width: 440
            height: 200
            color: "#80ffffff"
            Layout.fillWidth: true
            border.width: 8
            Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
            Layout.fillHeight: true

            Text {
                id: t_Video2
                text: qsTr("Cam 2")
                horizontalAlignment: Text.AlignHCenter
                anchors.fill: parent
                font.pixelSize: 50
                verticalAlignment: Text.AlignVCenter
            }
        }
    }

    Rectangle {
        id: r_State
        height: 250
        color: "#80c00404"
        anchors.rightMargin: 100
        anchors.leftMargin: 100
        anchors.top: rl_Video.bottom
        anchors.right: parent.right
        anchors.left: parent.left
        anchors.topMargin: 20
        border.width: 6
    }

}
