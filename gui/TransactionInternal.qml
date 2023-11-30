import QtQuick 2.15
import "../customElements"
import "../js/extract.js" as BDD

Item {
    id:page
    width:parent.width
    height:parent.height

    property string title: "Default"
    property variant debitAccount
    property variant creditAccount

    signal closed


    HeaderAndExitBtn{
        id:header
        title: page.title
        onClosed: page.closed()
    }

    TransactionAccountSelected{
        id:info
        account: page.debitAccount
        anchors.top:header.bottom
    }

    Rectangle{
        id:txtinfo
        width: parent.width
        height:txt.implicitHeight+20
        anchors.top:info.bottom
        anchors.margins:5

        Text{
            id:txt
            anchors.centerIn: parent
            text: "Choix du compte à créditer"
        }
    }

    AccountsList{
        height: parent.height-header.height-info.height-txtinfo.height-40
        anchors.top: txtinfo.bottom
        onAccountChanged: creditAccount = account
        accountlist: debitAccount ? BDD.removeAccount(handler.accounts,debitAccount.name) : []
    }

}
