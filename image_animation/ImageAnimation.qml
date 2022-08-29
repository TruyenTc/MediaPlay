import QtQuick 2.15

Image {
    id: id_playMusic
    scale: 0.5
    source: "qrc:/image/icons8-audio-file-64.png"
    anchors{
        horizontalCenter: parent.horizontalCenter
        top: parent.top
        topMargin: 1/8*parent.height
    }
    NumberAnimation{
        id:idAnimation
        target: id_playMusic
        property: "rotation"
        duration: 5000
        from: 0
        to:360
        loops: Animation.Infinite
        running: play.States
    }

}
