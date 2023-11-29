import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtCharts 2.3
import "../customElements"
import "../js/extract.js" as BDD

Rectangle{
    id:rect
    height: 60
    width: parent.width
    radius:4
    border.color: "grey"

    property variant account
    property bool   chart: false

    AccountTemplate{
        id:template
        account: rect.account
        border.color:"transparent"
        color:"transparent"
        border.width: 0
    }

    ChartView {
        id: graph
        visible: false
        anchors {
            bottom: parent.bottom
            top: template.bottom
            right: parent.right
            left: parent.left
        }

        legend.visible: false

        BarSeries {
            id: soldSeries
            axisX: BarCategoryAxis {
                categories: BDD.generateDateList("2020-01-01", "2020-12-01")
            }

            BarSet {
                id: barSet
                values: if(account) account.getMonthlyEvolution("2020-01-01", "2020-12-01")
            }
        }
    }

    MouseArea{
        anchors.fill:parent
        onClicked: {

            graph.visible = !chart

            chart = !chart
            animParent.to = (chart ? 350 : 60)
            animParent.running = true

            animGraph.to = (chart ? 290 : 0)
            animGraph.running = true
        }
    }

    PropertyAnimation{
        id:animParent
        target: rect
        easing.type: Easing.InQuad
        properties: "height"
        duration:400
    }

    PropertyAnimation{
        id:animGraph
        target: graph
        easing.type: Easing.InQuad
        properties: "height"
        duration:400
    }
}
