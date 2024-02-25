import QtQuick 2.15
import "../Settings.js" as Setting

Item {
    id:page
    height:65
    width: 0.95*parent.width
    anchors.horizontalCenter: parent.horizontalCenter

    property variant account: accounts[0]

    Rectangle {
        id:info
        width: parent.width
        height: 51

        color: Setting.fillColor

        StyledText {
            anchors{
                verticalCenter: parent.verticalCenter
                left: parent.left
                margins:10
            }
            text: page.account ? page.account.name : "default"
            color:"white"
        }

        StyledText {
            anchors{
                verticalCenter: parent.verticalCenter
                right: parent.right
                margins:10
            }
            text: page.account ? page.account.sold.toFixed(2)+" €" : "N/A €"
            font.bold: true
            color:"white"
        }
    }

    Rectangle {
        id: clipper
        anchors.top:info.bottom
        width: parent.width
        height: clipped.radius
        color: 'transparent'
        clip: true

        Rectangle {
            id: clipped
            width: parent.width
            height: parent.height + radius
            y:-radius
            radius: 15
            color: Setting.fillColor
        }
    }
}
