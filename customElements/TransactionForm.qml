import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts
import "../js/extract.js" as BDD

Item {
    width: parent.width
    height: 17
    property variant transaction

    TextEditable {
        id: txt
        text: BDD.formatDate(transaction.date)
        type: 2
        anchors.left: parent.left
        anchors.verticalCenter: parent.verticalCenter
        width: 0.2*parent.width
    }

    TextEditable {
        text: transaction.category
        type: 0
        anchors.left: txt.right
        anchors.verticalCenter: parent.verticalCenter
        width: 0.6*parent.width
        textAnchorMargins: 20
    }

    TextEditable {
        type: 1
        text: transaction.amount + " €"
        anchors.right: parent.right
        anchors.verticalCenter: parent.verticalCenter
        width: 0.2*parent.width
        textAnchorLeft: false
        textAnchorRight: true
    }
}
