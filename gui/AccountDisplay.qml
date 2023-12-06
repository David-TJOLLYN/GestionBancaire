import QtQuick 2.15
import QtQuick.Controls
import "../customElements"

Item {
    id: page

    width: parent.width
    height:parent.height

    property  variant accountFocus

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

        interactive: false

        MouseArea {
            anchors.fill: parent
            preventStealing: true

            onWheel: event => {
                if (event.angleDelta.y > 0) {
                    scrollBar.decrease()
                } else {
                    scrollBar.increase()
                }
            }
        }

        ScrollBar.vertical: ScrollBar {
            id: scrollBar
            visible: false
        }

        AccountsList{
            id:listView
            height: handler.accounts.length*(60+10)
            anchors.top:parent.top
            accountlist: handler.accounts
            interactive:false
            onAccountChanged: page.accountFocus = account
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
                    loader.sourceComponent = popup
                    loader.active = true
                    loader.item.open()
                }
            }
        }
    }

    Component{
        id:popup
        CreateAccountPopup{
            height: parent.height+60
            onClosed: loader.active = false
        }
    }

    Loader{
        id:loader
        active: false
        anchors.fill:parent
    }
}
