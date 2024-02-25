import QtQuick 2.15
import "../Settings.js" as Setting

Item {
    id:header
    property string text: "default"
    property color background: Setting.strokeColor
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
