import QtQuick 2.15
import "../component"


QRectImage{
    width: 50
    height: 50
    focusRect: false
    colorRect: focusRect? "grey":"transparent"
    sourceImage: "qrc:/image/outline_shuffle_white_24dp.png"
    // changed Shuffle
    onClicked:  {
        playlist.check(focusRect);
        focusRect = !focusRect;
    }
}
