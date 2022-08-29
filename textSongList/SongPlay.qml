import QtQuick 2.15


//text name a song play
Rectangle{
    id: idRectName
    width:rectView.width-(rectView.border.width*2)
    height:  10/48*rectView.height
    anchors{
        top: parent.top
        horizontalCenter: parent.horizontalCenter
    }
    color: "lightblue"
    clip:true
    onFocusChanged: { if (!focus) idNamePlay.x = parent.x  }
    Text {
        id: idNamePlay
        anchors.verticalCenter: idRectName.verticalCenter
        color: "#770000"
        text : play.name
        font.pixelSize: 18
        NumberAnimation{
            properties: "x"
            target: idNamePlay
            from: idRectName.x+30
            to: -50
            duration: 4000
            loops: Animation.Infinite
            running: true
        }
    }

}
