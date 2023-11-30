import QtQuick 2.15
import "../customElements"

Item {
    id:page
    width:parent.width
    height:parent.height

    property string title: "DEFAULT"
    property string info: "default"
    property variant account
    signal closed

    HeaderAndExitBtn{
        id:header
        title: page.title
        onClosed: page.closed()
    }

    Rectangle{
        id:txtinfo
        width: parent.width
        height:txt.implicitHeight+20
        anchors.top:header.bottom
        anchors.margins:10

        Text{
            id:txt
            anchors.centerIn: parent
            text: page.info
        }
    }

    AccountsList{
        anchors.top: txtinfo.bottom
        onAccountChanged: page.account = account
        accountlist: handler.accounts
        height: parent.height-header.height-txtinfo.height-20
    }
}
