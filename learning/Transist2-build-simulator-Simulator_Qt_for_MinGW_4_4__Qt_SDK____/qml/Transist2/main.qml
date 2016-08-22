import QtQuick 1.0

Rectangle {
    width: 360
    height: 360
    color: "#382b2b"
    border.color: "#000000"
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

        Rectangle {
            id: rectangle1
            x: 26
            y: 27
            width: 78
            height: 80
            color: "#ffffff"
        }

        GridView {
            id: grid_view1
            x: 89
            y: 143
            width: 140
            height: 140
            cellHeight: 70
            cellWidth: 70
            delegate: Item {
                x: 5
                height: 50
                Column {
                    spacing: 5
                    Rectangle {
                        width: 40
                        height: 40
                        color: transparent
                        anchors.horizontalCenter: parent.horizontalCenter
                    }

                    Text {
                        x: 5
                        text: name
                        anchors.horizontalCenter: parent.horizontalCenter
                        font.bold: true
                    }
                }
            }
            model: ListModel {
                ListElement {
                    name: "Grey"
                    colorCode: "grey"
                }

                ListElement {
                    name: "Red"
                    colorCode: "red"
                }

                ListElement {
                    name: "Blue"
                    colorCode: "blue"
                }

                ListElement {
                    name: "Green"
                    colorCode: "green"
                }
            }
        }

        TextEdit {
            id: text_edit1
            x: 140
            y: 157
            text: qsTr("text edit")
            z: 1
            font.pixelSize: 12
        }



        MouseArea {
            id: mouse_area1
            x: 254
            y: 34
            width: 100
            height: 100
        }

        Image {
            id: image1
            x: 127
            y: 27
            source: "Transist280.png"
        }
    }
}
