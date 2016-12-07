import QtQuick 2.0

Item {
    Rectangle {
        id: r_Background
        color: "#3401e8"
        anchors.fill: parent

        Text {
            id: t_Titel
            width: 300
            height: 300
            color: "#fee5e5"
            text: qsTr("Armband")
            anchors.horizontalCenter: parent.horizontalCenter
            wrapMode: Text.WrapAnywhere
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            anchors.verticalCenter: parent.verticalCenter
            font.pixelSize: 48
        }
    }

}
