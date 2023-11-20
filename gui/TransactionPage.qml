import QtQuick 2.15
import "../customElements"

Item {
    onVisibleChanged: {
        console.log("TransactionPage visible",visible)
    }

    Rectangle{
        id:layoutLeft

        anchors.bottom: parent.bottom
        anchors.left: parent.left

        height: parent.height/8
        width: parent.width/2

        CustomButton{
            anchors.centerIn: parent
            height: parent.height-20
            width: 0.6*parent.width

            text:  "+ €"
            color: "#70AD47"
            fill:  "#B7D6A3"

            onClicked: {
                moneyTransaction.expense = false
                moneyTransaction.open()
            }
        }
    }


    Rectangle{
        id:layoutRight

        anchors.bottom: parent.bottom
        anchors.right: parent.right

        height: parent.height/8
        width: parent.width/2

        CustomButton{
            anchors.centerIn: parent
            width: 0.6*parent.width
            height: parent.height-20

            text:  "- €"
            color: "#F70000"
            fill:  "#FF7F7F"

            onClicked: {
                moneyTransaction.expense = true
                moneyTransaction.open()
            }

        }
    }
}
