import QtQuick 2.15
import QtQuick.Controls
import QtQuick.Layouts

import "../customElements"


Popup {
    id: popup

    property bool show: false

    modal: true
    focus: true
    padding:0

    background: Rectangle{
        anchors.fill:parent
        color: "white"
    }

    HeaderAndExitBtn{
        id:header
        title:qsTr("Paramètres")
        anchors.top:parent.top
        onClosed: popup.close()
    }

    ColumnLayout{
        width: 0.9*parent.width
        spacing: 12

        anchors{
            top:header.bottom
            margins:25
            horizontalCenter: parent.horizontalCenter
        }

        Rectangle{
            implicitHeight: 25
            implicitWidth: parent.width

            StyledText{
                id:txt
                color: root.strokeColor
                anchors.left: parent.left
                text: qsTr("Thème :  ")
            }

            RowLayout{
                anchors{
                    centerIn: parent
                    left: txt.right
                    right:parent.left
                }
                height: parent.height


                Repeater {
                    model: 3 // Number of rectangles

                    Rectangle {
                        width: parent.height
                        height: parent.height

                        color: colors[index]
                        border.color: strokeColors[index]
                        border.width: 3

                        MouseArea{
                            anchors.fill:parent
                            onClicked: {
                                console.log("Theme chosen : ", index)
                                root.fillColor  = colors[index]
                                root.strokeColor= strokeColors[index]
                            }
                        }
                    }
                }
            }
        }
    }

    // Define the colors and stroke colors
    property var colors: ["#9bd3e3", "lightpink", "lightgreen"]
    property var strokeColors: ["#3c6c8c", "red", "green"]


    enter: Transition {
        NumberAnimation{
            property: "y"
            from: parent.height ; to:0
            duration: 350
            easing.type: Easing.OutQuad
        }
    }

    exit: Transition{
        NumberAnimation {
            property: "y"
            from: 0 ; to: parent.height
            duration: 250
            easing.type: Easing.InOutQuad
        }
    }
}
