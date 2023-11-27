import QtQuick 2.15

Item{
    id:exitbtn

    signal clicked

    width: parent.height
    height:parent.height
    property color background: "transparent"
    property color color: "white"

    Rectangle{
        width: parent.height/2
        height:parent.height/2
        color: exitbtn.background

        anchors{
            left: parent.left ; margins: 10
            verticalCenter: parent.verticalCenter
        }

        StyledText{
            text:"X"
            color: exitbtn.color
            anchors.centerIn: parent
        }

        MouseArea{
            anchors.fill:parent
            onClicked: exitbtn.clicked()
        }
    }
}
