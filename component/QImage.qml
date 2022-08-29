import QtQuick 2.15

Image {
 //   id: idImageBtn
    property string sourceImage
    property bool focusImage
    signal clicked();
    source: sourceImage
    scale: mouseImage.containsMouse? 1.2:1
    MouseArea{
        id: mouseImage
        anchors.fill: parent
        hoverEnabled: true
        onClicked: {
            parent.clicked();
        }
    }
}
