import QtQuick 2.15
import QtQuick.Layouts 1.15
import "../customElements"

Item {
    id: accountPage

    width: parent.width
    height:parent.height

    Header{
        id:header
        text:"Comptes et Livrets"
    }

    Component{
        id: accountform
        AccountForm{
            account:modelData
        }
    }

    ListView {
        anchors.top:header.bottom
        width: parent.width
        height: parent.height - header.height
        model: accounts
        delegate: accountform
        clip: true
        spacing:10
        topMargin: 15
        leftMargin: 10
        rightMargin: 10
        bottomMargin: 10
    }
}
