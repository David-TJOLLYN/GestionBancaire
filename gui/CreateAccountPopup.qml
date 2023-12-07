import QtQuick 2.15
import QtQuick.Controls
import QtQuick.Layouts
import "../customElements"

Popup {
    id:popup
    width:parent.width
    height: parent.height
    modal: true
    focus: true
    padding:0

    background: Rectangle{
        anchors.fill:parent
        color:"white"
    }

    HeaderAndExitBtn{
        id:header
        title:"Créer un Compte / Livret"
        anchors.top:parent.top
        onClosed: popup.close()
    }

    ColumnLayout{
        width: 0.8*parent.width
        spacing: 12

        anchors{
            top:header.bottom
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
                text:""

                //Setup next focus
                KeyNavigation.tab: number
                Keys.onReturnPressed: KeyNavigation.tab.forceActiveFocus();
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
                    text: ""
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

                    //Setup next focus
                    KeyNavigation.tab: btn
                    Keys.onReturnPressed: KeyNavigation.tab.forceActiveFocus();
                    Keys.onTabPressed: KeyNavigation.tab.forceActiveFocus();
                }

                MouseArea{
                    anchors.fill: parent
                    onClicked: number.forceActiveFocus()
                    onDoubleClicked: number.selectAll()
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
                if(number.text==="") number.text = "xxxx xxxx xxxx"
                handler.addAccount(name.text, checkNumber(number.text), bank.currentText, 0);
                popup.close()
            }
        }
    }


    enter: Transition {
        NumberAnimation{
            property: "y"
            from: parent.height ; to:0
            duration: 350
            easing.type: Easing.OutQuad
        }
    }

    exit: Transition{
        NumberAnimation {
            property: "y"
            from: 0 ; to: parent.height
            duration: 250
            easing.type: Easing.InOutQuad
        }
    }

    onOpened:{
        name.text = ""
        number.text = ""
        name.forceActiveFocus()
    }

    function checkNumber(txt){
        return txt.replace(/[^0-9]/g, "");
    }
}
