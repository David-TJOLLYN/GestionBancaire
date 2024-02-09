import QtQuick 2.15
import QtQuick.Controls 2.15
import "../customElements"

Popup {
    id:popup
    property var titles:[qsTr("Virement interne"), qsTr("Ajouter un revenu"), qsTr("Ajouter une dépense")]
    property var infos: [qsTr("Choix du compte a débiter"), qsTr("Choix du compte a créditer"), qsTr("Choix du compte a débiter")];
    property real type : 0

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
                onAccountChanged: {
                    if(type == 0){
                        swipeView.currentIndex = 2
                        intern.debitAccount = account
                    }
                    else{
                        swipeView.currentIndex = 1
                        extern.account = account
                        extern.expense = (type-1)==1
                    }
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

        Item{
            TransactionInternal{
                id: intern
                title: titles[type]
                onClosed: popup.close()
                onCreditAccountChanged:{
                    internamount.creditAccount= creditAccount
                    internamount.debitAccount=debitAccount
                    swipeView.currentIndex=3
                    internamount.forceActiveFocus()
                }
            }
        }

        Item{
            TransactionInternalAmount{
                id:internamount
                title: titles[type]
                onClosed: popup.close()
            }
        }
    }

    enter: Transition {
        NumberAnimation{
            property: "y"
            from: parent.height ; to:0
            duration: 350
            easing.type: Easing.OutQuad
        }
    }

    exit: Transition{
        NumberAnimation {
            property: "y"
            from: 0 ; to: parent.height
            duration: 250
            easing.type: Easing.InOutQuad
        }
    }
}
