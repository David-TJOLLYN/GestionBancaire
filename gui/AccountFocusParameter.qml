import QtQuick 2.15
import QtQuick.Layouts
import QtQuick.Controls
import "../customElements"

Item {
    width: parent.width
    height:parent.height
    property variant account

    StyledText{
        id:info
        anchors.top:parent.top
        anchors.left:parent.left
        anchors.margins:15
        text:"Paramètres du compte"
        color:"#3C6888"
    }

    ColumnLayout{
        anchors.top:info.bottom
        width: 0.8*parent.width
        spacing: 12

        anchors{
            top:info.bottom
            margins:25
            horizontalCenter: parent.horizontalCenter
        }

        Rectangle{
            implicitHeight: 25
            implicitWidth: parent.width
            Text{
                text:"Banque :"
                anchors.left:parent.left
                anchors.verticalCenter: parent.verticalCenter
            }
            ComboBox{
                id:bank
                height: parent.height
                width: 0.75*parent.width
                anchors.right: parent.right
                editable:false
                model:handler.banks
            }
        }

        Rectangle{
            implicitHeight: 25
            implicitWidth: parent.width

            Text{
                text:"Nom :"
                anchors.left:parent.left
                anchors.verticalCenter: parent.verticalCenter
            }
            TextLineEdit{
                id:name
                anchors.right:parent.right
                width: 0.75*parent.width
                height: parent.height
                text:account.name
            }
            Image{
                anchors.right:parent.right
                anchors.margins: 5
                anchors.verticalCenter: parent.verticalCenter
                source: "../icon/modify.png"
                height: 15 ; width: 15
            }
        }

        Rectangle{
            implicitHeight: 25
            implicitWidth: parent.width

            Text{
                text:"Numéro :"
                anchors.left:parent.left
                anchors.verticalCenter: parent.verticalCenter
            }

            Rectangle {
                anchors.right:parent.right
                width: 0.75*parent.width
                height: parent.height

                color:  "white"
                border.color: "#B0B0B0"
                border.width: 1

                TextInput{
                    id: number
                    text: account.number
                    color: "black"

                    anchors.fill: parent
                    anchors.margins: 2
                    verticalAlignment:   TextInput.AlignVCenter

                    onTextChanged: {
                        // Remove non-numeric characters
                        var numericText = checkNumber(text)

                        // Add a space after every four digits
                        var formattedText = numericText.replace(/(.{4})/g, "$1 ");

                        // Update the text property with the formatted text
                        if (formattedText !== text) {
                            text = formattedText.trim(); // Trim to remove the extra space at the end
                        }
                    }
                }

                MouseArea{
                    anchors.fill: parent
                    onClicked: number.forceActiveFocus()
                    onDoubleClicked: number.selectAll()
                }

                Image{
                    anchors.right:parent.right
                    anchors.margins: 5
                    anchors.verticalCenter: parent.verticalCenter
                    source: "../icon/modify.png"
                    height: 15 ; width: 15
                }
            }
        }


        Item{
            implicitHeight: 1
        }

        CustomButton{
            id:btn
            implicitWidth: parent.width/2
            implicitHeight: 25
            Layout.alignment: Qt.AlignHCenter

            onClicked: {
                if(name.text===""){ popup.close(); return; }
                if(sold.text==="")  sold.text = "0.00";
                if(number.text==="") number.text = "xxxx xxxx xxxx"
                handler.addAccount(bank.currentText, name.text, checkSold(sold.text), checkNumber(number.text));
                popup.close()
            }
        }
    }

    function checkNumber(txt){
        return txt.replace(/[^0-9]/g, "");
    }
    function checkSold(inputString) {
        return inputString.replace(",", ".");
    }
}
