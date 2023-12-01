import QtQuick 2.15
import "../customElements"
import "../js/extract.js" as BDD

Item {
    id:page
    width:parent.width
    height:parent.height

    property string title: "Default"
    property variant debitAccount
    property variant creditAccount

    signal closed
    signal forceActiveFocus


    HeaderAndExitBtn{
        id:header
        title: page.title
        onClosed: page.closed()
    }

    TransactionAccountSelected{
        id:info
        account: page.debitAccount
        anchors.top:header.bottom
    }

    Rectangle{
        id:creditAccountInfo
        height: 50
        width: 0.95*parent.width
        color: "#98D7E5"
        anchors{
            horizontalCenter: parent.horizontalCenter
            top:info.bottom
            margins:5
        }
        radius:15

        StyledText{
            anchors{
                left:parent.left
                verticalCenter: parent.verticalCenter
                margins:10
            }
            text: creditAccount ? creditAccount.name : "Default"
            color:"white"
        }

        StyledText{
            anchors{
                right:parent.right
                verticalCenter: parent.verticalCenter
                margins:10
            }
            text: creditAccount ? creditAccount.sold.toFixed(2)+" €" : "N/A €"
            color:"white"
            font.bold: true
        }
    }

    onForceActiveFocus:{
        sold.text=""
        sold.forceActiveFocus()
    }

    FloatLineEdit{
        id:sold
        height: 25
        width: 0.95*parent.width-30
        anchors{
            horizontalCenter: parent.horizontalCenter
            top:creditAccountInfo.bottom
            margins:20
        }
        suffix: "  €"
        text: "0.00"
    }

    Rectangle{
        width: parent.width/2
        height: 25
        anchors{
            horizontalCenter: parent.horizontalCenter
            top:sold.bottom
            margins:20
        }
        radius: 25
        color: "#3C6888"

        StyledText{
            text:"valider"
            color:"white"
            anchors.centerIn: parent
        }

        MouseArea{
            id:mouseare
            anchors.fill:parent
            onClicked: {
                handleTransaction()
            }
        }
    }

    Keys.onReturnPressed: handleTransaction()

    function handleTransaction(){
        if(sold.text === ""){
            page.closed()
            return;
        }
        page.creditAccount.addTransaction("+"+check(sold.text),BDD.date(),"Internal","")
        page.debitAccount.addTransaction("-"+check(sold.text),BDD.date(),"Internal","")
        page.closed()
    }

    function check(inputString) {
        return inputString.replace(",", ".");
    }
}
