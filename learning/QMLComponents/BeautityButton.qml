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
    property string text: "button"
     property int fontSize: 44
     signal clicked
     BorderImage {
         id: border_image1
         x: -59
         y: -40
         width: 150
         height: 60
         visible: !mouse_area1.pressed
         source: "qrc:/qtquickplugin/images/template_image.png"

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
         scale: if (!mousearea1.pressed) { 1 } else { 0.95 }
         font.pixelSize: 0
         smooth: true
         style: Text.Outline
     }

     MouseArea {
         id: mouse_area1
         x: -59
         y: -40
         width: 150
         height: 60
         z: 1
          onClicked: parent.clicked()
     }

     BorderImage {
         id: border_image2
         x: -59
         y: -40
         width: 150
         height: 60
         visible: mouse_area1.pressed
         source: "qrc:/qtquickplugin/images/template_image.png"

         Image {
             id: image2
             anchors.fill: parent
             source: "button_down.png"
         }
     }
 }
