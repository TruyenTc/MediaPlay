import QtQuick 2.15
import QtMultimedia


Rectangle{
    id: idList
    height: viewLabraries.height
    width: viewLabraries.width
    signal clicked();
    color: "grey"
    clip: true
    ListView {
        id: id_PlayList
        anchors.fill: parent
        model: /*playlist*/playlist.FavoritesSong
        delegate:
            Column{
            spacing: 2
            Rectangle{
                id: id_rect
                width: id_PlayList.width
                height: 40
                color: id_Mouse.hovered? "white" : "transparent"
                Text {
                    id: txt
                    anchors{
                        fill: id_rect
                        left: parent.left
                        leftMargin: 5
                    }
                    font.pixelSize: 20
                    text: /*playlist.FavoritesSong.at(index)*/modelData
                    color: (playlist.IndexFavorite === index)?"#770000" : "black"
                }

                MouseArea{
                    id: id_mouse
                    anchors.fill: id_rect
                    onClicked: {
                        playlist.IndexFavorite = index ;
                        play.play(!play.States);
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
