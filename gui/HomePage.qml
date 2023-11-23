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

    Rectangle {
        id: frame

        height: 200
        width: parent.width
        border.width: 2
        border.color: parent.color
        radius: 10

        anchors {
            top: parent.top
            left: parent.left
            right: parent.right
            margins: 0.06 * parent.width
        }

        ColumnLayout{
            anchors.fill:parent

            RowLayout {
                id: rowLayoutComponent
                Layout.margins:10
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignTop

                StyledText {
                    id: rowAccount
                    text: account.name
                }

                Item { Layout.fillWidth: true }

                StyledText {
                    id: rowSold
                    text: qsTr(account.sold.toFixed(2)+" €")
                }
            }

            Rectangle{
                Layout.preferredWidth: parent.width
                height:1
                color:homePage.color
            }

            Component{
                id:transactionForm
                Rectangle{
                    implicitWidth: parent.width
                    implicitHeight: txt.implicitHeight

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
                Layout.preferredWidth: parent.width
                Layout.fillHeight: true

                model: account.getLastTransactions(5)

                delegate: transactionForm

                Connections {
                    target: account
                    onUpdateLastTransaction: {
                        lastTransactionList.model = account.getLastTransactions(5)
                    }
                }

                interactive: false

                spacing:10
                topMargin: 5
                leftMargin: 20
                rightMargin: 20
                bottomMargin: 20
            }
        }
    }
}
