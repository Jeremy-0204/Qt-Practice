import QtQuick 2.15
import QtQuick.Window
import QtQuick.Controls 2.15

Item {
    width: 200
    height: 200

    SerialPort {
        id: serialPort
        onAvailablePortsChanged: {
            // 포트 번호 목록이 변경되었을 때 처리할 로직
        }
    }

    Column {
        spacing: 10

        Text {
            text: "Available Ports:"
            font.bold: true
        }

        ListView {
            width: 180
            height: 120
            model: serialPort.availablePorts
            delegate: Text {
                text: modelData
                font.pixelSize: 12
            }
        }

        ComboBox {
            id: baudRateComboBox
            width: 180
            model: serialPort.baudRates
            currentIndex: 0
        }

        Button {
            text: "Connect"
            onClicked: {
                var selectedPort = portListView.model.get(portListView.currentIndex)
                var selectedBaudRate = baudRateComboBox.model.get(baudRateComboBox.currentIndex)
                var selectedFlowControl = flowControlComboBox.currentText
                var selectedParity = parityComboBox.currentText
                var selectedDataBits = dataBitsComboBox.currentText
                var selectedStopBits = stopBitsComboBox.currentText
                serialPort.connectToPort(selectedPort, selectedBaudRate, selectedFlowControl, selectedParity, selectedDataBits, selectedStopBits)
            }
        }


        Button {
            text: "Refresh"
            onClicked: serialPort.refreshAvailablePorts()
        }
    }
}
