import QtQuick
import QtQuick.Window
import QtQuick.Controls 2.15
import SerialPort 1.0
import SerialPortInfo 1.0


ApplicationWindow {
    visible: true
    width: 400
    height: 200
    title: "Serial Communication"

    QSerialPort {
        id: serialPort
    }

    QSerialPortInfo {
        id: serialPortInfo
    }

    Column {
        spacing: 10

        ComboBox {
            id: portComboBox
            width: 200
            model: {
                   var model = serialPortInfo.availablePorts()
//                   if (model.length > 0) {
//                       displayText = "Select Port"
//                   } else {
//                       displayText = "No Ports Available"
//                   }
                   model
               }
        }

        Button {
            text: "Open Port"
            onClicked: {
                var portName = portComboBox.currentText
                var baudRate = 9600
                if (serialPort.open(portName, baudRate))
                    console.log("Port opened successfully")
                else
                    console.log("Failed to open port")
            }
        }

        Button {
            text: "Close Port"
            onClicked: {
                serialPort.close()
                console.log("Port closed")
            }
        }

        TextField {
            id: inputField
            width: 200
            placeholderText: "Enter data to send"
        }

        Button {
            text: "Send Data"
            onClicked: {
                var data = inputField.text
                serialPort.write(data)
                console.log("Data sent:", data)
            }
        }

        TextArea {
            id: receivedText
            width: 200
            height: 100
            readOnly: true
        }

        Connections {
            target: serialPort
            function dataReceived(data) {
                receivedText.text += data + "\n"
            }
        }
    }
}
