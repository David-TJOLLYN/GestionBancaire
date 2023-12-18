import QtQuick 2.15
import QtCharts 2.3
import QtQuick.Layouts
import QtQuick.Controls
import "../js/extract.js" as BDD

Item {
    id: page
    width: parent.width
    height: parent.height
    property variant account
    property real spacing : 35

    //Private
    property var posList: if(account) account.getMonthlyPositiveSold("2019-05-01", "2021-12-01")
    property var negList: if(account) account.getMonthlyNegativeSold("2019-05-01", "2021-12-01")
    property real difference: if(account) posList[focusIndex]+negList[focusIndex]
    property var xlabels: BDD.generateDateList("2019-05-01", "2022-01-01")
    property real absMax: Math.max(BDD.maxAbsoluteValue(posList),BDD.maxAbsoluteValue(negList))
    property real focusIndex: xlabels.length-1
    property real minOpacity: 0.4

    Connections{
        target: account
        function onTransactionsChanged() {
            posList = account.getMonthlyPositiveSold("2019-05-01", "2021-12-01")
            negList = account.getMonthlyNegativeSold("2019-05-01", "2021-12-01")
        }
    }

    Rectangle{
        id:info
        anchors.top:parent.top
        anchors.margins: 10
        anchors.horizontalCenter: parent.horizontalCenter
        radius:10
        width: 0.9*parent.width
        height:70
        border.color:"grey"


        Rectangle{
            width: 0.5*parent.width
            height:parent.height
            anchors.left: parent.left
            color:"transparent"
            border.color:"transparent"
            radius:10

            Rectangle{
                height: infoMonth.height+infoYear.height
                width: infoMonth.width+infoYear.width
                anchors.centerIn: parent

                Text{
                    id:infoMonth
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.top:parent.top
                    text: extractMonthToLongString(xlabels[focusIndex])
                    font.bold: true
                }

                Text{
                    id:infoYear
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.bottom: parent.bottom
                    text: "20"+extractYear(xlabels[focusIndex])
                    font.bold: true
                }
            }
        }

        GridLayout{
            width: 0.5*parent.width
            height:parent.height
            anchors{
                right:parent.right
                top:parent.top
                bottom:parent.bottom
                margins:5
                rightMargin: 20
            }

            columns: 2

            Text{
                text:"Dépense"
                Layout.alignment: Qt.AlignLeft
            }

            Text{
                id: expense
                text: num2money(negList[focusIndex])
                color: "blue"
                Layout.alignment: Qt.AlignRight
            }

            Text{
                text:"Revenu"
                Layout.alignment: Qt.AlignLeft
            }

            Text{
                id: revenue
                text: num2money(posList[focusIndex])
                color: "black"
                Layout.alignment: Qt.AlignRight
            }

            Text{
                id:txt
                text:"Différence"
                Layout.alignment: Qt.AlignLeft
            }

            Rectangle{
                radius:10
                width: 80
                height: 20
                color: difference ? ((difference>=0) ? "green" : "red") : "green"
                Layout.alignment: Qt.AlignRight

                Text{
                    id:sold
                    anchors.centerIn: parent
                    text: num2money(difference)
                    color:"white"
                    font.bold: true
                }
            }
        }
    }

    Rectangle{
        id:yAxis
        height:parent.height-20-info.height - xAxis.height-5
        width: 35
        anchors{
            top:info.bottom
            left: parent.left
            topMargin: 10
        }

        //border.color:"green"

        Text{
            text:"0"
            color:"grey"
            anchors.right: parent.right
            anchors.margins:5
            anchors.verticalCenter: parent.verticalCenter
        }
    }

    Flickable{
        id:graph
        height:parent.height - 20 - info.height
        width:parent.width-yAxis.width-15
        anchors{
            top:info.bottom
            left:yAxis.right
            topMargin: 10
        }

        contentWidth: posList.length*(spacing+5)
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
            height: (parent.height-xAxis.height)/2-5
            Repeater {
                model: page.posList

                Rectangle {
                    width: spacing
                    height: parent.height

                    Rectangle{
                        id:dataBarUp
                        width: 10
                        height: modelData*parent.height/absMax
                        anchors.bottom:parent.bottom
                        color: "green"
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
            anchors.bottom: down.top
            anchors.margins: 4
        }

        RowLayout {
            id:down
            anchors.bottom: xAxis.top
            height: (parent.height-xAxis.height)/2-5
            Repeater {
                model: page.negList

                Rectangle {
                    width: spacing
                    height: parent.height
                    Layout.alignment: Qt.AlignTop

                    Rectangle{
                        width: 10
                        height: -1*modelData*parent.height/absMax
                        anchors.top:parent.top
                        color:"red"
                        radius:5
                        opacity: (focusIndex == index) ? 1 : minOpacity
                        anchors.horizontalCenter: parent.horizontalCenter
                    }

                    MouseArea{
                        anchors.fill:parent
                        onClicked: focusIndex = index
                    }
                }
            }
        }

        RowLayout {
            id:xAxis
            anchors.bottom:parent.bottom
            height:40

            Repeater {
                model: page.xlabels

                Rectangle {
                    width: spacing
                    height:20
                    Layout.alignment: Qt.AlignVCenter

                    Rectangle{
                        height: labelMonth.height+labelYear.height
                        width: labelMonth.width+labelYear.width
                        anchors.centerIn: parent

                        Text{
                            id:labelMonth
                            anchors.horizontalCenter: parent.horizontalCenter
                            anchors.top:parent.top
                            text: extractMonthToShortString(modelData)
                            font.bold: (focusIndex==index)
                        }

                        Text{
                            id:labelYear
                            anchors.horizontalCenter: parent.horizontalCenter
                            anchors.bottom: parent.bottom
                            text: extractYear(modelData)
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

    // Assuming inputDate is in the format "MM/YYYY"

    function extractMonthToLongString(inputDate) {
        var monthNames =["Janvier", "Février", "Mars", "Avril", "Mai", "Juin", "Juillet", "Août", "Septembre", "Octobre", "Novembre", "Décembre"];
        return monthNames[parseInt(inputDate.split('/')[0])-1];
    }

    function extractYear(inputDate){
        return inputDate.split('/')[1]
    }

    function extractMonthToShortString(inputDate) {
        var monthNames =["jan.", "fév.", "mars", "avr.", "mai", "juin", "juil.", "août", "sept.", "oct.", "nov.", "dec."];
        return monthNames[parseInt(inputDate.split('/')[0])-1];
    }

    function num2money(number){
        if(isNaN(number)) return "+ 0.00 €";
        var str = number>= 0 ? "+ " : "- ";
        str += Math.abs(number).toFixed(2);
        return str += " €";
    }
}
