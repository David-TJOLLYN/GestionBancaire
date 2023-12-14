import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts
import "../js/extract.js" as BDD

Item {
    width: parent.width
    height: 17
    property variant transaction

    Text {
        id: txt
        text: BDD.formatDate(transaction.date)
        color: "grey"
        anchors.left: parent.left
        anchors.verticalCenter: parent.verticalCenter
    }

    Text {
        text: transaction.category
        anchors.left: txt.right
        anchors.verticalCenter: parent.verticalCenter
        anchors.margins: 20
    }

    Text {
        text: transaction.amount + " €"
        anchors.right: parent.right
        anchors.verticalCenter: parent.verticalCenter
    }
}
