import QtQuick 1.0

Rectangle {
    id: rectangle1
    width: 80
    height: 30
    radius: 6
    border.width: 2
    border.color: "#bb0891"
    gradient: Gradient {
        GradientStop {
            position: 0
            color: "#23e4b4"
        }

        GradientStop {
            position: 1
            color: "#000000"
        }
    }

    Text {
        id: text1
        text: qsTr("MyButton")
        font.bold: false
        style: Text.Normal
        anchors.fill: parent
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 16
    }
}
