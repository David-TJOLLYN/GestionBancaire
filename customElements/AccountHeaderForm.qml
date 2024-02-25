import QtQuick 2.15
import "../Settings.js" as Setting

Rectangle {
    id: frame

    height: 10+frametitle.height+33+itemNbr*(17+5)+10
    width: parent.width
    border.width: 2
    border.color: Setting.strokeColor
    radius: 10

    property variant account
    property real itemNbr: 5

    Rectangle {
        id: frametitle
        height:rowAccount.implicitHeight
        width: parent.width

        anchors {
            top: parent.top
            left: parent.left
            right: parent.right
            margins:10
        }

        StyledText {
            id: rowAccount
            text: account.name
            color: homePage.color
            anchors.left:parent.left

        }

        StyledText {
            id: rowSold
            text: qsTr(account.sold.toFixed(2)+" €")
            color: homePage.color
            anchors.right:parent.right
        }
    }

    Rectangle{
        id:line
        width: parent.width
        height:3
        color:homePage.color
        anchors{
            left:parent.left
            right:parent.right
            top:frametitle.bottom
            topMargin: 10
        }
    }

    Component{
        id:transactionForm
        TransactionForm{
            transaction:modelData
        }
    }

    ListView {
        id:lastTransactionList
        width: parent.width
        height: parent.height

        anchors{
            left:parent.left
            right:parent.right
            top:line.bottom
            margins:10
        }

        model: account.getLastTransactions(itemNbr)

        delegate: transactionForm

        Connections {
            target: account
            function onTransactionsChanged() {
                lastTransactionList.model = account.getLastTransactions(5)
            }
        }

        interactive: false

        spacing:10
    }
}
