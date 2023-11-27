import QtQuick 2.15

Item {
    id:header
    height: 60
    width:parent.width

    property string title: "Default"
    property color backgroung : "#3C6888"
    property color color: "white"
    signal closed

    Rectangle{
        width:parent.width
        height: parent.height
        color: header.backgroung

        anchors.top:parent.top

        ExitButton{
            id:exitbtn
            onClicked: header.closed()
        }

        StyledText{
            text: header.title
            color: header.color
            anchors{
                left: exitbtn.right
                verticalCenter: parent.verticalCenter
            }
        }
    }
}
