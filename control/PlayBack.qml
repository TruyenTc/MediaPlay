import QtQuick 2.15
import"../component"
import"../slider"
import"../switch"
Rectangle{
    id: idRect1
    width: parent.width
    height: 1/5*parent.height
    color: "#3366FF"
    anchors.bottom: parent.bottom
    // play or pause
    QImage{
        id: idPlay
        sourceImage: play.States? "qrc:/image/outline_pause_white_24dp.png": "qrc:/image/outline_play_arrow_white_24dp.png"
        anchors.centerIn: idRect1
        onClicked: {
            if(playlist.Index===-1 || playlist.Index===-2){
                playlist.Index =0;
            }
             play.play(!play.States);
        }

    }
    //next
    QImage{
        id: idNext
        sourceImage: "qrc:/image/outline_skip_next_white_24dp.png"
        anchors{
            bottom: idPlay.bottom
            left: idPlay.right
            leftMargin: 20
        }
        onClicked: {
            playlist.Index = playlist.Index +1;
            play.play(!play.States);
        }

    }
    //previous
    QImage{
        id: idPrevious
        sourceImage: "qrc:/image/outline_skip_previous_white_24dp.png"
        anchors{
            bottom: idPlay.bottom
            right: idPlay.left
            rightMargin: 20
        }
        onClicked: {
            playlist.Index = playlist.Index -1;
            play.play(!play.States);
        }

    }
    //slider time of music
    SliderTimeOfMusic{
        anchors{
            left: parent.left
            leftMargin: 20
            right: parent.right
            rightMargin: 20
            bottom: parent.top
            bottomMargin: 2/8*parent.height
        }
    }
    //slider volume
    SliderVolume{
        anchors{
            left:  idNext.right
            leftMargin: 1/8*parent.width
            verticalCenter: parent.verticalCenter
        }
    }
    //change Shuffle
    Shuffle{
        id: shuffle
        anchors{
            right:  idPrevious.left
            rightMargin: 1/16*idRect1.width-25
            verticalCenter: parent.verticalCenter
        }
    }
    //change Repeat
    SwitchRepeat{
        anchors{
            right: idPrevious.left
            rightMargin: 1/8*idRect1.width
            verticalCenter: parent.verticalCenter
        }
    }

}
