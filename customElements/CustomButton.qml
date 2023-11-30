import QtQuick 2.15

Item{
    id:btn
    property string text: "valider"
    property color color: "white"
    property color fill: "#3C6888"
    property string font: "Comic sans MS"
    signal clicked

    Rectangle{
        width: parent.width
        height: 25
        radius: 25
        color: btn.fill

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
}
