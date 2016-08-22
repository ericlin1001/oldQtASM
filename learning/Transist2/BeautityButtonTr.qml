import QtQuick 1.0

/*Rectangle {
    width: 100
    height: 62

    Item {
        id: item1
        x: 0
        y: 0
        width: 100
        height: 62
    }
}*/
Item {
    id: item1
    property string text: "button"
     property int fontSize: 44
     signal tre
     BorderImage {
         id: border_image1
         x: -59
         y: -40
         width: 150
         height: 60
         anchors.horizontalCenter: parent.horizontalCenter
         anchors.verticalCenter: parent.verticalCenter
         visible: !mouse_area1.pressed


         Image {
             id: image1
anchors.fill: parent
             source: "button_up.png"
         }
     }

     Text {
         id: text1
         x: -50
         y: -32
         color: "#af4242"
         text: parent.text
         z: 2
         anchors.horizontalCenter: parent.horizontalCenter
         anchors.verticalCenter: parent.verticalCenter
         scale: if (!mouse_area1.pressed) { 1 } else { 0.95 }
         font.pixelSize: parent.fontSize
         smooth: true
         style: Text.Outline
     }

     MouseArea {
         id: mouse_area1
         x: -59
         y: -40
         width: 150
         height: 60
         anchors.horizontalCenter: parent.horizontalCenter
         anchors.verticalCenter: parent.verticalCenter
         z: -1
          onClicked: parent.tre()
     }

     BorderImage {
         id: border_image2
         x: -59
         y: -40
         width: 150
         height: 60
         anchors.horizontalCenter: parent.horizontalCenter
         anchors.verticalCenter: parent.verticalCenter
         visible: mouse_area1.pressed


         Image {
             id: image2
             anchors.fill: parent
             source: "button_down.png"
         }
     }
 }
