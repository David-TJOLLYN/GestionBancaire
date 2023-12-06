import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts

Item {
    id: item
    height: 30
    width: parent.width
    property color background: "#3C6888"
    property color color: "white"
    property var tabs
    property real currentIndex: 0

    Rectangle {
        anchors.fill: parent
        color: background
    }

    ListView {
        id: listView
        width: parent.width
        height: item.height

        model: tabs

        delegate: Item {
            width: txt.implicitWidth + 20
            height: listView.height

            Rectangle {
                height: parent.height
                width: parent.width
                color: item.background

                StyledText {
                    id: txt
                    text: modelData
                    font.pixelSize: 13
                    anchors.centerIn: parent
                }

                Rectangle{
                    anchors.top:txt.bottom
                    anchors.horizontalCenter: parent.horizontalCenter
                    height:2 ; radius:2
                    width:txt.implicitWidth
                    color: item.currentIndex === index ? "white" : "transparent"
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: item.currentIndex = index
                }
            }
        }

        orientation: ListView.Horizontal
        clip: true
        boundsMovement: Flickable.StopAtBounds
    }
}
