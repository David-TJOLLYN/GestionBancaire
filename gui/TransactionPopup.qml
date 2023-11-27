import QtQuick 2.15
import QtQuick.Controls 2.15
import "../customElements"

Popup {
    id:popup
    property var titles:["Virement interne", "Ajouter un revenu", "Ajouter une dépense"]
    property var infos: ["Choix du compte a débiter", "Choix du compte a créditer", "Choix du compte a débiter"];
    property real type : 0
    property real account : 0

    modal: true
    focus: true
    padding:0

    background: Rectangle{
        anchors.fill:parent
        color:"white"
    }

    HeaderAndExitBtn{
        id:header
        title: titles[type]
        onClosed: popup.close()
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
            text: infos[type]
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
                    account = modelData.id
                    popup.accountSelected()
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

    onAboutToShow:{
        animation.restart();
    }

    NumberAnimation on y {
        id:animation
        from: parent.height ; to:0
        duration: 350
        easing.type: Easing.OutQuad
    }
}
