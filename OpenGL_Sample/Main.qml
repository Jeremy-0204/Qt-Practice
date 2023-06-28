import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Shapes 1.15
import QtQuick.Window 2.15

Window {
    visible: true
    width: 400
    height: 400
    title: "OpenGL Triangle"

    Canvas {
        id: canvas
        anchors.fill: parent

        onPaint: {
            var ctx = getContext("2d");
            if (ctx) {
                ctx.clearRect(0, 0, width, height);
                ctx.strokeStyle = "red";
                ctx.beginPath();
                ctx.moveTo(100, 100);
                ctx.lineTo(300, 100);
                ctx.lineTo(200, 300);
                ctx.closePath();
                ctx.stroke();
            }
        }
    }
}
