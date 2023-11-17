import QtQuick 2.15

Item {
    property color color: "cyan"

    Rectangle{
        anchors.fill: parent
        color: parent.color
    }

}
