import QtQuick 2.15
import "../component"


QRectImage{
    width: 50
    height: 50
    focusRect: false
    colorRect: focusRect? "grey":"transparent"
    sourceImage: "qrc:/image/outline_repeat_white_24dp.png"
    //changed Repeat
    onClicked:  {
        focusRect = !focusRect;
        play.checkRepeat(!focusRect);
    }
}
