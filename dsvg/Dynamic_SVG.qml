import QtQuick
import "../Settings.js" as Setting

Image {
    id:itm

    property bool filled: false
    fillMode: Image.PreserveAspectFit // Preserve aspect ratio

    property color strokeColor: Setting.strokeColor
    property color fillColor:   Setting.fillColor
    property color emptyColor:  Setting.emptyColor

    property Item svgComponent

    //Private variable
    property color bufferFillColor: emptyColor

    property string svg:
        "<svg "+svgComponent.viewbox+">
            <g stroke='"+strokeColor+"' fill='"+bufferFillColor+"' style='stroke-linejoin: round; stroke-linecap: round;'>
                "+svgComponent.paths+"
            </g>
        </svg>"

    source: "data:image/svg+xml," + encodeURIComponent(svg)

    onFilledChanged: bufferFillColor = filled ? fillColor : emptyColor


    function fill(){
        itm.filled = true;
    }

    function empty(){
        itm.filled = false;
    }

    function togglefill(){
        itm.filled = !itm.filled;
    }
}
