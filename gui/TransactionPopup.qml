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

    onClosed:{
        swipeView.currentIndex = 0
    }

    SwipeView {
        id: swipeView
        anchors.fill: parent
        interactive: false

        Item{
            TransactionSelectAccount {
                width: swipeView.width
                height: swipeView.height
                title: titles[type]
                info: infos[type]
                onClosed: popup.close()
                onAccountSelected:{
                    swipeView.currentIndex = 1
                    extern.account = account
                    extern.expense = (type-1)==1
                }
            }
        }

        Item{
            TransactionExpenseRevenue{
                id: extern
                title: titles[type]
                onClosed: popup.close()
            }
        }
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
