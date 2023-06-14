import QtQuick 2.15
import QtQuick.Window
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.15
import SerialPort 1.0

Window {
    id: windows
    visible: true
    width: 400
    height: 300

    SerialPort {
        id: serialPort
    }

    Loader { id: mainLoader }


    RowLayout
    {
        spacing: 0

        Rectangle
        {
            border.width: 1
            Layout.preferredWidth : windows.width/4
            Layout.preferredHeight : windows.height

            ColumnLayout
            {
                anchors.centerIn: parent
                spacing: 10

                Button
                {
                    text: "settings"
                    onClicked:
                    {
                        mainLoader.source = "settings.qml"
                    }
                }
            }
        }
    }
}
