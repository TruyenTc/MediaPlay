import QtQuick 2.15


// text ListMusic
Rectangle {
    id: rectText
    anchors.horizontalCenter: rectView.horizontalCenter
    height: 1/8*rectView.height
    width: rectView.width-(rectView.border.width*2)
    anchors{
        top: rectView.top
        topMargin: 10/48*rectView.height
    }

    color: "grey"
    Text {
        id: idText
        anchors.centerIn: parent
        color: "black"
        text: qsTr("List Music")
        font.pixelSize: 22
    }
}
