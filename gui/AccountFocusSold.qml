import QtQuick 2.15
import QtCharts 2.3
import "../js/extract.js" as BDD

Item {
    id: page
    width: parent.width
    height: parent.height
    property variant account

    ChartView {
        id: graph
        width: page.width  // Set the width to be larger than the parent
        height: page.height
        legend.visible: false

        MouseArea{
            anchors.fill:parent
            onWheel: event => {
                if (event.angleDelta.x > 0) {
                    graph.scrollLeft(5);
                } else {
                    graph.scrollRight(5)
                }
            }
        }


        StackedBarSeries {
            id: soldSeries
            barWidth:0.3
            axisX: BarCategoryAxis {
                id:x
                categories: BDD.generateDateList("2019-05-01", "2021-12-01")
                labelsAngle: -45
                gridVisible: false
            }

            BarSet {
                id: negatif
                color:"red"

                values: if(account) account.getMonthlyNegativeSold("2019-05-01", "2021-12-01")
            }

            BarSet {
                id: positif
                color: "green"
                values: if(account) account.getMonthlyPositiveSold("2019-05-01", "2021-12-01");
            }

            onAxisYChanged: axisY.visible = false
        }
    }
}
