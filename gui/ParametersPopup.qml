import QtQuick 2.15
import QtQuick.Controls

import "../customElements"

Popup {
    id: popup

    property bool show: false

    modal: true
    focus: true
    padding:0

    background: Rectangle{
        anchors.fill:parent
        color:"white"
    }


    HeaderAndExitBtn{
        id:header
        title: qsTr("Paramètres")
        onClosed: popup.close()
    }


    enter: Transition {
        NumberAnimation{
            property: "y"
            from: parent.height ; to:0
            duration: 350
            easing.type: Easing.OutQuad
        }
    }

    exit: Transition{
        NumberAnimation {
            property: "y"
            from: 0 ; to: parent.height
            duration: 250
            easing.type: Easing.InOutQuad
        }
    }
}
