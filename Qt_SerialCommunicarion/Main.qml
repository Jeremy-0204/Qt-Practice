import QtQuick
import QtQuick.Window
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 400
    height: 300
    title: "Serial Communication Example"

    Column {
        anchors.centerIn: parent
        spacing: 10

        Text {
            text: "Serial Port Settings"
            font.pixelSize: 16
        }

        ComboBox {
            id: portComboBox
            width: 200
            model: SerialPortInfo
            displayText: "Select Port"
        }

        Button {
            text: "Open Port"
            onClicked: {
                if (portComboBox.currentIndex !== -1) {
                    var portInfo = portComboBox.currentText
                    serialPort.setPort(portInfo)
                    if (serialPort.open(QIODevice.ReadWrite)) {
                        console.log("Port opened:", portInfo)
                    } else {
                        console.error("Failed to open port:", portInfo)
                    }
                }
            }
        }

        Button {
            text: "Close Port"
            onClicked: {
                if (serialPort.isOpen) {
                    serialPort.close()
                    console.log("Port closed")
                }
            }
        }
    }
}
