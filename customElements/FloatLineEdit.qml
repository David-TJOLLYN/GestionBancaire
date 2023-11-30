import QtQuick 2.15

Rectangle {

    property alias text: txt.text
    property alias suffix: suffix.text
    property alias prefix: prefix.text

    color:  "white"
    border.color:"#B0B0B0"
    border.width: 1

    Text {
        id: prefix
        text: ""
        color: "black"

        anchors.left: parent.left
        anchors.right:txt.left
        anchors.rightMargin: 4
        height: parent.height

        verticalAlignment:   TextInput.AlignVCenter
        horizontalAlignment: TextInput.AlignRight
    }

    TextInput{
        id: txt
        text: ""
        color: "black"
        validator:DoubleValidator{decimals: 2}

        anchors.left: parent.Left
        anchors.right: suffix.left
        anchors.margins: 2
        height: parent.height

        verticalAlignment:   TextInput.AlignVCenter
        horizontalAlignment: TextInput.AlignRight
    }

    Text {
        id: suffix
        text: ""
        color: "black"

        anchors.right: parent.right
        anchors.rightMargin: 8
        height: parent.height

        verticalAlignment:   TextInput.AlignVCenter
        horizontalAlignment: TextInput.AlignRight
    }

    MouseArea{
        anchors.fill: parent
        onClicked: {
            text = ""
            txt.forceActiveFocus()
        }
    }

}
