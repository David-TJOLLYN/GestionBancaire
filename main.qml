import QtQuick 2.15
import QtQuick.Window 2.15
import QtCharts 2.15
import QtQuick.Layouts 1.15

import "gui"
import "customElements"
import "dsvg"

Window {
    id: mainWindows
    width: 375
    height: 600
    visible: true

    property string strokeColor: "#3c6c8c"
    property string fillColor: "#9bd3e3"

    minimumWidth: 300
    minimumHeight: 400

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
                loader.active = true
                loader.item.open()
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
            color: fillColor
        }


        RowLayout{
            anchors.fill:parent

            Button{
                Layout.fillWidth: true
                height: parent.height

                Dynamic_SVG{
                    id:homesvg
                    anchors.centerIn: parent
                    height: parent.height-10
                    width: parent.width-10

                    filled: homePage.visible

                    svgComponent: Home_SVG{}
                }

                onClicked: body.currentIndex = 0
            }

            Button{
                Layout.fillWidth: true
                height: parent.height

                Dynamic_SVG{
                    anchors.centerIn: parent
                    height: parent.height-10
                    width: parent.width-10

                    filled: accountPage.visible

                    svgComponent: Account_SVG{}
                }

                onClicked: body.currentIndex = 1
            }

            Button{
                Layout.fillWidth: true
                height: parent.height

                Dynamic_SVG{
                    id:svg
                    anchors.centerIn: parent
                    height: parent.height-10
                    width: parent.width-10

                    filled: transactionPage.visible

                    svgComponent: Transaction_SVG{}
                }

                onClicked: body.currentIndex = 2
            }
        }
    }

    Component{
        id:transactionpopup
        TransactionPopup{
            width: parent.width
            height:parent.height
            onClosed: {
                body.currentIndex = 2
                loader.active = false
            }
            type: transactionPage.type
        }
    }


    Loader{
        id:loader
        active: false
        anchors.fill:parent
        sourceComponent:transactionpopup
    }
}
