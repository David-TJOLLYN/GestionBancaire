import QtQuick 2.15
import QtQuick.Layouts 1.15

Item {
    id: homePage
    focus: false

    property color color: "#3C6888"
    property string font: "Comic Sans MS"
    property real px: 15
    property bool small: false

    Rectangle {
        id: frame

        height: 100
        width: parent.width
        border.width: 2
        border.color: parent.color
        radius: 10

        anchors {
            top: parent.top
            left: parent.left
            right: parent.right
            margins: 0.06 * parent.width
        }

        RowLayout {
            id: rowLayoutComponent
            anchors {
                top: parent.top
                left: parent.left
                right: parent.right
                margins: 10
            }

            Text {
                id: rowAccount
                text: "Compte bancaire :"
                color: homePage.color
                font.family: homePage.font
                font.pixelSize: homePage.px
            }

            Item {
                Layout.fillWidth: true
            }

            Text {
                id: rowSold
                text: "1230.45 €"
                color: homePage.color
                font.family: homePage.font
                font.pixelSize: homePage.px
                Layout.alignment: Qt.AlignRight
            }
        }

        ColumnLayout {
            id: columnLayoutComponent
            anchors {
                top: parent.top
                left: parent.left
                right: parent.right
                margins: 10
            }

            Text {
                id: columnAccount
                text: "Compte bancaire :"
                color: homePage.color
                font.family: homePage.font
                font.pixelSize: homePage.px
            }

            Item {
                Layout.fillWidth: true
            }

            Text {
                id: columnSold
                text: "1230.45 €"
                color: homePage.color
                font.family: homePage.font
                font.pixelSize: homePage.px
                Layout.alignment: Qt.AlignRight
            }
        }

        states: [
            State {
                name: "RowLayoutState"
                when: !small
                PropertyChanges {
                    target: rowLayoutComponent
                    visible: true
                }
                PropertyChanges {
                    target: columnLayoutComponent
                    visible: false
                }
            },
            State {
                name: "ColumnLayoutState"
                when: small
                PropertyChanges {
                    target: rowLayoutComponent
                    visible: false
                }
                PropertyChanges {
                    target: columnLayoutComponent
                    visible: true
                }
            }
        ]

        transitions: Transition {
            ParallelAnimation {
                NumberAnimation {
                    properties: "opacity"
                    duration: 250
                }
            }
        }

        onWidthChanged: {
            var size = rowAccount.implicitWidth + rowSold.implicitWidth + 0.2 * parent.width + 20;

            if (!small && size > parent.width) {
                small = true;
                state = "ColumnLayoutState";
            } else if (small && size < parent.width) {
                small = false;
                state = "RowLayoutState";
            }
        }
    }
}
