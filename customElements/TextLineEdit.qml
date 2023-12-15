import QtQuick 2.15

Rectangle {
    property string defaultText: ""
    property alias text: txt.text
    property bool modified: false
    signal forceActiveFocus
    signal accepted

    color:  "white"
    border.color:"#B0B0B0"
    border.width: 1

    TextInput{
        id: txt
        color: "black"
        text: defaultText

        anchors.fill: parent
        anchors.margins: 2
        verticalAlignment: TextInput.AlignVCenter

        onTextChanged: parent.modified = true;
        onAccepted: parent.accepted()
    }

    MouseArea{
        anchors.fill: parent
        onClicked: txt.forceActiveFocus()
        onDoubleClicked: txt.selectAll()
    }

    onForceActiveFocus: txt.forceActiveFocus()
}
