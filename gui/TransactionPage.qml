import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts
import "../customElements"

Item {
    id:page
    signal openExpensePopup
    signal openRevenuPopup
    signal openInternalPopup

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

                    MouseArea{
                        anchors.fill:parent
                        onClicked:{
                            var nbr = modelList.get(index).type
                            if(nbr === 0){
                                openInternalPopup()
                            }
                            if(nbr === 1){
                                openRevenuPopup()
                            }
                            if(nbr === 2){
                                openExpensePopup()
                            }

                            console.log(modelList.get(index).name, nbr)
                        }
                    }
                }
            }
        }
    }

    ListModel {
        id: modelList
        ListElement { type: 0; name: "Virement interne" }
        ListElement { type: 1; name: "Ajouter un revenu" }
        ListElement { type: 2; name: "Ajouter une dépense" }
    }
}
