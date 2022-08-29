import QtQuick 2.15

Rectangle{
    id: qRect
    property string colorRect
    property bool focusRect
    property string sourceImage
    signal clicked();
    color: colorRect
    Image {
        anchors.centerIn: parent
        signal clicked();
        source: sourceImage
        scale: mouseImage.containsMouse? 1:0.8
        MouseArea{
            id: mouseImage
            anchors.fill: parent
            hoverEnabled: true
            onClicked: {
                qRect.clicked();
            }
        }
    }

}
