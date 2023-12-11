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
    property var posList: [10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180]
    property real absMax: BDD.maxAbsoluteValue(posList)

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
            width: 0.4*parent.width
            height:parent.height
            anchors.left: parent.left
            color:"transparent"
            border.color:"transparent"
            radius:10

            Text{
                anchors.centerIn: parent
                text:"Décembre\n2023"
                font.bold: true
            }
        }

        GridLayout{
            width: 0.6*parent.width
            height:parent.height
            anchors{
                right:parent.right
                top:parent.top
                bottom:parent.bottom
                margins:5
            }

            columns: 2

            Text{
                text:"Dépense"
                Layout.alignment: Qt.AlignLeft
            }

            Text{
                id:expense
                text:"- 214.20 €"
                color:"blue"
                Layout.alignment: Qt.AlignCenter
            }

            Text{
                text:"Revenu"
                Layout.alignment: Qt.AlignLeft
            }

            Text{
                id:revenue
                text:"+ 480.65 €"
                color:"black"
                Layout.alignment: Qt.AlignCenter
            }

            Text{
                id:txt
                text:"Différence"
                Layout.alignment: Qt.AlignLeft
            }

            Rectangle{
                radius:10
                width: sold.width+15
                height:sold.height+2
                color:"green"
                Layout.alignment: Qt.AlignCenter
                Text{
                    id:sold
                    anchors.centerIn: parent
                    text:"+ 214.20 €"
                    color:"white"
                }
            }
        }
    }

    Rectangle{
        id:yAxis
        height:parent.height-20-info.height - xAxis.height
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

        contentWidth: posList.length*30

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
                    width: 25
                    height: modelData*parent.height/absMax
                    Layout.alignment: Qt.AlignBottom

                    Rectangle{
                        height:parent.height
                        width: 10
                        color:"green"
                        radius:5
                        anchors.horizontalCenter: parent.horizontalCenter
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
                model: page.posList

                Rectangle {
                    width: 25
                    height: modelData*parent.height/absMax
                    Layout.alignment: Qt.AlignTop

                    Rectangle{
                        height:parent.height
                        width: 10
                        color:"red"
                        radius:5
                        anchors.horizontalCenter: parent.horizontalCenter
                    }
                }
            }
        }

        RowLayout {
            id:xAxis
            anchors.bottom:parent.bottom
            height:40

            Repeater {
                model: page.posList

                Rectangle {
                    width: 25
                    height:20
                    Layout.alignment: Qt.AlignVCenter

                    Text{
                        text:modelData
                        color:"black"
                        anchors.centerIn:parent
                    }
                }
            }
        }
    }
}
