import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import "../customElements"
import "../js/extract.js" as BDD

Item {
    id:page
    width:parent.width
    height:parent.height

    property string title: "Default"
    property bool expense: false
    property var account
    property string amount: amountValue.prefix+amountValue.text
    property string details: detailsValue.text
    property string category: categoryList.currentText

    signal closed

    HeaderAndExitBtn{
        id:header
        title: page.title
        onClosed: page.closed()
    }

    Rectangle {
        id:info
        anchors.top:header.bottom
        width: parent.width
        height: 60

        color: "#98D7E5"

        StyledText {
            anchors{
                verticalCenter: parent.verticalCenter
                left: parent.left
                margins:10
            }
            text: page.account ? page.account.name : "default"
            color:"white"
        }

        StyledText {
            anchors{
                verticalCenter: parent.verticalCenter
                right: parent.right
                margins:10
            }
            text: page.account ? page.account.sold.toFixed(2)+" €" : "N/A €"
            font.bold: true
            color:"white"
        }
    }
    Rectangle {
        id: clipper
        anchors.top:info.bottom
        width: parent.width
        height: clipped.radius
        color: 'transparent'
        clip: true

        Rectangle {
            id: clipped
            width: parent.width
            height: parent.height + radius
            y:-radius
            radius: 15
            color: "#98D7E5"
        }
    }



    ColumnLayout{
        implicitWidth: 0.8*parent.width
        spacing: 12

        anchors{
            top: clipper.bottom
            horizontalCenter: parent.horizontalCenter
            margins:25
        }

        FloatLineEdit{
            id: amountValue
            implicitWidth: parent.width
            implicitHeight: 25

            prefix: (expense ? "-" : "+")
            suffix: "  €"
            text: "0.00"
        }

        ComboBox{
            id:categoryList
            Layout.preferredWidth:  parent.width
            Layout.preferredHeight: 25
            editable:false
            model:list_categories
        }

        TextLineEdit{
            id: detailsValue
            implicitWidth: parent.width
            implicitHeight: 25
            text: "détails"
        }

        Rectangle{
            implicitWidth: parent.width/2
            implicitHeight: 25
            Layout.alignment: Qt.AlignHCenter
            radius: 25
            color: "#3C6888"

            StyledText{
                text:"valider"
                color:"white"
                anchors.centerIn: parent
            }

            MouseArea{
                anchors.fill:parent
                onClicked: {
                    page.account.addTransaction(check(amount),BDD.date(),category,details)
                    page.closed()
                }

                function check(inputString) {
                    return inputString.replace(",", ".");
                }
            }
        }
    }
}
