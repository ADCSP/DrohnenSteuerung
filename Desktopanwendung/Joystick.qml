import QtQuick 2.0

Item {
    Rectangle {
        id: r_Background
        color: "#d90bb7"
        anchors.fill: parent

        Text {
            id: text1
            text: qsTr("Joystick")
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 48

        }
    }

}
