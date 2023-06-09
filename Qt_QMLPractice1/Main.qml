import QtQuick
import QtQuick.Window
import QtQuick.Controls 6.3

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")




    Rectangle {
        id: rectangle
        color: "#0eb4af"
        anchors.fill: parent

        Column {
            id: column
            y: 0
            width: 200
            height: 480
            spacing: 15
            anchors.horizontalCenterOffset: 1
            anchors.horizontalCenter: parent.horizontalCenter

            Text {
                id: text1
                text: qsTr("Write any number in your mind")
                font.pixelSize: 12
                anchors.horizontalCenter: parent.horizontalCenter
            }

            TextField {
                id: textField
                width: 104
                height: 22
                anchors.horizontalCenter: parent.horizontalCenter
                placeholderText: qsTr("Text Field")
            }

            Button {
                id: button
                width: 61
                height: 18
                text: qsTr("Button")
                anchors.horizontalCenter: parent.horizontalCenter

                onClicked:
                {
                    text1.text = "You just imagined " + textField.text;


                    dialog.open();

                }

                Connections {
                    target: button
                    onClicked: console.log("clicked")
                }
            }

            Dialog {
                    id: dialog
                    x:(parent.width-width)/2
                    y:(parent.height-height)/2
                    implicitWidth: 500;
                    implicitHeight: 300;
                    title: "Dialog"
                    Text {
                        id: dialogMessage
                        text: qsTr("You were Thinking of number " + textField.text)
                    }
                    modal: true;
                    standardButtons: Dialog.Ok | Dialog.Cancel

                    onAccepted: console.log("Ok clicked")
                    onRejected: console.log("Cancel clicked")
                }



        }
    }

}
