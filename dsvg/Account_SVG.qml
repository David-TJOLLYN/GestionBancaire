import QtQuick

Item {
    property real ratio: 1.6 // ratio width/height
    property string viewbox: "viewBox='0 0 200 125'"
    property string paths:
        "<rect style='stroke-width: 6px;' x='5' y='5' width='190' height='115'/>
        <rect style='stroke-width: 5px;' x='33.562' y='26.795' width='37.802' height='26.171' rx='3' ry='3'/>
        <path style='stroke-width: 5px;' d='M 95.457 35.934 L 171.06 35.934'/>
        <path style='stroke-width: 4px;' d='M 37 80.382 L 61.093 80.382'/>
        <path style='stroke-width: 4px;' d='M 37 97.829 L 124.234 96.998'/>
        <path style='stroke-width: 4px;' d='M 70.332 80.797 L 94.425 80.797'/>
        <path style='stroke-width: 4px;' d='M 103.664 80.658 L 127.757 80.658'/>
        <path style='stroke-width: 4px;' d='M 136.997 80.52 L 161.09 80.52'/>"
}
