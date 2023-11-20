import QtQuick 2.15

Item {
    property string icon: ""
    property string iconfocus: ""
    signal clicked

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
        console.log(focus, image.source)
    }
}
