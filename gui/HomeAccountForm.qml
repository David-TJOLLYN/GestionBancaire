import QtQuick 2.15
import QtQuick.Layouts

Item {
    property color color: "#3C6888"
    property string font: "Comic Sans MS"
    property real px: 15
    property real implicitWidth: account.implicitWidth + sold.implicitWidth



    Text {
        id: account
        text: "Compte bancaire :"
        color: parent.color
        font.family: parent.font
        font.pixelSize: parent.px
    }

    Item {
        Layout.fillWidth: true
    }

    Text {
        id: sold
        text: "1230.45 €"
        color: parent.color
        font.family: parent.font
        font.pixelSize: parent.px
        Layout.alignment: Qt.AlignRight
    }
}
