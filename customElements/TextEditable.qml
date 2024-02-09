import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    id:itm
    property bool editing: false
    property bool enebleEditing: false
    property string text: "default"
    property color textColor: "grey"
    property real type:0 // 0 : editText , 1 : editFloat , 2 : editDate
    width: parent.width
    height: parent.height
    property bool textAnchorLeft: true
    property bool textAnchorRight: false
    property real textAnchorMargins: 0

    Loader {
        id: contentLoader
        anchors.fill:parent
        sourceComponent: getSourceComponent()
    }

    Component {
        id: textComponent
        Rectangle{
            id:textRect
            width: itm.width
            height: itm.height
            anchors.left: parent.left
            color: "transparent"
            Text {
                id: txt
                text: itm.text
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: if(textAnchorLeft) parent.left
                anchors.right: if(textAnchorRight) parent.right
                anchors.margins: itm.textAnchorMargins
            }
            MouseArea{
                anchors.fill:parent
                onDoubleClicked: editing = true;
            }
        }
    }

    Component {
        id: editTextComponent
        TextLineEdit {
            id: editText
            width: itm.width
            height: itm.height
            anchors.left: parent.left
            defaultText: itm.text
            onAccepted: {
                editing = false
                itm.text = text
            }
        }
    }

    Component {
        id: editFloatComponent
        FloatLineEdit {
            id: editFloat
            width: itm.width
            height: itm.height
            anchors.left: parent.left
            defaultText: formatAmount(itm.text)
            suffix: qsTr("  €")
            onAccepted: {
                editing = false
                itm.text = parseFloat(text.replace(",",".")).toFixed(2) + " €";
            }
        }
    }

    Component {
        id: editDateComponent
        TextLineEdit {
            id: editText
            width: itm.width
            height: itm.height
            anchors.left: parent.left
            defaultText: itm.text
            onAccepted: {
                editing = false
                itm.text = text
            }
        }
    }

    function getSourceComponent(){
        if(!(editing && enebleEditing)) return textComponent

        if(type === 1)      return editFloatComponent
        else if(type === 2) return editDateComponent
        else                return editTextComponent
    }

    function formatAmount(input){
        var str = input.replace(".",",");
        str = str.replace(" €","");
        return str;
    }
}

