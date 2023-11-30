import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15
import "../customElements"

Item {
    id: accountPage

    width: parent.width
    height:parent.height

    Header{
        id:header
        text:"Comptes et Livrets"
    }

    Flickable {
        width: parent.width
        height: parent.height-header.height
        contentHeight: listView.height+btn.height+40

        clip:true
        anchors.top:header.bottom

        boundsMovement: Flickable.StopAtBounds

        AccountsList{
            id:listView
            height: handler.accounts.length*(60+10)
            anchors.top:parent.top
            accountlist: handler.accounts
            interactive:false
        }

        Rectangle{
            id:btn
            height: 60
            width: parent.width-20
            radius: 4
            border.color: "grey"

            anchors{
                horizontalCenter: parent.horizontalCenter
                top: listView.bottom
                margins:20
            }

            Text{
                text:"Ajouter un compte ou livret"
                anchors.centerIn: parent
            }

            MouseArea{
                anchors.fill:parent
                onClicked:{
                    popup.open()
                }
            }
        }
    }

    CreateAccountPopup{
        id:popup
    }
}
