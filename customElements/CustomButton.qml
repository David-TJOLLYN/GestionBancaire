import QtQuick 2.15

Item{
    property string text: "Default Text"
    property color color: "blue"
    property color fill: "red"
    property string font: "Comic sans MS"
    signal clicked

    Rectangle {
        id:rect
        anchors.fill: parent
        color: parent.fill
        border.color: parent.color
        border.width: 1+parent.height*0.05
        radius: 10
    }

    Text {
        anchors.centerIn: parent

        text: parent.text
        color: parent.color
        font.family: parent.font

        font.pixelSize: parent.height - 10
        font.bold: true
    }

    MouseArea {
        id:mouseArea
        anchors.fill: parent
        onClicked: parent.clicked()
    }
}
