import QtQuick 2.15
import "../customElements"
import "../js/extract.js" as BDD

Item {
    id:page
    width:parent.width
    height:parent.height

    property string title: "Default"
    property var account
    signal closed

    HeaderAndExitBtn{
        id:header
        title: page.title
        onClosed: page.closed()
    }

    Rectangle {
        anchors.top:header.bottom
        width: parent.width
        height: 60

        color: "#98D7E5"

        Rectangle {
            id: clipper
            anchors.top:parent.bottom
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
                color: "#98D7E5"
            }
        }

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
}
