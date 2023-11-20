import QtQuick 2.15
import QtQuick.Layouts

Item {
    property string icon: ""
    property string iconfocus: ""
    signal clicked

    Layout.preferredHeight: parent.height
    Layout.preferredWidth: parent.width/3

    Image{
        id:image
        anchors.fill: parent
        fillMode: Image.PreserveAspectFit
    }

    MouseArea{
        anchors.fill:parent
        onClicked: {
            parent.focus = !parent.focus
            parent.clicked()
        }
    }

    onFocusChanged: {
        image.source = focus ? iconfocus : icon
    }
}
