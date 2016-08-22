import QtQuick 1.0

Rectangle {
    width: 360
    height: 360
    Text {
        text: qsTr("Hello World")
        anchors.centerIn: parent
    }
    MouseArea {
        x: 0
        y: 0
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        anchors.fill: parent
        onClicked: {
            Qt.quit();
        }

        TextEdit {
            id: text_edit1
            x: 122
            y: 226
            width: 127
            height: 35
            text: qsTr("text edit")
            font.pixelSize: 12
        }
    }
}
