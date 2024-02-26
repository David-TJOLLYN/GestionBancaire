import QtQuick 2.15

Item {
    id:header
    property string text: "default"
    property color background: root.strokeColor
    property color color: "white"
    height: 60
    width: parent.width
    anchors.top:parent.top

    Rectangle{
        color: header.background
        anchors.fill:parent

        StyledText{
            id:headerTxt
            text: header.text
            color: header.color
            anchors{
                left:parent.left
                verticalCenter: parent.verticalCenter
                margins:15
            }
        }
    }
}
