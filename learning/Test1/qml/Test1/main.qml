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
        width: 130
        height: 90
        anchors.rightMargin: 225
        anchors.bottomMargin: 259
        anchors.leftMargin: 0
        anchors.topMargin: 0
        anchors.fill: parent
        onClicked: {
            Qt.quit();
        }
    }
}
