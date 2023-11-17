import QtQuick 2.15

Item{
    signal clicked

    Rectangle {
        id:rect
        anchors.fill: parent
        color: mouse.containsMouse ? "#E81123" : "transparent"
    }

    Text {
        anchors.centerIn: parent

        text: "X"
        color: mouse.containsMouse ? "white" : "#B0B0B0"
        font.family: "Comic sans MS"
        font.pixelSize: parent.height - 10
    }

    MouseArea {
        id:mouse
        hoverEnabled: true
        anchors.fill: parent
        onClicked: parent.clicked()
    }
}
