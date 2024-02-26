import QtQuick 2.15
import QtQuick.Layouts 1.15
import Qt.labs.qmlmodels

import "../dsvg"
import "../customElements"
import "../js/extract.js" as BDD

Item {
    id: homePage
    focus: false

    width: parent.width
    height:parent.height

    property string font: "Comic Sans MS"
    property real px: 15
    property bool small: false


    Header{
        id:header
        text:qsTr("Acceuil")
        width: homePage.width

        Button{
            anchors.right: parent.right
            width: parent.height
            height: parent.height

            Dynamic_SVG{
                width: 0.6*parent.height
                height: 0.6*parent.height
                anchors.centerIn:parent

                strokeColor: root.fillColor
                filled:true

                svgComponent: Parameter_SVG{}
            }

            onClicked: loader.active = true
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
