import QtQuick 2.15
import QtQuick.Window
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3

Item {
    id: item3
    ColumnLayout{
        anchors.left: parent.left
        anchors.leftMargin: 20
        Text {
            id: fullTuningRange
            text: qsTr("Full Tuning Range:  805nm ~ 880nm")
            font.bold: true
            font.pointSize: 9
        }

        Text {
            id: waveLength
            text: qsTr("Light Wavelength")
            font.bold: true
            font.pointSize: 9
        }

        RowLayout{
            TextField {
                id: startWaveLength
                placeholderText: qsTr("Start")

                onTextChanged:
                {
                    placeholderText: placeholderText + qsTr(" nm");
                }
            }

            TextField {
                id: endWaveLength
                placeholderText: qsTr("End")

                onTextChanged:
                {
                    placeholderText: placeholderText + qsTr(" nm");
                }
            }
        }

        RowLayout{
            Text {
                id: sweepSpeedText
                text: qsTr("Sweep Speed")
                font.bold: true
                font.pointSize: 9
            }

            Text {
                id: puaseText
                text: qsTr("Pause")
                Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
                font.bold: true
                font.pointSize: 9
            }

        }

        RowLayout{
            TextField {
                id: sweepSpeedInput
                placeholderText: qsTr("Enter Speed")

                onTextChanged:
                {
                    placeholderText: placeholderText + qsTr(" nm");
                }
            }

            TextField {
                id: pauseInput
                placeholderText: qsTr("Enter Pause")

                onTextChanged:
                {
                    placeholderText: placeholderText + qsTr(" nm");
                }
            }
        }

        Text {
            id: sweepTimeText
            text: qsTr("Sweep Time 30ms")
            font.bold: true
            font.pointSize: 9
        }

        Button {
            id: saveButton
            text: "Save"
            onClicked:
            {
                superlumBS840VM.onClickedSetContinuousSwept(2, startWaveLength.text, endWaveLength.text, sweepSpeedInput.text, pauseInput.text)
            }
        }
    }
}
