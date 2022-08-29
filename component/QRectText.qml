import QtQuick 2.15

Rectangle{
    id: qRect
    property string qText
    property string colorText
    property int fontText
    signal clicked();
    property string colorRect
    color: focus || idMouseArea.containsMouse ? "brown" : "#222222"
    Text {
        anchors.centerIn:  parent
        text: qText
        color: colorText
        font.pixelSize: fontText
         }
        MouseArea{
            id: idMouseArea
            anchors.fill: qRect
            hoverEnabled: true
            onClicked: {
                qRect.clicked();
            }
        }
}
