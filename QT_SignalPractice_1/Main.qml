import QtQuick
import QtQuick.Window
import QtQuick.Controls 2.15

Window
{
    property bool mbImageClicked: true
    property int mCount : 0

    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    function qmlSlotTestData(data)
    { // Slot으로 등록한 함수
        console.log("qmlSlotTestData data:" + data);
        testText.text = data;
    }

    StackView
    {
        id:stackView
        anchors.fill: parent

        initialItem: Item
        {
            objectName: "mainscreen"
            Rectangle
            {
                anchors.fill: parent
                color: "white"
            }

            Text
            {
                id: testData
                anchors.horizontalCenter: parent.horizontalCenter
                text: "cpp -> qml signal & slot"
                font.pixelSize: 30
                font.bold: true
            }

            Text
            {
                id: testText
                anchors.centerIn: parent
                text: "main screen"
                font.pixelSize: 50
                font.bold: true
            }

            Button
            {
                id: nextButton
                anchors.top: testText.bottom
                anchors.horizontalCenter: parent.horizontalCenter
                text: "go screen1"
                onClicked:
                {
                    console.log("push screen1")
                    //stackView.push(Qt.resolvedUrl("qrc:/screen1.qml"))
                }
            }

            Button
            {
                anchors.top: testText.bottom
                anchors.left: nextButton.right
                anchors.leftMargin: 30
                text: "go screen2"
                onClicked:
                {
                    console.log("push screen2")
                    //stackView.push(Qt.resolvedUrl("qrl:/screen2.qml"))
                }
            }
        }

    }
}

