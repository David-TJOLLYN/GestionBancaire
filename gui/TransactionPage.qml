import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts
import "../customElements"
import "../Settings.js" as Setting

Item {
    id:page
    signal openPopup
    property real type: 0

    width: parent.width
    height:parent.height

    Header{
        id:header
        text:qsTr("Transactions")
    }

    ColumnLayout {
        anchors {
            top: header.bottom
            horizontalCenter: parent.horizontalCenter
            margins: 15
        }
        height: modelList.count*(50+10)

        Repeater {
            model: modelList.count
            Item {
                Layout.alignment: Qt.AlignCenter

                Rectangle {
                    id:rect
                    anchors.centerIn: parent

                    width:  0.9 * page.width
                    height: 50
                    radius: 5

                    color: Setting.fillColor
                    border.color: Setting.strokeColor
                    border.width: 2

                    StyledText {
                        text: modelList.get(index).name
                        color: "white"
                        anchors{
                            verticalCenter: parent.verticalCenter
                            left: parent.left
                            leftMargin: 10
                        }
                    }

                    MouseArea{
                        anchors.fill:parent
                        onClicked:{
                            type = modelList.get(index).type
                            openPopup()
                        }
                    }
                }
            }
        }
    }

    ListModel {
        id: modelList
        ListElement { type: 0; name: qsTr("Virement interne") }
        ListElement { type: 1; name: qsTr("Ajouter un revenu") }
        ListElement { type: 2; name: qsTr("Ajouter une dépense") }
    }
}
