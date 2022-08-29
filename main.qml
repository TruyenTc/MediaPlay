import QtQuick 2.15
import QtQuick.Window 2.15
import "./control"
import "./image_animation"
import "./slider"
import "./textSongList"
import "./language"
import "./switch"
import "./menu"
import "./tabLibraries"
import "./listLibraries"
import "./component"
Window {
    id: window1
    width: 840
    height: 480
    visible: true
    title: qsTr("Hello World")
    Loader{
        id: myloader
        sourceComponent: screenPlay
    }
    Loader{
        id: menu
        sourceComponent: null
    }

    Loader{
        id: loaderAbout
        sourceComponent: null
    }

    Component{
        id: componentMenuPlay
        MenuPlayBack{
        }
    }
    Component{
        id: componentMenuLibaries
        MenuLibraries{
        }
    }

    Component{
        id: about
        About{
           // anchors.centerIn: window1
        }
    }



    Component{
        id: screenPlay
        Item {
            width:window1.width
            height: window1.height
            Rectangle{
                id: rectControl
                width: 3/4* parent.width
                height: parent.height
                gradient: Gradient{
                    GradientStop{position: 0.0; color:"#0077b5"}
                    GradientStop{position: 0.5; color:"#55acee"}
                }
                //click man hinh menu se mat
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        menu.sourceComponent = null
                    }
                }

                PlayBack{
                }
                ImageAnimation{
                }
                Rectangle{
                    width: parent.width
                    height: 20
                    color: "#222222"
                    Menutext{
                        onClicked: {
                            menu.sourceComponent =  (menu.sourceComponent == null)? componentMenuPlay: null
                        }
                    }
                }
            }
            // sort name
            Rectangle{
                id:rectView
                width: 1/4*parent.width
                height: parent.height
                anchors.right: parent.right
                color: "#CCFFCC"
                clip: true
                QRectImage{
                    width: 30
                    height: 30
                    z:2
                    focusRect: false
                    sourceImage : "qrc:/image/icons8-sort-alpha-up-32.png"
                    colorRect: focusRect? "grey":"transparent"
                    onClicked: {
                        focusRect = !focusRect;
                        playlist.sortList(!focusRect);
                    }
                }
                TextSongList{
                }
                SongPlay{
                }
                SongList{
                }
            }
        }
    }
    Component{
        id: screenLibraries
        Item {
            width:window1.width
            height: window1.height

           //click man hinh menu se mat
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    menu.sourceComponent = null
                }
            }
            Rectangle{
                width: parent.width
                height: 20
                color: "#222222"
                Menutext{
                    onClicked: {
                        menu.sourceComponent = (menu.sourceComponent==null)? componentMenuLibaries: null
                    }
                }
            }
            Rectangle{
                id: idRectTab
                width: 1/5*parent.width
                height: parent.height-20
                anchors.bottom: parent.bottom
                TabLibraries{
                    anchors.fill: parent
                }
            }
            Rectangle{
                id: viewLabraries
                height: parent.height-20
                width: 4/5*parent.width
                anchors{
                        bottom: parent.bottom
                        right: parent.right
                }
                color: "grey"

                Loader{
                    id: tabLabraries
                     sourceComponent: TabLibraries ==0 ? albumTitle:( TabLibraries == 1? albumArtist:(TabLibraries==2? albumSong:favorites));
                }
                Component{
                    id: albumTitle
                        ListAlbum{

                        }
                }
                Component{
                    id: albumArtist
                        ListArtist{
                        }
                }
                Component{
                    id: albumSong
                        ListSong{
                          }
                }
                Component{
                    id: favorites
                        ListFavorites{
                          }
                }

            }
        }
    }

}
