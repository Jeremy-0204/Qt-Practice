import QtQuick 2.15
import QtQuick.Window 2.15
import OpenGLTriangleItem 1.0

Window {
    visible: true
    width: 400
    height: 400

    OpenGLTriangleItem {
        anchors.fill: parent
    }
}
