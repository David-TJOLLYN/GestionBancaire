import QtQuick 2.15

Rectangle {
    property string name:""
    property real sold:0.00
    property string num:"xxxx xxxx xxxx"

    width: parent.width
    height: 60
    radius: 4
    border.color: "grey"

    Text {
        id: accountName
        text: qsTr(name)
        anchors{ left:parent.left; top:parent.top}
        anchors.margins: 10
    }

    Text {
        id: accountSold
        text: qsTr(sold.toFixed(2)+" €")
        anchors{ right:parent.right; top:parent.top}
        anchors.margins: 10
    }

    Text{
        id:accountNum
        text: qsTr(num)
        anchors{ top:accountName.bottom; right:parent.right; left:parent.left}
        anchors.margins: 10
    }
}
