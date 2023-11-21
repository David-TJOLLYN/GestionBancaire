import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts

import "../customElements"
import "../js/extract.js" as Extract

Popup {
    id:popup

    property bool expense: false
    property alias sold: soldValue.text
    property alias account: accountList.currentText
    property alias details: detailsValue.text
    property alias category: categoryList.currentText

    topPadding:  0
    leftPadding: 0
    rightPadding:0

    background: Rectangle{
        color:"white"
        anchors.fill: parent
    }

    modal:true
    focus:true

    Rectangle{
        id:header
        color:"#3C6888"
        height: 60
        width:  parent.width

        anchors{
            left:parent.left
            right:parent.right
            top:parent.top
        }

        RowLayout{
            anchors.fill: parent
            anchors.margins: 4

            spacing:10
            Rectangle{
                width: parent.height/2
                height:parent.height/2
                color:"transparent"
                StyledText{
                    anchors.centerIn: parent
                    text:"X"
                    color:"white"
                }
                MouseArea{
                    anchors.fill:parent
                    onClicked: popup.visible = false
                }

            }

            StyledText{
                text:qsTr("Ajouter un"+(expense ? "e dépense" : " revenu"))
                Layout.fillWidth: true
                color:"white"
            }
        }
    }

    ColumnLayout{
        anchors{
            margins: 10
            left:parent.left
            right:parent.right
            top:header.bottom
        }
        height:6*parent.height/7-10
        Layout.fillWidth: true

        spacing:5

        RowLayout{

            Layout.preferredHeight: parent.height/7
            Layout.preferredWidth:  parent.width
            spacing:5

            ComboBox{
                id:accountList
                Layout.preferredHeight: parent.height
                Layout.preferredWidth:  parent.width/2

                editable:false
                model: Extract.extractNames(accounts)
            }

            FloatLineEdit {
                id:soldValue
                Layout.preferredHeight: parent.height
                Layout.fillWidth: true

                prefix: (expense ? "-" : "+")
                suffix: "€"
                text: "0.00"
            }
        }

        ComboBox{
            id:categoryList
            Layout.preferredHeight: parent.height/7
            Layout.preferredWidth:  parent.width

            editable:false
            model:list_categories
        }

        Text {
            id: lablel
            Layout.preferredHeight: parent.height/7
            Layout.fillWidth: true
            text: qsTr("Details :")
            color:"black"
            font.underline: true
        }

        TextLineEdit{
            id:detailsValue
            Layout.preferredHeight: parent.height/7
            Layout.preferredWidth:  parent.width
        }

        CustomButton{
            Layout.preferredHeight: parent.height/7
            Layout.preferredWidth:  parent.width/3

            text: "OK"
            color: "#70AD47"
            fill:  "#B7D6A3"

            Layout.alignment: Qt.AlignCenter

            onClicked: {
                popup.visible = false
                Extract.getAccount(accounts,account).addTransaction(expense,sold,category,details)
            }
        }
    }


    closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutsideParent

}
