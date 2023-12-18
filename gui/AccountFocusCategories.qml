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
    property var dataGroupedByCategories: account.getSoldGroupByCategories(JS.format2db(xlabels[focusIndex]), (type ? 0 : 1))
    property var list: getData(type,account)
    property var xlabels: JS.generateDateList("2019-05-01", "2022-01-01")
    property real absMax: JS.maxAbsoluteValue(list)
    property real size: xlabels.length
    property real focusIndex: size-1
    property real minOpacity: 0.4

    onFocusIndexChanged:{
        dataGroupedByCategories = account.getSoldGroupByCategories(JS.format2db(xlabels[focusIndex]), (type ? 0 : 1))
    }

    Connections{
        target: account
        function onTransactionsChanged() {
            list = getData(type,account)
            absMax = JS.maxAbsoluteValue(list)
            listview.model = account.getSoldGroupByCategories(JS.format2db(xlabels[focusIndex]))
        }
    }

    onSizeChanged: console.log("new size ",size)

    Rectangle{
        id: frame
        height: 0.35*parent.height
        width: parent.width
        color: "transparent"

        anchors.top:parent.top
        anchors.margins: 10

        Rectangle{
            id:yAxis
            height: frame.height - 28
            width: 35
            color:"transparent"
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

        Component{
            id:dataform
            Item{
                height:datalv.height
                width: spacing

                Rectangle {
                    id: data
                    width: spacing
                    height: datalv.height - xAxis.height - 10
                    color:"transparent"

                    Rectangle{
                        id:dataBarUp
                        width: 10
                        height: list[index] ? Math.abs(list[index])*parent.height/absMax : 1
                        anchors.bottom:parent.bottom
                        anchors.horizontalCenter: parent.horizontalCenter

                        color: type ? "green" : "red"
                        opacity: (focusIndex==index) ? 1 : minOpacity
                        radius:5
                    }
                }

                Rectangle{
                    id:middle
                    height:2
                    width: spacing
                    anchors.top: data.bottom
                    anchors.margins: 4
                    color:"grey"
                }

                Rectangle {
                    id:xAxis
                    width: spacing
                    height: 30
                    anchors.top:middle.bottom
                    anchors.margins: 4
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
                    }
                }

                MouseArea{
                    anchors.fill:parent
                    onClicked: focusIndex = index
                }
            }
        }

        ListView{
            id:datalv
            height:frame.height
            width: frame.width-yAxis.width - 25
            anchors.top:frame.top
            anchors.left:yAxis.right
            orientation: ListView.Horizontal
            boundsMovement: Flickable.StopAtBounds

            clip:true
            model:32
            delegate: dataform
        }
    }

    Component{
        id:categoryform

        Rectangle{
            width:  listview.width
            height: 35
            radius: 5
            color: "burlywood"
            border.color: "peru"
            border.width: 2

            Rectangle{
                id: img
                width:  parent.height-10
                height: parent.height-10
                anchors{
                    left:parent.left
                    margins:10
                    verticalCenter: parent.verticalCenter
                }
                color: "cornsilk"
                radius:5
            }

            Rectangle{
                id: name
                width: 0.6*parent.width - img.width - 20
                height:parent.height
                anchors{
                    left:img.right
                    margins:10
                }
                color:"transparent"

                StyledText{
                    text:modelData
                    anchors.left:parent.left
                    anchors.verticalCenter: parent.verticalCenter
                    color:"white"
                    font.bold:true
                }
            }

            Rectangle{
                width: 0.4*parent.width
                height: parent.height
                anchors.right:parent.right
                color: "transparent"
                radius: 5

                StyledText{
                    text:num2money(dataGroupedByCategories[modelData])
                    anchors.right:parent.right
                    anchors.margins:10
                    anchors.verticalCenter: parent.verticalCenter
                    color:"white"
                    font.bold:true
                }
            }
        }
    }

    ListView{
        id:listview
        width: parent.width-20
        height: parent.height - frame.height - 40
        spacing:10
        clip:true
        anchors{
            top:frame.bottom
            left:parent.left
            right:parent.right
            margins: 10
            topMargin: 20
        }
        boundsMovement: Flickable.StopAtBounds

        model: Object.keys(dataGroupedByCategories)
        delegate: categoryform
    }

    function getData(type, account){
        if(account === undefined) return [];
        var list = [];
        if(type) list = account.getMonthlyPositiveSold("2019-05-01", "2021-12-01");
        else     list = account.getMonthlyNegativeSold("2019-05-01", "2021-12-01");
        return list;
    }

    function num2money(number){
        if(isNaN(number)) return "+ 0.00 €";
        var str = number>= 0 ? "+ " : "- ";
        str += Math.abs(number).toFixed(2);
        return str += " €";
    }
}
