import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts

import "../customElements"
import "../js/extract.js" as Extract

Popup {
    id:popup
    anchors.centerIn: parent

    property bool expense: false
    property alias sold: soldValue.text
    property alias account: accountList.currentText
    property alias details: detailsValue.text
    property alias category: categoryList.currentText

    topPadding:  1
    leftPadding: 1
    rightPadding:1

    background: Rectangle{
        color:"#EDEDED"
        anchors.fill: parent
        border.color: "black"
        border.width: 1
    }

    modal:true
    focus:true

    Rectangle{
        id:header
        anchors{
            left:parent.left
            right:parent.right
            top:parent.top
        }

        height: 35
        Layout.fillWidth: true

        RowLayout{
            anchors.fill: parent
            anchors.margins: 4

            spacing:12

            CustomButton{
                Layout.preferredHeight: parent.height
                Layout.preferredWidth:  parent.height+10

                text:  expense ? "- €"     : "+ €"
                color: expense ? "#F70000" : "#70AD47"
                fill:  expense ? "#FF7F7F" : "#B7D6A3"
            }

            Text{
                text:qsTr("Ajouter un"+(expense ? "e dépense" : " revenue"))
                Layout.fillWidth: true

                font.pixelSize: Math.min(parent.height/2+4, parent.height)
                font.underline: true
                color:"black"
            }

            ExitButton{
                id:btn_exitpopup

                Layout.preferredHeight: parent.height
                Layout.preferredWidth:  parent.height+25

                onClicked: popup.visible = false

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
