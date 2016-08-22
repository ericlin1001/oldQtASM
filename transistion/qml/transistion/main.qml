import QtQuick 1.0

Rectangle {
    id: page
    width: 360
    height: 360
    color: "#343434"

    Rectangle {
        id: topLeftRect
        x: 20
        y: 40
        width: 64
        height: 64
        color: "#343434"
        radius: 6
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.top: parent.top
        anchors.topMargin: 20
        border.color: "#808080"

        MouseArea {
            id: mousearea1
            anchors.fill: parent
            onClicked: page.state = ''

        }
    }

    Image {
        id: icon
        x: 10
        y: 20
        fillMode: Image.Tile
        source: "states.png"
    }

    Rectangle {
        id: middleRightRect
        x: 273
        y: 119
        width: 64
        height: 64
        color: "#343434"
        radius: 6
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.verticalCenter: parent.verticalCenter
        border.color: "#808080"
        MouseArea {
            id: mousearea2
            anchors.fill: parent
            onClicked: page.state = 'State1'
        }
    }

    Rectangle {
        id: bottomLeftRect
        y: 256
        width: 64
        height: 64
        color: "#343434"
        radius: 6
        anchors.right: parent.right
        anchors.rightMargin: 286
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 20
        border.color: "#808080"
        MouseArea {
            id: mousearea3
            anchors.fill: parent
            onClicked: page.state = 'State2'
        }
    }

    states: [
        State {
            name: "State1"

            PropertyChanges {
                target: icon
                x: middleRightRect.x
                y: middleRightRect.y
                z: 1
            }
        },
        State {
            name: "State2"
            PropertyChanges {
                target: icon
                x: bottomLeftRect.x
                y: bottomLeftRect.y
                z: 1
            }
        }
        /*
           }*/
    ]

    transitions: [
        Transition {
              from: "*"; to: "State1"
             NumberAnimation {
                properties: "x,y";
                duration: 1000
            }
        },
        Transition {
                 from: "*"; to: "State2"
                 NumberAnimation {
                     properties: "x,y";
                     easing.type: Easing.InOutElastic
                     duration: 2000
                 }
             },
        Transition {
                NumberAnimation {
easing.type: Easing.InOutCirc
                    properties: "x,y";
                    duration: 500
                }
            }
    ]



}

