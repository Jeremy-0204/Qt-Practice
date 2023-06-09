import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import "."

Window {
    property bool mbImageClicked: true
    property int mCount: 0

    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    // Signal 선언
    signal qmlSignalString(var StringData);
    signal qmlSignalInt(var IntData);

    // Slot으로 등록되어 있는 함수
    function qmlSlotFunction(data)
    {
        console.log("QmlSlotFunction Data : " + data);
        signalresponse.text = data;
    }

    function updateSignalResponse(data) {
        signalresponse.text = data;
    }

    StackView
    {
        id: stackView
        anchors.fill: parent
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0

        initialItem: Item
        {
            objectName: "mainscreen"
            Rectangle
            {
                anchors.fill: parent
                color: "white"

                TextField {
                    id: textField0
                    x: 245
                    y: 283
                    width: 62
                    height: 22
                    placeholderText: qsTr("Number")
                }

                TextField {
                    id: textField1
                    x: 245
                    y: 319
                    width: 62
                    height: 22
                    placeholderText: qsTr("Text Field")
                }
            }

            Text
            {
                id: testData
                anchors.horizontalCenter: parent.horizontalCenter
                text: qsTr("cpp <-> qml signal and slot")
            }

            Text
            {
                id: signalresponse
                anchors.centerIn: parent
                text: qsTr("Waiting for Signal")

            }

            Button
            {
                id:intButton
                x: 318
                y: 279
                width: 113
                height: 26 //int형 데이터를 매개변수에 넣어서 cpp함수를 호출하는 버튼
                //                anchors.right:strButton.left
//                anchors.top:strButton.top
//                anchors.rightMargin: 30
                text:"int data"
                onClicked:
                {
                    console.log("qml signal intButton click")
                    qmlSignalInt(textField0.text); //qml 에서 signal을 발생시키는 부분
                }
            }

            Button
            {
                id:strButton
                x: 318
                y: 317
                width: 113
                height: 26 //string형 데이터를 매개변수에 넣어서 cpp함수를 호출하는 버튼
//                anchors.right:intButton.right
//                anchors.top:intButton.top
//                anchors.rightMargin: 30
                text:"String Data"
                onClicked:
                {
                    console.log("qml signal strButton click")
                    qmlSignalString(textField1.text); //qml 에서 signal을 발생시키는 부분
                }
            }
        }
    }
}
