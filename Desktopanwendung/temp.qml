import QtQuick.Controls 2.5
import QtQuick.Window 2.2
import QtQuick.Layouts 1.3
import QtQuick.Extras 1.4

Rectangle {
    id: rectangle2
    radius: 0
    opacity: 1
    property alias r_Titel: r_Titel
    property alias t_Text: t_Text
    width: 1080
    height: 1920
    gradient: Gradient {
        GradientStop {
            position: 0.034
            color: "#001601"
        }

        GradientStop {
            position: 0.401
            color: "#015005"
        }

        GradientStop {
            position: 0.888
            color: "#1fdc08"
        }

    }
    border.color: "#270101"

    Rectangle {
        id: r_Titel
        height: 113
        color: "#4cd10000"
        radius: 30
        anchors.right: parent.right
        anchors.rightMargin: 300
        anchors.left: parent.left
        anchors.leftMargin: 300
        anchors.top: parent.top
        anchors.topMargin: 100
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
        height: 450
        anchors.top: parent.top
        anchors.topMargin: 250
        anchors.left: parent.left
        anchors.leftMargin: 75
        anchors.right: parent.right
        anchors.rightMargin: 75

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
        id: r_WLan
        x: 114
        width: 311
        height: 200
        color: "#00000000"
        radius: 30
        border.width: 10
        anchors.bottom: r_State.top
        anchors.bottomMargin: 50
        anchors.top: rl_Video.bottom
        anchors.topMargin: 50

        Text {
            id: t_WLanButton
            color: "#f0efef"
            text: qsTr("WLAN Connect")
            anchors.leftMargin: 15
            anchors.fill: parent
            z: 1
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignLeft
            font.pixelSize: 42
        }
    }

    Rectangle {
        id: r_State
        y: 942
        height: 750
        color: "#80c00404"
        border.width: 6
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.right: parent.right
        anchors.rightMargin: 75
        anchors.left: parent.left
        anchors.leftMargin: 75
    }


    RowLayout {
        id: rl_Radiobuttons
        anchors.right: parent.right
        anchors.rightMargin: 150
        anchors.left: parent.left
        anchors.leftMargin: 150
        activeFocusOnTab: false
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 150
        anchors.top: r_State.bottom
        anchors.topMargin: 25

        RadioButton {
            id: rb_Joystick
            text: "Joystick"
            bottomPadding: 0
            rightPadding: 0
            topPadding: 0
            checked: false
            spacing: 10
            leftPadding: 100
            scale: 1.6
            transformOrigin: Item.Center
            Layout.fillWidth: true
            Layout.fillHeight: true
        }

        RadioButton {
            id: rb_Armband
            text: qsTr("Armband")
            bottomPadding: 0
            rightPadding: 0
            topPadding: 0
            autoExclusive: true
            checked: true
            spacing: 10
            leftPadding: 100
            scale: 1.5
            Layout.fillWidth: true
            Layout.fillHeight: true
        }

        RadioButton {
            id: rb_Speech
            text: qsTr("Spracherkennung")
            bottomPadding: 0
            Layout.rowSpan: 1
            leftPadding: 100
            rightPadding: 0
            z: 0
            rotation: 0
            scale: 1.5
            topPadding: 0
            spacing: 10
            checked: false
            Layout.fillWidth: true
            Layout.fillHeight: true
        }
    }


}
