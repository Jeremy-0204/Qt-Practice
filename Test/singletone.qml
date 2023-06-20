import QtQuick 2.15
import QtQuick.Window
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.3

Item {
    id: item1

    signal signalfromSingleTone

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
                id: textField
                placeholderText: qsTr("Enter Wavelength")

                onTextChanged:
                {
                    placeholderText: placeholderText + qsTr(" nm");
                }
            }
        }

        Button {
            id: saveButton
            text: "Save"
            onClicked: {
                superlumBS840.setSingleToneWaveLength(textField.text)
                superlumBS840.setSweptMode(0)
                item1.signalfromSingleTone()
            }
        }
    }
}
