import QtQuick 1.0

Rectangle {
    id: mainpage
    width: 600
    height: 360
    color: "#382b2b"
    scale: 1
    rotation: 0
    border.color: "#000000"

    Rectangle {
        id: rectangle1
        x: 64
        width: 200
        color: "#ffffff"
        scale: 1.100
        rotation: 10
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 118
        anchors.top: parent.top
        anchors.topMargin: 54
    }
    MyButton {
        width: 100
        height: 100
        z: 1

    }
    BeautityButton {
        x: 370
        y: 168
        text: "ass"
        fontSize: 49
        onTre:mainpage.state="State1"
    }
    BeautityButton {
        x: 370
        y: 168
        text: "ass"
        fontSize: 49
        onTre:mainpage.state="State1"
    }

    Rectangle {
        id: rectangle2
        x: 137
        y: 0
        width: 200
        height: 200
        color: "#ffffff"
        opacity: 0
    }

    Rectangle {
        id: rectangle3
        x: 11
        y: 11
        width: 200
        height: 200
        color: "#ffffff"
        opacity: 0
    }

    Text {
        id: text1
        x: 227
        y: 217
        text: qsTr("text")
        font.pixelSize: 12
        opacity: 0
    }

    TextEdit {
        id: text_edit1
        x: 137
        y: 291
        width: 80
        height: 20
        text: qsTr("Hell world")
        font.pixelSize: 12
        opacity: 1
    }

    TextInput {
        id: text_input1
        x: 235
        y: 256
        width: 80
        height: 20
        text: qsTr("text")
        font.pixelSize: 12
        opacity: 0
    }

    Rectangle {
        id: rectangle5
        x: 267
        y: 318
        width: 76
        height: 29
        gradient: Gradient {
            GradientStop {
                position: 0
                color: "#3e9cca"
            }

            GradientStop {
                position: 1
                color: "#000000"
            }
        }

        MouseArea {
            id: mouse_area1
            x: 0
            y: 0
            width: 76
            height: 29
            onClicked:mainpage.state="State1"
        }
    }
    states: [
        State {
            name: "State1"

            PropertyChanges {
                target: rectangle1
                x: 145
                y: 181
                width: 106
                height: 110
            }

            PropertyChanges {
                target: rectangle2
                x: 263
                y: 58
                width: 85
                height: 138
                opacity: 1
            }

            PropertyChanges {
                target: mouse_area1
                onClicked:mainpage.state="State2"
            }

            PropertyChanges {
                target: mainpage
                width: 500
                height: 500
            }
        },
        State {
            name: "State2"
            PropertyChanges {
                target: rectangle1
                x: 92
                y: 178
                width: 106
                height: 110
            }

            PropertyChanges {
                target: rectangle2
                x: 264
                y: 29
                width: 85
                height: 138
                opacity: 1
            }

            PropertyChanges {
                target: rectangle3
                x: rectangle1.x
                y: 23
                width: 89
                height: 134
                opacity: 1
            }

            PropertyChanges {
                target: text1
                x: 241
                y: 185
                width: 108
                height: 71
                text: "text"
                opacity: 1
            }

            PropertyChanges {
                target: text_edit1
                x: 10
                y: 225
                width: 105
                height: 86
                text: "cxvatext editsadfqweaasdf"
                opacity: 1
            }

            PropertyChanges {
                target: text_input1
                width: 100
                height: 55
                text: "text"
                opacity: 1
            }
            PropertyChanges {
                target: mouse_area1
                onClicked:mainpage.state=""
            }
        }

    ]

}
