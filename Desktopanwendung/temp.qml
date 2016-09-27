import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.3

ApplicationWindow {
    id: mainwindow
    visible: true
    width: 1500
    height: 1000
    title: qsTr("Dronen Steuerungs System")

    menuBar: MenuBar {
        Menu {
            title: qsTr("File")
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
            MenuItem {
                text: videofeed_down_placeholder.visible? qsTr("Hide Cam 2"):qsTr("Show Cam 2")
                onTriggered: {
                    console.log("Feed action triggered");
                    videofeed_down_placeholder.visible = !videofeed_down_placeholder.visible
                }
            }
        }
    }

    Rectangle {
        id: r_Titel
        height: 113
        color: "#4cd10000"
        radius: 15
        anchors.right: parent.right
        anchors.rightMargin: 150
        anchors.left: parent.left
        anchors.leftMargin: 150
        anchors.top: parent.top
        anchors.topMargin: 25
        border.color: "#fa0505"
        border.width: 10
        opacity: 1

        Text {
            id: t_TitelText
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
        id: videofeed_layout
        height: 500
        anchors.top: r_Titel.bottom
        anchors.topMargin: 5
        anchors.right: parent.right
        anchors.rightMargin: 25
        anchors.left: parent.left
        anchors.leftMargin: 25

        Rectangle {
            id: videofeed_front_placeholder
            width: 200
            height: 200
            color: "#808080"
            radius: 15
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            border.width: 5

            Text {
                id: videofeed_front_text
                color: "#ffffff"
                text: qsTr("Front")
                anchors.fill: parent
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 50
            }
        }

        Rectangle {
            id: videofeed_down_placeholder
            width: 200
            height: 200
            color: "#808080"
            radius: 15
            visible: true
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            Layout.fillHeight: true
            Layout.fillWidth: true
            border.width: 5

            Text {
                id: videofeed_down_text
                color: "#ffffff"
                text: qsTr("Down")
                visible: true
                verticalAlignment: Text.AlignVCenter
                anchors.fill: parent
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 50
            }
        }
    }
}
