import QtQuick 2.15
import "../js/extract.js" as BDD

Item {
    width:parent.width
    height: txt.implicitHeight
    property variant transaction

    Rectangle{
        width: parent.width
        height: txt.implicitHeight

        Text{
            id:txt
            anchors.left: parent.left
            text:BDD.formatDate(transaction.date)
            color:"grey"
        }

        Text{
            text:transaction.category
            anchors.left:txt.right
            anchors.margins:20
        }

        Text{
            text:transaction.amount+" €"
            anchors.right:parent.right
        }
    }
}
