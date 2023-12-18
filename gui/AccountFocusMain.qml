import QtQuick 2.15
import QtQuick.Controls
import "../customElements"


Item {
    id:page
    width:parent.width
    height:parent.height

    property var tablist: ["Solde","Transactions","Paramètres"]
    property variant account
    property bool show: false
    signal close

    HeaderAndExitBtn{
        id:header
        anchors.top:parent.top
        title: account ? account.name : "default"
        onClosed: page.close()
    }

    onShowChanged: loader.active = show

    Loader{
        id:loader
        active:false
        anchors.top:header.bottom
        sourceComponent: content
    }

    Component{
        id:content

        Item{

        Tabs{
            id:tab
            width: page.width
            tabs: tablist
        }

        SwipeView{
            id:swipeview
            anchors.top:tab.bottom
            width: page.width
            height:page.height-header.height-tab.height
            currentIndex: tab.currentIndex
            interactive: false

            Item{
                AccountFocusSold{
                    height:swipeview.height
                    width:swipeview.width
                    account: page.account
                }
            }

            Item{
                AccountFocusTransactions{
                    height:swipeview.height
                    width:swipeview.width
                    account: page.account
                }
            }

            Item{
                AccountFocusParameter{
                    id:parameter
                    height:swipeview.height
                    width:swipeview.width
                    account:page.account
                }
            }
        }

        Component.onCompleted: console.log("Focus account main completed")
        Component.onDestruction: console.log("Focus account main destroyed")

        }
    }
}
