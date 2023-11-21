import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts
import "../customElements"

Item {
    id:page

    ColumnLayout {
        anchors {
            top: parent.top
            horizontalCenter: parent.horizontalCenter
            margins: 0.06 * parent.width
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

                    color: "#98D7E5"
                    border.color: "#3C6888"
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
                }
            }
        }
    }

    ListModel {
        id: modelList
        ListElement { name: "Virement interne" }
        ListElement { name: "Ajouter un revenu" }
        ListElement { name: "Ajouter une dépense" }
    }
}
