import QtQuick 2.15

Rectangle {
    property variant account

    width: parent.width
    height: 60
    radius: 4
    border.color: "grey"

    Text {
        id: accountName
        text: account ? account.name : "compte"
        anchors{ left:parent.left; top:parent.top}
        anchors.margins: 10
    }

    Text {
        id: accountSold
        text: account ? account.sold.toFixed(2)+" €" : "0.00 €"
        anchors{ right:parent.right; top:parent.top}
        anchors.margins: 10
    }

    Text{
        id:accountNum
        text: account ? account.number.replace(/(.{4})/g, "$1 ") : "xxxx xxxx xxxx"
        anchors{ top:accountName.bottom; right:parent.right; left:parent.left}
        anchors.margins: 10
    }
}
