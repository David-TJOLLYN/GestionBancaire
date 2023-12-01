import QtQuick 2.15
import QtQuick.Controls

Item{
    id:btn
    property string text: "valider"
    property color color: "white"
    property color fill: "#3C6888"
    property string font: "Comic sans MS"
    signal clicked

    signal forceActiveFocus

    Rectangle{
        width: parent.width
        height: 25
        radius: 25
        color: btn.fill
        border.color: btn.focus ? "grey" : "transparent"
        border.width: 1

        StyledText{
            text: btn.text
            color: btn.color
            anchors.centerIn: parent
        }

        MouseArea{
            anchors.fill:parent
            onClicked: btn.clicked()
        }
    }

    Keys.onReturnPressed: if(focus) btn.clicked()
    onForceActiveFocus: focus=true
}
