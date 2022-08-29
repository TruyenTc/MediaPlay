import QtQuick 2.15
import QtMultimedia

import "../component"

List{

    height: viewLabraries.height
    width: viewLabraries.width
    modelList : playlist
    heightRect : 40
    textList :  MediaMetaData.AlbumTitle
    colorList : "grey"
    fontText : 20
    onClicked: {
        playlist.Index = index;
        play.play(!play.States);
    }

}
