import QtQuick 2.15
import "../component"
import "../listLibraries"
Column{

    anchors.left: parent.left

    //tab ALbum
    QRectText{
        height: 1/4*parent.height
        width: parent.width
        colorText: "#FF99FF"
        fontText: 25
        qText: qsTr("Album")
        focus : play.TabLibraries === 0? true:false
        onClicked: {
            focus= true
            play.setTabLibraries(0);
            tabLabraries.sourceComponent = albumTitle
            menu.sourceComponent = null
        }
    }

    //tab Artist
    QRectText{
        height: 1/4*parent.height
        width: parent.width
        fontText: 25
        colorText: "#FF99FF"
        qText: qsTr("Artist")
        focus : play.TabLibraries === 1? true:false
        onClicked: {
            focus = true
            play.setTabLibraries(1);
            tabLabraries.sourceComponent = albumArtist
            menu.sourceComponent = null
        }
    }
    //tab Songs
    QRectText{
        height: 1/4*parent.height
        width: parent.width
        fontText: 25
        focus : play.TabLibraries === 2? true:false
        colorText: "#FF99FF"
        qText: qsTr("Songs")
        onClicked: {
            focus = true
            play.setTabLibraries(2);
            tabLabraries.sourceComponent = albumSong
            menu.sourceComponent = null
        }
    }
    //tab Favorites
    QRectText{
        height: 1/4*parent.height
        width: parent.width
        fontText: 25
        colorText: "#FF99FF"
        qText: qsTr("Favorites")
        focus : play.TabLibraries === 3? true:false
        onClicked: {
            focus= true
            play.setTabLibraries(3);
            tabLabraries.sourceComponent = favorites
            menu.sourceComponent = null
        }
    }
}
