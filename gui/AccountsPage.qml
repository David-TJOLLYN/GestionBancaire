import QtQuick 2.15

Rectangle {
    id: accountListView
    anchors {top: parent.top; left:parent.left; right:parent.right}
    anchors.fill:parent

    Component{
        id: accountform
        AccountForm{
            name: modelData.name
            sold: modelData.sold
            num:  modelData.number
            anchors{left:parent.left;right:parent.right}
        }
    }

    ListView {
        anchors.fill:parent
        model: accounts
        delegate: accountform
        clip: true
        spacing:10
        topMargin: 10
        leftMargin: 10
        rightMargin: 10
        bottomMargin: 10
    }
}
