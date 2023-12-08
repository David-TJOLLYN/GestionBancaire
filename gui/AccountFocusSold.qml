import QtQuick 2.15
import QtCharts 2.3
import "../js/extract.js" as BDD

Item {
    id:page
    width: parent.width
    height:parent.height
    property variant account

    ChartView {
        id: graph
        height:parent.height

        legend.visible: false

        BarSeries {
            id: soldSeries
            axisX: BarCategoryAxis {
                categories: BDD.generateDateList("2019-05-01", "2021-12-01")
            }

            BarSet {
                id: positif
                values: if(account) account.getMonthlyNegativeSold("2019-05-01", "2021-12-01")
            }

            BarSet {
                id: negatif
                values: if(account) account.getMonthlyPositiveSold("2019-05-01", "2021-12-01");
            }
        }
    }
}
