import QtQuick 2.15
import QtQuick.Layouts 1.15
import Qt.labs.qmlmodels


import "../customElements"
import "../js/extract.js" as BDD

Item {
    id: homePage
    focus: false

    width: parent.width
    height:parent.height

    property color color: "#3C6888"
    property string font: "Comic Sans MS"
    property real px: 15
    property bool small: false


    Header{
        id:header
        text:qsTr("Acceuil")
        width: homePage.width

        Rectangle{
            anchors.right: parent.right
            width: parent.height
            height: parent.height
            color:"transparent"

            MouseArea{
                anchors.fill:parent
                onClicked: loader.active = true
            }

            Image{
                source: "../icon/parameterIcon.svg"
                anchors.fill:parent
                anchors.margins: 10
            }
        }
    }

    AccountHeaderForm{
        account: handler.account(1)

        anchors {
            top: header.bottom
            left: parent.left
            right: parent.right
            margins:15
        }
    }

    Loader{
        id:loader
        active:false
        anchors.fill:parent
        sourceComponent: parameterComponent

        onActiveChanged: if(active)item.open()
    }


    Component{
        id:parameterComponent

        ParametersPopup{
            id:parameters
            width: parent.width
            height:parent.height+60

            onClosed: loader.active = false
        }
    }
}
