import QtQuick 2.15
import QtQuick.Window 2.15
import QtCharts 2.15
import QtQuick.Layouts 1.15

import "gui"
import "customElements"

Window {
    id: mainWindows
    width: 375
    height: 540
    visible: true
    title: qsTr("Tests coding")

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

    MoneyTransactionForm {
        id:moneyTransaction
        width: 0.90*parent.width
        height: 230
    }

    Rectangle{
        id:layoutLeft

        anchors.bottom: parent.bottom
        anchors.left: parent.left

        height: parent.height/7
        width: parent.width/2

        CustomButton{
            anchors.centerIn: parent
            height: parent.height-20
            width: 0.6*parent.width

            text:  "+ €"
            color: "#70AD47"
            fill:  "#B7D6A3"

            onClicked: {
                moneyTransaction.expense = false
                moneyTransaction.open()
            }
        }
    }


    Rectangle{
        id:layoutRight

        anchors.bottom: parent.bottom
        anchors.right: parent.right

        height: parent.height/7
        width: parent.width/2

        CustomButton{
            anchors.centerIn: parent
            width: 0.6*parent.width
            height: parent.height-20

            text:  "- €"
            color: "#F70000"
            fill:  "#FF7F7F"

            onClicked: {
                moneyTransaction.expense = true
                moneyTransaction.open()
            }

        }
    }
}
