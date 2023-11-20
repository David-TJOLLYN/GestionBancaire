import QtQuick 2.15
import QtQuick.Layouts 1.15

Item {
    id:homePage
    focus: false
    Layout.fillWidth: true
    Layout.fillHeight: true


    onVisibleChanged: {
        console.log("HomePage visible",visible)
    }

    Rectangle{
        width : homePage.width
        height: homePage.height
        color:  homePage.focus ? "cyan" : "yellow"
    }
}
