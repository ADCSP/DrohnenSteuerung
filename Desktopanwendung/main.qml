import QtQuick 2.5
import QtQuick.Controls 1.4

ApplicationWindow {
    id: applicationWindow1
    visible: true
    width: 640
    height: 480
    title: qsTr("Dronen Steuerungs System")

    menuBar: MenuBar {
        Menu {
            title: qsTr("File")
            MenuItem {
                text: qsTr("&Open")
                onTriggered: console.log("Open action triggered");
            }
            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
        }
        Menu {
            title: qsTr("Test")
            MenuItem {
                text: qsTr("&Testing")
                onTriggered: console.log("Test action triggered")
            }
        }
    }

    Label {
        text: qsTr("Dronen Steuerungs System")
        anchors.verticalCenterOffset: -208
        anchors.horizontalCenterOffset: 1
        anchors.centerIn: parent
    }

    Rectangle {
        id: b
        y: 250
        height: 200
        color: "#848484"
        radius: 15
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 50
        anchors.right: parent.right
        anchors.rightMargin: 50
        anchors.left: parent.left
        anchors.leftMargin: 50
        border.width: 5

        Text {
            id: b_text
            color: "#ffffff"
            text: qsTr("Quit")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            anchors.fill: parent
            font.pixelSize: 30
        }

        MouseArea {
            id: b_mouse_area
            anchors.fill: parent
            onClicked: {
                Qt.quit()
            }
        }
    }
}
