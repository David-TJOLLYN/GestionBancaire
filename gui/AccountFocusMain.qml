import QtQuick 2.15
import QtQuick.Controls
import "../customElements"


Item {
    id:page
    width:parent.width
    height:parent.height

    property var tablist: ["Paramètres","Transactions","Graphiques","Solde","Options","Analyse","Rapport"]
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
                AccountFocusParameter{
                    id:parameter
                    height:swipeview.height
                    width:swipeview.width
                    account:page.account
                }
            }

            Rectangle{
                height:swipeview.height
                width:swipeview.width
                color:"red"
                border.color: "black"

                StyledText{
                    id:txt
                    anchors.centerIn:parent
                    text: tablist[tab.currentIndex]
                    color:"black"
                }
            }
        }

        Component.onCompleted: console.log("Focus account main completed")
        Component.onDestruction: console.log("Focus account main destroyed")

        }

    }

}
