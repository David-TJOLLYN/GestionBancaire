import QtQuick 2.15

Rectangle {
    property alias text: txt.text
    signal forceActiveFocus

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

    onForceActiveFocus: txt.forceActiveFocus()
}
