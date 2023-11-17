import QtQuick 2.15
import QtQuick.Window 2.15
import QtCharts 2.15
import QtQuick.Layouts 1.15

import "gui"
import "customElements"

Window {
    id: mainWindows
    width: 375
    height: 600
    visible: true
    title: qsTr("Tests coding")



    MoneyTransactionForm {
        id:moneyTransaction
        width: 0.90*parent.width
        height: 230
    }

    Rectangle{
        id:footer
        color:"lightblue"
        height: parent.height>50 ? 50 : parent.height/10
        anchors{
            left:parent.left
            right:parent.right
            bottom:parent.bottom
        }

        RowLayout{
            anchors.fill:parent
            anchors.margins: 10

            Rectangle{
                color:footer.color
                Layout.preferredHeight: parent.height
                Layout.preferredWidth: parent.width/3
                Image{
                    anchors.fill:parent
                    fillMode: Image.PreserveAspectFit
                    source: "icon/icon_homepage.png"
                }
            }

            Rectangle{
                color:footer.color
                Layout.preferredHeight: parent.height
                Layout.preferredWidth: parent.width/3
                Image{
                    anchors.fill:parent
                    fillMode: Image.PreserveAspectFit
                    source: "icon/icon_accountpage.png"
                }
            }

            Rectangle{
                color:footer.color
                Layout.preferredHeight: parent.height
                Layout.preferredWidth: parent.width/3
                Image{
                    anchors.fill:parent
                    fillMode: Image.PreserveAspectFit
                    source: "icon/icon_transactionpage.png"
                }
            }
        }
    }
}
