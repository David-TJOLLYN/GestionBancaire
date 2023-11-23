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

    minimumWidth: 300
    minimumHeight: 400

    Rectangle{
        id:header
        color:"#3C6888"
        height: 60
        width: parent.width
        anchors{
            top:parent.top
            left:parent.left
            right:parent.right
        }
        StyledText{
            id:headerTxt
            text:"Home"
            color:"white"
            anchors{
                left:parent.left
                verticalCenter: parent.verticalCenter
                margins:15
            }
        }
    }

    TransactionPopup2{
        id:transactionPopup
        width: parent.width
        height:parent.height-footer.height
    }


    StackLayout{
        id:body
        currentIndex: 0
        anchors{
            left:parent.left
            right:parent.right
            top:header.bottom
            bottom:footer.top
        }

        HomePage{
            id:homePage
            width: parent.width
            height:parent.height - footer.height
        }

        AccountsPage{
            id:accountPage
        }

        TransactionPage{
            id:transactionPage
            width: parent.width
            height:parent.height - footer.height

            onOpenPopup:{
                transactionPopup.type = type
                transactionPopup.open()
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
                onClicked:{
                    headerTxt.text = "Home"
                    body.currentIndex = 0
                }
            }

            IconButton{
                focus:accountPage.visible
                icon: "../icon/accountpage.png"
                iconfocus: "../icon/accountpagefilled.png"
                onClicked: {
                    headerTxt.text = "Comptes et Livrets"
                    body.currentIndex = 1
                }
            }

            IconButton{
                focus:transactionPage.visible
                icon: "../icon/transactionpage.png"
                iconfocus: "../icon/transactionpagefilled.png"
                onClicked: {
                    headerTxt.text = "Transaction"
                    body.currentIndex = 2
                }
            }
        }
    }
}
