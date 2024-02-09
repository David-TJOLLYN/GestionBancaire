import QtQuick 2.15
import QtQuick.Layouts 1.15
import Qt.labs.qmlmodels

import "../customElements"
import "../js/extract.js" as BDD

Item {
    id: homePage
    focus: false

    width: parent.width
    height:parent.height

    property color color: "#3C6888"
    property string font: "Comic Sans MS"
    property real px: 15
    property bool small: false

    Header{
        id:header
        text:qsTr("Acceuil")
        width: parent.width
    }

    AccountHeaderForm{
        account: handler.account(1)

        anchors {
            top: header.bottom
            left: parent.left
            right: parent.right
            margins:15
        }
    }
}
