import QtQuick 2.15

Rectangle{
    id: rectSlider
    height: 10
    color: "white"
    radius: 10
    MouseArea{
        anchors.fill: parent
        onClicked: {
            var x =mouseX;
            if(x > rectSlider.width - id_Slider.width){
                x = rectSlider.width - id_Slider.width
            }
            play.takeX(x, ( rectSlider.width-20));
        }
    }
    Rectangle{
        height: rectSlider.height
        width: (play.position/play.duration*( rectSlider.width-20))+5
        color: "grey"
        radius: 10
    }
    Rectangle{
        id: id_Slider
        width: 20
        height: 20
        color: "grey"
        anchors.verticalCenter: parent.verticalCenter
        radius: 10
        Drag.active:mouse.drag.active
        x:  (play.position/play.duration*( rectSlider.width-20));//change x
        Text {
            id: positionTime
            anchors{
                bottom: id_Slider.top
                left: id_Slider.left
                leftMargin: -20
            }
            text: play.positionString + "/" + play.durationString
            color: "black"
        }
        onXChanged: {
            if(mouse.drag.active){
                play.takeX(x, ( rectSlider.width-20));
            }
        }


        //  biding again x
        states: State {
            when: mouse.drag.active
            PropertyChanges{
                target: id_Slider
                x: mouse.x
            }
        }
        //drag change x
        MouseArea{
            id:mouse
            anchors.fill: parent
            drag.target: id_Slider
            drag.axis: Drag.XAxis
            drag.minimumX : 0
            drag.maximumX: rectSlider.width - id_Slider.width

        }
    }

}
