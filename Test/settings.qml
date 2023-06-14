import QtQuick 2.15
import QtQuick.Window
import QtQuick.Controls 2.15

Window {
    visible: true
    width: 400
    height: 300

    Column {
        spacing: 10
        anchors.centerIn: parent

        Text {
            text: "Available Ports:"
            font.bold: true
        }

        ComboBox {
            id: portListView
            width: 180
            model: {
                   var model = serialPort.availablePorts
                   model
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

        Row {
            spacing: 10
            //anchors.horizontalCenter: parent

            Button {
                text: "Connect"
                onClicked: {
                    var selectedPort = serialPort.availablePorts[portListView.currentIndex]
                    var selectedBaudRate = baudRateComboBox.model[baudRateComboBox.currentIndex]
                    var selectedFlowControl = flowControlComboBox.model[flowControlComboBox.currentIndex]
                    var selectedParity = parityComboBox.model[parityComboBox.currentIndex]
                    var selectedDataBits = dataBitsComboBox.model[dataBitsComboBox.currentIndex]
                    var selectedStopBits = stopBitsComboBox.model[baudRateComboBox.currentIndex]
                    serialPort.connectToPort(selectedPort, selectedBaudRate, selectedFlowControl, selectedParity, selectedDataBits, selectedStopBits)
                }
            }

            Button {
                text: "Refresh"
                onClicked: serialPort.refreshAvailablePorts()
            }
        }
    }

    // settings.pml 창이 닫힐 때 신호를 보내기 위한 신호
    signal closed
    onClosed: closed()
}
