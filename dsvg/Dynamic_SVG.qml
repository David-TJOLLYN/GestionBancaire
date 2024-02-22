import QtQuick

Image {
    id:itm

    property bool filled: false
    fillMode: Image.PreserveAspectFit // Preserve aspect ratio

    property color strokeColor: "#3c6c8c"
    property color fillColor:   "#9bd3e3"
    property color emptyColor:  "#FFFFFF"

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
