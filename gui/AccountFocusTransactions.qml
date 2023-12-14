import QtQuick 2.15
import QtQuick.Controls
import QtQuick.Layouts
import "../customElements"

Item {
    id: root
    width: parent.width
    height: parent.height

    property variant account
    property real focusIndex: -1

    Component {
        id: transactionsModel

        Item {
            width: parent ? parent.width : 200
            height: info.height+10
            property var k: modelData
            property bool options: (focusIndex === index)

            MouseArea {
                anchors.fill: parent
                onDoubleClicked: if(focusIndex!==index) focusIndex = index;
            }

            TransactionForm {
                id: info
                transaction: parent.k
                anchors.verticalCenter: parent.verticalCenter
            }


            Rectangle {
                anchors.left: info.right
                anchors.margins: 5
                height: parent.height
                width: 1
                color: "lightgrey"
                visible: options
            }

            Rectangle {
                id: actionsRectangle
                width: 0
                height: parent.height
                anchors.left: info.right
                anchors.margins: 5
                color:"transparent"

                Rectangle{
                    width:50
                    height:parent.height
                    anchors.centerIn: parent
                    visible: parent.width>=width
                    color:"transparent"

                    Rectangle{
                        id:edit
                        width:parent.height/2
                        height:parent.height/2
                        anchors.left:parent.left
                        anchors.margins: 5
                        anchors.verticalCenter: parent.verticalCenter
                        color:"blue"
                    }

                    Rectangle{
                        id:supp
                        width:parent.height/2
                        height:parent.height/2
                        anchors.left: edit.right
                        anchors.margins: 5
                        anchors.verticalCenter: parent.verticalCenter
                        color:"red"
                        MouseArea{
                            anchors.fill:parent
                            onClicked:{
                                focusIndex = -1
                                account.deleteTransaction(k.id)
                            }
                        }
                    }
                }
            }

            Rectangle {
                anchors.top: parent.bottom
                width: parent.width
                height: 1
                color: "lightgrey"
                radius: 2
            }

            onOptionsChanged: showActions.restart()

            ParallelAnimation {
                id: showActions

                PropertyAnimation {
                    target: actionsRectangle
                    property: "width"
                    to: (options ? 65 : 0) - 10
                    duration: 500
                    easing.type: Easing.Linear
                }

                PropertyAnimation {
                    target: info
                    property: "width"
                    to: (options ? root.width - 65 : root.width - 10) -10
                    duration: 500
                    easing.type: Easing.Linear
                }
            }
        }
    }

    ListView {
        id: list
        width: parent.width
        height: parent.height
        model: account.transactions
        delegate: transactionsModel

        Connections {
            target: account
            function onTransactionsChanged() {
                list.model = account.transactions
            }
        }

        clip: true
        spacing: 0
        topMargin: 10
        leftMargin: 10
        rightMargin: 10
        bottomMargin: 10
        boundsMovement: Flickable.StopAtBounds
    }
}
