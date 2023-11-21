import QtQuick 2.15
import QtQuick.Layouts 1.15
import "../customElements"
import "../js/extract.js" as BDD

Item {
    id: homePage
    focus: false

    property color color: "#3C6888"
    property string font: "Comic Sans MS"
    property real px: 15
    property bool small: false
    property variant account : accounts[0]

    Rectangle {
        id: frame

        height: 200
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

        ColumnLayout{
            anchors.fill:parent

            RowLayout {
                id: rowLayoutComponent
                Layout.margins:10
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignTop

                StyledText {
                    id: rowAccount
                    text: account.name
                }

                Item { Layout.fillWidth: true }

                StyledText {
                    id: rowSold
                    text: qsTr(account.sold.toFixed(2)+" €")
                }
            }

            ColumnLayout {
                id: columnLayoutComponent
                Layout.margins:10
                Layout.preferredWidth: parent.width
                Layout.alignment: Qt.AlignTop

                StyledText { text: account.name }
                StyledText { text: qsTr(account.sold.toFixed(2)+" €")
                    Layout.alignment: Qt.AlignRight
                }
            }

            Rectangle{
                Layout.preferredWidth: parent.width
                height:1
                color:homePage.color
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
