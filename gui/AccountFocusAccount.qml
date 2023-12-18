import QtQuick 2.15
import "../customElements"

Item {
    id: page
    property variant account

    AccountHeaderForm{
        account:page.account
        anchors{
            top:parent.top
            left:parent.left
            right:parent.right
            margins:15
            topMargin: 20
        }
    }
}
