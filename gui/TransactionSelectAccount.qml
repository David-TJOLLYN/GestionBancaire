import QtQuick 2.15
import "../customElements"

Item {
    id:page
    width:parent.width
    height:parent.height

    property string title: "DEFAULT"
    property string info: "default"
    property var account
    signal accountSelected
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

    Component{
        id: accountform
        AccountTemplate{
            name: modelData.name
            sold: modelData.sold
            num:  modelData.number

            MouseArea{
                anchors.fill:parent
                onClicked:{
                    account = modelData
                    page.accountSelected()
                }
            }
        }
    }

    ListView {
        anchors.top: txtinfo.bottom
        width: parent.width
        height:parent.height

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
