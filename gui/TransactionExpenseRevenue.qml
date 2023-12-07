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
    property variant account
    property string amount: amountValue.prefix+amountValue.text
    property string details: detailsValue.text
    property string category: categoryList.currentText

    signal closed

    HeaderAndExitBtn{
        id:header
        title: page.title
        onClosed: page.closed()
    }

    TransactionAccountSelected{
        id:info
        account: page.account
        anchors.top:header.bottom
    }

    ColumnLayout{
        implicitWidth: 0.8*parent.width
        spacing: 12

        anchors{
            top: info.bottom
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
            model:handler.categories
        }

        TextLineEdit{
            id: detailsValue
            implicitWidth: parent.width
            implicitHeight: 25

            text: "détails"
        }

        CustomButton{
            implicitWidth: parent.width/2
            implicitHeight: 25
            Layout.alignment: Qt.AlignHCenter

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
