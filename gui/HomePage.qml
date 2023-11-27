import QtQuick 2.15
import QtQuick.Layouts 1.15
import Qt.labs.qmlmodels

import "../customElements"
import "../js/extract.js" as BDD

Item {
    id: homePage
    focus: false

    property color color: "#3C6888"
    property string font: "Comic Sans MS"
    property real px: 15
    property bool small: false
    property variant account : accounts[0]

    Header{
        id:header
        text:"Home"
        width: parent.width
    }

    Rectangle {
        id: frame

        height: 200
        width: parent.width
        border.width: 2
        border.color: parent.color
        radius: 10

        anchors {
            top: header.bottom
            left: parent.left
            right: parent.right
            margins:15
        }

        Rectangle {
            id: frametitle
            height:rowAccount.implicitHeight
            width: parent.width

            anchors {
                top: parent.top
                left: parent.left
                right: parent.right
                margins:10
            }

            StyledText {
                id: rowAccount
                text: account.name
                anchors.left:parent.left

            }

            StyledText {
                id: rowSold
                text: qsTr(account.sold.toFixed(2)+" €")
                anchors.right:parent.right
            }
        }

        Rectangle{
            id:line
            width: parent.width
            height:3
            color:homePage.color
            anchors{
                left:parent.left
                right:parent.right
                top:frametitle.bottom
                topMargin: 10
            }
        }

        Component{
            id:transactionForm
            Rectangle{
                width: parent.width
                height: txt.implicitHeight

                Text{
                    id:txt
                    anchors.left: parent.left
                    text:BDD.formatDate(modelData.date)
                    color:"grey"
                }

                Text{
                    text:modelData.category
                    anchors.left:txt.right
                    anchors.margins:20
                }

                Text{
                    text:modelData.amount+" €"
                    anchors.right:parent.right
                }
            }
        }

        ListView {
            id:lastTransactionList
            width: parent.width
            height: parent.height

            anchors{
                left:parent.left
                right:parent.right
                top:line.bottom
                margins:10
            }

            model: account.getLastTransactions(5)

            delegate: transactionForm

            Connections {
                target: account
                function onUpdateLastTransaction() {
                    lastTransactionList.model = account.getLastTransactions(5)
                }
            }

            interactive: false

            spacing:10
        }
    }
}
