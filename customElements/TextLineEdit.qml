import QtQuick 2.15

Rectangle {
    property alias text: txt.text

    color:  "white"
    border.color:"#B0B0B0"
    border.width: 1

    TextInput{
        id: txt
        text: ""
        color: "black"

        anchors.fill: parent
        anchors.margins: 2
        verticalAlignment:   TextInput.AlignVCenter
    }

    MouseArea{
        anchors.fill: parent
        onClicked: txt.forceActiveFocus()
        onDoubleClicked: txt.selectAll()
    }
}

/* TODO :
            -> when clicked outside unfocus
            -> disable owervrite txt when refocus with text entered by user
            -> rewrite default value when unfocus and txt empty
*/
