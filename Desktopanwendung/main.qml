import QtQuick 2.5
import QtQuick.Controls 1.4

ApplicationWindow {
    id: applicationWindow1
    visible: true
    width: 1000
    height: 750
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
        text: qsTr("Drohnen Steuerungs System")
        font.pointSize: 30
        anchors.top: parent.top
        anchors.topMargin: 10
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.horizontalCenterOffset: 0
    }

    Rectangle {
        id: videofeed_placeholder
        width: 600
        height: 400
        color: "#686a78"
        anchors.top: parent.top
        anchors.topMargin: 60
        anchors.horizontalCenter: parent.horizontalCenter
    }
}
