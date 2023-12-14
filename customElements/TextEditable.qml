import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    property bool editing: false
    property bool enebleEditing: true

    Loader {
        id: contentLoader
        anchors.fill: parent
        sourceComponent: (editing && enebleEditing) ? editComponent : textComponent
    }

    Component {
        id: textComponent
        Text {
            id: txt
            text: "default"
            anchors.centerIn: parent
            MouseArea{
                anchors.fill:parent
                onDoubleClicked: editing = true;
            }
        }
    }

    Component {
        id: editComponent
        TextLineEdit {
            id: edit
            anchors.fill:parent
            onAccepted: {
                editing = false
                txt.text = text
            }
        }
    }
}

//Currently not used
