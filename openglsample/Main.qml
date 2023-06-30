import QtQuick
import QtQuick.Window

Window {
    id: mainWindow
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle {
        id: glWindow
        width: mainWindow.width
        height: mainWindow.height


        onBeforeRendering: {
            TriangleWindow.render();
        }
    }
}
