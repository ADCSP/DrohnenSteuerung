import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Window 2.2
import QtQuick.Layouts 1.3
import QtQuick.Extras 1.4

ApplicationWindow {
    id: applicationWindow1
    visible: true
    width: Screen.width
    height: Screen.height
    color: "#085b04"
    title: qsTr("Dronen Steuerungs System")

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
            hoverEnabled: false
        }
    }

    RowLayout {
        id: rl_Video
        y: 182
        width: 1000
        height: 300
        anchors.left: parent.left
        anchors.leftMargin: 99
        anchors.horizontalCenter: r_Titel.horizontalCenter
        anchors.top: r_Titel.verticalCenter
        anchors.topMargin: 50

        Rectangle {
            id: r_Video1
            width: 440
            height: 200
            color: "#80ffffff"
            opacity: 1
            border.width: 8
            Layout.fillHeight: true
            Layout.fillWidth: true
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
        }
    }

    Rectangle {
        id: r_State
        x: 0
        width: 600
        height: 250
        color: "#80c00404"
        anchors.right: parent.right
        anchors.rightMargin: 100
        anchors.top: rl_Video.bottom
        anchors.topMargin: 20
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.left: parent.left
        anchors.leftMargin: 50
        border.width: 6
    }

}
