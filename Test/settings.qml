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

        QtObject {
            id: qml
            function toUtf8(str) {
                return str.toUtf8()
            }
        }

        Text {
            text: "Available Ports:"
            font.bold: true
        }

        ComboBox {
            id: portListView
            width: 180
            model: {
                   var model = superlumBS840VM.onClickedRefresh()
                   model
               }
        }

        ComboBox {
            id: baudRateComboBox
            width: 180
            model: superlumBS840VM.onBaudRates()
            currentIndex: 0
        }

        ComboBox {
            id: flowControlComboBox
            width: 180
            model: superlumBS840VM.onFlowControls()
            currentIndex: 0
        }

        ComboBox {
            id: parityComboBox
            width: 180
            model: superlumBS840VM.onParityOptions()
            currentIndex: 0
        }

        ComboBox {
            id: dataBitsComboBox
            width: 180
            model: superlumBS840VM.onDataBits()
            currentIndex: 0
        }

        ComboBox {
            id: stopBitsComboBox
            width: 180
            model: superlumBS840VM.onStopBits()
            currentIndex: 0
        }

        Row {
            spacing: 10
            //anchors.horizontalCenter: parent

            Button {
                text: "Connect"
                onClicked: {
                    var selectedPort = portListView.model[portListView.currentIndex]
                    var selectedBaudRate = baudRateComboBox.model[baudRateComboBox.currentIndex]
                    var selectedFlowControl = flowControlComboBox.model[flowControlComboBox.currentIndex]
                    var selectedParity = parityComboBox.model[parityComboBox.currentIndex]
                    var selectedDataBits = dataBitsComboBox.model[dataBitsComboBox.currentIndex]
                    var selectedStopBits = stopBitsComboBox.model[stopBitsComboBox.currentIndex]
                    superlumBS840VM.onClickedConnect(selectedPort, selectedBaudRate, selectedFlowControl, selectedParity, selectedDataBits, selectedStopBits)
                }
            }

            Button {
                text: "Refresh"
                onClicked: superlumBS840VM.onClickedRefresh()
            }


            Button {
                text: "Close"
                onClicked: superlumBS840VM.onClickedClose()
            }
        }
    }

    // settings.pml 창이 닫힐 때 신호를 보내기 위한 신호
    signal closed
    onClosed: closed()
}
