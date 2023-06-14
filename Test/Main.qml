import QtQuick 2.15
import QtQuick.Window
import QtQuick.Controls 2.15
import SerialPort 1.0

Window {
    visible: true
    width: 400
    height: 300

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

        ComboBox {
            id: flowControlComboBox
            width: 180
            model: serialPort.flowControls
            currentIndex: 0
        }

        ComboBox {
            id: parityComboBox
            width: 180
            model: serialPort.parityOptions
            currentIndex: 0
        }

        ComboBox {
            id: dataBitsComboBox
            width: 180
            model: serialPort.dataBits
            currentIndex: 0
        }

        ComboBox {
            id: stopBitsComboBox
            width: 180
            model: serialPort.stopBits
            currentIndex: 0
        }

        Button {
            text: "Connect"
            onClicked: {
                var selectedPort = portListView.model.get(portListView.currentIndex)
                var selectedBaudRate = baudRateComboBox.model.get(baudRateComboBox.currentIndex)
                var selectedFlowControl = flowControlComboBox.model.get(flowControlComboBox.currentIndex)
                var selectedParity = parityComboBox.model.get(parityComboBox.currentIndex)
                var selectedDataBits = dataBitsComboBox.model.get(dataBitsComboBox.currentIndex)
                var selectedStopBits = stopBitsComboBox.model.get(stopBitsComboBox.currentIndex)
                serialPort.connectToPort(selectedPort, selectedBaudRate, selectedFlowControl, selectedParity, selectedDataBits, selectedStopBits)
            }
        }

        Button {
            text: "Refresh"
            onClicked: serialPort.refreshAvailablePorts()
        }
    }
}
