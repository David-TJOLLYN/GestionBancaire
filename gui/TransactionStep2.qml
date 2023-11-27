import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts

import "../customElements"
import "../js/extract.js" as BDD

Item {
    id:page

    width:parent.width
    height:parent.height
    property string title: "Default"

    property bool expense: false
    property string sold: soldValue.prefix+soldValue.text
    property string account: accountList.currentText
    property string details: detailsValue.text
    property string category: categoryList.currentText

    Rectangle{
        id:header
        color:"#3C6888"
        height: 60
        width:  parent.width

        anchors.top:parent.top

        RowLayout{
            anchors.fill: parent
            anchors.margins: 4
            spacing:10

            ExitButton{
                onClicked: popup.visible = false
            }

            StyledText{
                text: page.title
                Layout.fillWidth: true
                color:"white"
            }
        }
    }

    ColumnLayout{
        width: parent.width
        height: parent.height - header.height
        anchors{
            margins: 10
            top:header.bottom
        }

        spacing:5

        RowLayout{

            Layout.preferredHeight: parent.height/7
            Layout.preferredWidth:  parent.width/2
            spacing:5

            ComboBox{
                id:accountList
                Layout.preferredHeight: parent.height
                Layout.preferredWidth:  parent.width/2

                editable:false
                model: BDD.extractNames(accounts)
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
                BDD.addTransaction(accounts,account,check(sold),category,details)
            }

            function check(inputString) {
                return inputString.replace(",", ".");
            }
        }
    }
}
