import QtQuick 2.15
import QtMultimedia

Rectangle{
    id: idList
    property string textList
    property string colorList
    property int fontText
    property int heightRect
    property var modelList
    signal clicked();
    color: colorList
    clip: true
    ListView {
        id: id_PlayList
        anchors.fill: parent
        model: /*playlist*/modelList
        delegate:
            Column{
            spacing: 2
            Rectangle{
                id: id_rect
                width: id_PlayList.width
                height: heightRect
                color: id_Mouse.hovered? "white" : "transparent"
                Text {
                    id: txt
                    anchors{
                        fill: id_rect
                        left: parent.left
                        leftMargin: 5
                    }
                    font.pixelSize: fontText
                    text: idMPlayer.metaData.stringValue(textList) /*MediaMetaData.Title*/
                    color: (playlist.Index === index)? "#770000" : "black"
                }

                MediaPlayer{
                    id: idMPlayer
                    source: SongSource
                }
                //    click on the song to play it
                MouseArea{
                    id: id_mouse
                    anchors.fill: id_rect
                    onClicked: {
                        playlist.Index = index;
                        idList.clicked();
                    }
                    HoverHandler {
                        id: id_Mouse
                        acceptedDevices: PointerDevice.Mouse
                        cursorShape: Qt.OpenHandCursor
                    }
                }
            }
        }
    }
}
