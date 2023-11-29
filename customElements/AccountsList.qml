import QtQuick 2.15

Item {
    id:page
    width: parent.width
    height:parent.height

    property var accountlist
    property variant account

    Component{
        id: accountform
        AccountTemplate{
            account: modelData

            MouseArea{
                anchors.fill:parent
                onClicked: page.account = modelData
            }
        }
    }

    ListView {
        width: parent.width
        height:parent.height

        model: accountlist
        delegate: accountform
        clip: true
        spacing:10
        topMargin: 10
        leftMargin: 10
        rightMargin: 10
        bottomMargin: 10
    }
}
