import QtQuick 2.15
import "../customElements"

Item {
    width: parent.width
    height: parent.height

    property variant account

    Component{
        id:transactions

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
        }
    }

    ListView{
        id:list
        width: parent.width
        height: parent.height
        model: account.transactions()
        delegate: transactions

        clip: true
        spacing: 10
        topMargin: 10
        leftMargin: 10
        rightMargin: 10
        bottomMargin: 10
        boundsMovement: Flickable.StopAtBounds
    }
}
