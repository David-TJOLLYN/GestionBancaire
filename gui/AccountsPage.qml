import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15
import "../customElements"

Item {
    id: accountPage

    width: parent.width
    height:parent.height

    SwipeView{
        id: swipeview
        anchors.fill:parent
        width: parent.width
        height:parent.height
        interactive:false

        AccountDisplay{
            id:display
            width: swipeview.width
            height: swipeview.height
            onAccountFocusChanged:{
                focus.account = accountFocus
                focus.show = true
                console.log(accountFocus)
                swipeview.currentIndex = 1
            }

            //Component.onCompleted: console.log("Display account completed")
            //Component.onDestruction: console.log("Display account destroyed")
        }

        AccountFocusMain{
            id:focus
            width: swipeview.width
            height: swipeview.height
            onClose: {
                focus.show = false
                swipeview.currentIndex = 0
            }
        }
    }
}
