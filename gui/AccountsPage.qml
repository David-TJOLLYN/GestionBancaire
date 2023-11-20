import QtQuick 2.15
import QtQuick.Layouts 1.15

Item {
    id: accountPage
    focus: false
    Layout.fillWidth: true
    Layout.fillHeight: true

    onVisibleChanged: {
        console.log("AccountPage visible",visible)
    }


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
