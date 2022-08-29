import QtQuick 2.15
import "../component"




QRectText{
    height: 150
    width: 150
    anchors{
        left: parent.right
        leftMargin: -50
        top: parent.top
        topMargin: 100
    }
    colorText: "white"
    qText: "Media version 1.0
            "
    QRectText{
        height: 30
        width: 20
        anchors.right: parent.right
        colorText: "red"
        fontText: 10
        qText: "Close"
        onClicked: {
            loaderAbout.sourceComponent = null

        }
    }
}

