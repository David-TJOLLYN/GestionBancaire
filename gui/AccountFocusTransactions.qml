import QtQuick 2.15
import QtQuick.Controls
import "../customElements"

Item {
    width: parent.width
    height: parent.height

    property variant account

    Component{
        id:transactionsModel

        Item{
            width: parent ? parent.width : 200
            height:info.height+10
            property var k : modelData

            TransactionForm{
                id:info
                transaction: parent.k                
            }

            Rectangle{
                anchors.top:info.bottom
                anchors.margins: 10
                width: parent.width
                height:1
                color:"lightgrey"
                radius:2
            }

            MouseArea {
                anchors.fill: parent
                acceptedButtons: Qt.LeftButton | Qt.RightButton
                onClicked: mouse => { if (mouse.button === Qt.RightButton) contextMenu.popup() }
            }

            Menu {
                id: contextMenu
                MenuItem {
                    text: "Modifier"
                    onTriggered: {
                        console.log("Menu action edit ",k.id);
                    }
                }
                MenuItem {
                    text: "Supprimer"
                    onTriggered: {
                        console.log("Menu action delete",k.id);
                        account.deleteTransaction(k.id);
                    }
                }
            }
        }
    }

    ListView{
        id:list
        width: parent.width
        height: parent.height
        model: account.transactions
        delegate: transactionsModel

        Connections {
            target: account
            function onTransactionsChanged() {
                list.model = account.transactions
            }
        }

        clip: true
        spacing: 10
        topMargin: 10
        leftMargin: 10
        rightMargin: 10
        bottomMargin: 10
        boundsMovement: Flickable.StopAtBounds
    }
}
