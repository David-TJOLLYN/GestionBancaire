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

    StackLayout{
        id:body
        currentIndex: 0
        anchors{
            left:parent.left
            right:parent.right
            top:parent.top
            bottom:footer.top
        }

        HomePage{
            id:homePage
        }

        AccountsPage{
            id:accountPage
        }

        TransactionPage{
            id:transactionPage
        }
    }

    Rectangle{
        id:footer
        color:"white"
        height: 60
        anchors{
            left:parent.left
            right:parent.right
            bottom:parent.bottom
        }

        RowLayout{
            anchors.fill:parent
            anchors.margins: 10
            property real currentItem: 0

            IconButton{
                Layout.preferredHeight: parent.height
                Layout.preferredWidth: parent.width/3
                focus: homePage.visible
                icon: "../icon/homepage.png"
                iconfocus: "../icon/homepagefilled.png"
                onClicked: body.currentIndex = 0
            }

            IconButton{
                Layout.preferredHeight: parent.height
                Layout.preferredWidth: parent.width/3
                focus:accountPage.visible
                icon: "../icon/accountpage.png"
                iconfocus: "../icon/accountpagefilled.png"
                onClicked: body.currentIndex = 1
            }

            IconButton{
                Layout.preferredHeight: parent.height
                Layout.preferredWidth: parent.width/3
                focus:transactionPage.visible
                icon: "../icon/transactionpage.png"
                iconfocus: "../icon/transactionpagefilled.png"
                onClicked: body.currentIndex = 2
            }
        }
    }
}
