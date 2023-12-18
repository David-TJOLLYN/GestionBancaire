import QtQuick 2.15
import QtQuick.Controls
import QtQuick.Layouts
import "../customElements"
import "../js/extract.js" as JS

Item {
    id: page
    width: parent.width
    height: parent.height

    // Public
    property variant account
    property bool type: true // True : Revenues ; False : Expenses
    property real spacing : 35

    // Private
    property var list: getData(type,account)
    property var xlabels: JS.generateDateList("2019-05-01", "2022-01-01")
    property real absMax: JS.maxAbsoluteValue(list)
    property real size: xlabels.length
    property real focusIndex: size-1
    property real minOpacity: 0.4

    Connections{
        target: account
        function onTransactionsChanged() {
            list = getData(type,account)
            absMax = JS.maxAbsoluteValue(list)
        }
    }

    Rectangle{
        id: frame
        height: 0.35*parent.height
        width: parent.width
        color: "transparent"

        anchors.top:parent.top
        anchors.margins: 10

    Rectangle{
        id:yAxis
        height: parent.height - xAxis.height
        width: 35
        anchors{
            top:parent.top
            left: parent.left
        }

        Text{
            text:"0"
            color:"grey"
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            anchors.rightMargin: 5
        }
    }

    Flickable{
        id:graph
        height:parent.height
        width:parent.width-yAxis.width
        anchors{
            top:parent.top
            left:yAxis.right
        }

        contentWidth: list.length*(spacing+5)
        contentX: Math.max(0, contentWidth - width) //To initialy show the last data

        clip:true
        interactive: false

        MouseArea {
            anchors.fill: parent
            onWheel: event => {
                if (event.angleDelta.x > 0) {
                    scrollBar.decrease()
                } else {
                    scrollBar.increase()
                }
            }
        }

        ScrollBar.horizontal: ScrollBar {
            id: scrollBar
            visible:false
        }


        RowLayout {
            id:up
            anchors.top: parent.top
            height: parent.height-xAxis.height-5-5
            Repeater {
                model: size

                Rectangle {
                    width: spacing
                    height: parent.height
                    color:"transparent"

                    Rectangle{
                        id:dataBarUp
                        width: 10
                        height: Math.abs(list[index])*parent.height/absMax
                        anchors.bottom:parent.bottom
                        color: type ? "green" : "red"
                        opacity: (focusIndex==index) ? 1 : minOpacity
                        radius:5
                        anchors.horizontalCenter: parent.horizontalCenter
                    }

                    MouseArea{
                        anchors.fill:parent
                        onClicked: focusIndex = index
                    }
                }
            }
        }


        Rectangle{
            id:middle
            height:2
            width: parent.width
            color:"grey"
            anchors.top:up.bottom
            anchors.margins: 4
        }

        RowLayout {
            id:xAxis
            anchors.bottom: parent.bottom
            height:30

            Repeater {
                model: size

                Rectangle {
                    width: spacing
                    height: xAxis.height
                    color: "transparent"
                    Layout.alignment: Qt.AlignVCenter

                    Rectangle{
                        height: labelMonth.height+labelYear.height
                        width: labelMonth.width+labelYear.width
                        anchors.centerIn: parent
                        color:"transparent"

                        Text{
                            id:labelMonth
                            anchors.horizontalCenter: parent.horizontalCenter
                            anchors.top:parent.top
                            text: JS.extractMonthToShortString(xlabels[index])
                            font.bold: (focusIndex==index)
                        }

                        Text{
                            id:labelYear
                            anchors.horizontalCenter: parent.horizontalCenter
                            anchors.bottom: parent.bottom
                            text: JS.extractYear(xlabels[index])
                            font.bold: (focusIndex==index)
                        }

                        MouseArea{
                            anchors.fill:parent
                            onClicked: focusIndex = index
                        }
                    }
                }
            }
        }
    }
    }

    function getData(type, account){
        if(account === undefined) return [];
        var list = [];
        if(type) list = account.getMonthlyPositiveSold("2019-05-01", "2021-12-01");
        else     list = account.getMonthlyNegativeSold("2019-05-01", "2021-12-01");
        return list;
    }

}
