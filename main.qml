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

    minimumWidth: 300
    minimumHeight: 400

    TransactionPopup{
        id:transactionpopup
        width: parent.width
        height:parent.height
        onClosed: body.currentIndex = 2
    }

    StackLayout{
        id:body
        currentIndex: 0

        width: parent.width
        height:parent.height - footer.height

        anchors{
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

            onOpenPopup:{
                transactionpopup.type = type
                transactionpopup.open()
            }
        }
    }

    Rectangle{
        id:footer
        height: 60
        anchors{
            left:parent.left
            right:parent.right
            bottom:parent.bottom
        }

        Rectangle{
            height: 2
            width:parent.width
            color:"#3C6888"

        }

        RowLayout{
            anchors.fill:parent
            anchors.margins: 10

            property real currentItem: 0

            IconButton{
                focus: homePage.visible
                icon: "../icon/homepage.png"
                iconfocus: "../icon/homepagefilled.png"
                onClicked: body.currentIndex = 0
            }

            IconButton{
                focus:accountPage.visible
                icon: "../icon/accountpage.png"
                iconfocus: "../icon/accountpagefilled.png"
                onClicked: body.currentIndex = 1
            }

            IconButton{
                focus:transactionPage.visible
                icon: "../icon/transactionpage.png"
                iconfocus: "../icon/transactionpagefilled.png"
                onClicked: body.currentIndex = 2
            }
        }
    }
}
