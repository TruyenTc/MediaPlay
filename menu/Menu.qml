import QtQuick 2.15
import "../component"
import "../language"

Column{    
    QRectText{
        height: 20
        width: 100
        //colorRect: "#222222"
        colorText: "white"
        qText: qsTr("Open File")
        onClicked: {
            menu.sourceComponent = null
            folder.acction(false);
        }
    }
    QRectText{
        height: 20
        width: 100
        colorText: "white"
        qText: qsTr("Open Folder")
        onClicked: {
            menu.sourceComponent = null
            folder.acction(true);
        }
    }

    Language{

    }

    QRectText{
        height: 20
        width: 100
        colorText: "white"
        qText: qsTr("About")
        onClicked: {
            loaderAbout.sourceComponent = !loaderAbout.sourceComponent? about:null
        }
    }
}


