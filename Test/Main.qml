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
//                   if (model.length > 0) {
//                       displayText = "Select Port"
//                   } else {
//                       displayText = "No Ports Available"
//                   }
                   model
               }
        }
//        ListView {
//            width: 180
//            height: 120
//            id: portListView
//            model: serialPort.availablePorts
//            delegate: Text {
//                text: modelData
//                font.pixelSize: 12
//            }
//        }

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
            anchors.horizontalCenter: parent

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

//            Button {
//                text: "SINGLE TONE"
//                checkable: true  // 버튼을 선택 가능한 상태로 설정
//                checked: false  // 버튼을 선택되지 않은 상태로 설정 (들어가지 않은 상태)

//                // 버튼이 선택되었을 때의 스타일
//                background: Rectangle {
//                    color: "#00CC00"  // 선택된 상태의 배경색
//                    radius: 5  // 볼록한 모서리를 위한 반지름 값
//                }

//                // 버튼이 선택되지 않았을 때의 스타일
//                indicator: Rectangle {
//                    color: "#FFFFFF"  // 선택되지 않은 상태의 배경색
//                    radius: 5  // 볼록한 모서리를 위한 반지름 값
//                }

//                onClicked: {
//                    // 버튼이 클릭되었을 때의 동작
//                    if (checked) {
//                        // 버튼이 선택된 상태일 때의 로직
//                        // 들어가는 동작 수행
//                    } else {
//                        // 버튼이 선택되지 않은 상태일 때의 로직
//                        // 들어가지 않는 동작 수행
//                    }
//                }
//            }






        }
    }
}
