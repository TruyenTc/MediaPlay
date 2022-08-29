import QtQuick 2.15
import"../component"
Rectangle{
    id: rectVolume
    width: 100
    height: 10
    color: "white"
    radius: 10
    Rectangle{
        height: rectVolume.height
        width: play.Volume+5
        color: "grey"
        radius: 10
    }
    MouseArea{
        anchors.fill: parent
        // click changed x
        onClicked: {
            var x =mouseX;
            console.log(x);
            if(x > mouse1.drag.maximumX){
                x = mouse1.drag.maximumX
            }
            play.Volume = x
        }
    }
    QImage{
        id: idvolume
        sourceImage: play.Volume!==0?"qrc:/image/outline_volume_up_white_24dp.png": "qrc:/image/outline_volume_off_white_24dp.png"
        anchors{
            bottom: parent.bottom
            bottomMargin:  -20
            left:  parent.left
            leftMargin: -60
        }
        // volume off or volume 40
        onClicked: {
            idvolume.focus = !idvolume.focus
            play.Volume = !idvolume.focus? 40:0;
        }
    }

    Rectangle{
        id: id_Volume
        width: 20
        height: 20
        color: "grey"
        anchors.verticalCenter: parent.verticalCenter
        radius: 10
        Drag.active:mouse1.drag.active
        x: play.Volume //change x
        // x change to volume
        onXChanged: {
            if(mouse1.drag.active){
                play.Volume = x  ;// volume of music change to x
            }
        }
        // biding again x
        states: State {
            when: mouse1.drag.active
            PropertyChanges{
                target: id_Volume
                x: mouse1.x
            }
        }
        // drag change x
        MouseArea{
            id:mouse1
            anchors.fill: parent
            drag.target: id_Volume
            drag.axis: Drag.XAxis
            drag.minimumX : 0  //min of x
            drag.maximumX: rectVolume.width-id_Volume.width  //max of x

        }
    }
}

