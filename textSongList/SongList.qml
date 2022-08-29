import QtQuick 2.15
import QtMultimedia
import "../component"
Rectangle{
    id: idList
    anchors{
        bottom: parent.bottom
    }
    width: rectView.width
    height: 4/6*rectView.height
    color: "#CCFFCC"
    clip: true
    ListView {
        id: id_PlayList
        anchors.fill: parent
        model: playlist
        spacing: 2
        delegate:
            Row{
            Rectangle{
                id: id_rect
                width: 3/4* id_PlayList.width
                height: 30
                color: id_Mouse.hovered? "white" : "transparent"
                Text {
                    id: txt
                    anchors{
                        fill: id_rect
                        left: parent.left
                        leftMargin: 5
                    }
                    elide: Text.ElideRight
                    font.pixelSize: 16
                    text: idMPlayer.metaData.stringValue(MediaMetaData.Title)
                    color: (playlist.Index === index)?"#770000" : "black"
                }

                MediaPlayer{
                    id: idMPlayer
                    source: SongSource
                }

                MouseArea{
                    id: id_mouse
                    anchors.fill: parent
                    //play a song of list
                    onClicked: {
                        playlist.Index = index;
                        play.play(!play.States);
                    }
                    HoverHandler {
                        id: id_Mouse
                        acceptedDevices: PointerDevice.Mouse
                        cursorShape: Qt.OpenHandCursor
                    }
                }
            }
            Rectangle{
                width: 1/4* id_rect.width
                height: 30
                color: "transparent"
                Image {
                    id: imageList
                    anchors.centerIn: parent
                    scale: 0.3
                    source: Favorites ? "qrc:/image/icons8-heart-50.png":"qrc:/image/icons8-heart-64.png"
                    //them bai yeu thich
                    MouseArea{
                        anchors.fill: parent
                        onClicked: {
                            playlist.loveFavorites(index);
                        }
                    }
                }
            }
        }
    }
}
