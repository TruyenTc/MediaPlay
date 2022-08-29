import QtQuick 2.15
import "../component"


Column{
    anchors.top: parent.top
    anchors.topMargin: 20
    QRectText{
        height: 20
        width: 100
        colorText: "white"
        qText: qsTr("Libraries")
        onClicked: {
            myloader.sourceComponent = screenLibraries
            menu.sourceComponent = null
        }
    }
    Menu{

    }

}
