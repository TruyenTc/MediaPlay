import QtQuick 2.15
import"../component"

QRectText{
    height: 20
    width: 100
    colorText: "white"
    id:txt
    qText : qsTr("Language")
    onClicked: {
        idcolume.visible = !idcolume.visible
    }
    Column{
        id:idcolume
        anchors.left: parent.right
        visible: false
        QRectText{
            height: 20
            width: 60
            colorText: "white"
            qText: "Viet Nam"
                onClicked: {
                    idcolume.visible = !idcolume.visible
                    translator.setLanguage("VN.qm");
                    menu.sourceComponent = null
                }
        }
        QRectText{
            height: 20
            width: 60
            colorText: "white"
            qText: "English"
                onClicked: {
                    idcolume.visible = !idcolume.visible
                    translator.setLanguage("EL.qm");                  
                    menu.sourceComponent = null
                }
        }

    }
}
