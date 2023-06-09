import QtQuick
import QtQuick.Window
import QtQuick.Controls 2.15
import ViewModel 1.0

Window {
    width: 640
    height: 480



    Rectangle {
        width: 200
        height: 200

        ViewModel//qml에 클래스를 선언해 주는 곳
        {
           id:viewModel;//클래스를 선언해주고 id를 등록
        }

        Text {
            id: clickedNumText
            anchors.centerIn: parent
            text: "Clicked Num: " + viewModel.clickedNum
        }

        Button {
            text: "Add"
            anchors {
                top: clickedNumText.bottom
                horizontalCenter: parent.horizontalCenter
                margins: 10
            }
            onClicked: {
                viewModel.addNum();
            }
        }

        Button {
            text: "Sub"
            anchors {
                top: clickedNumText.bottom
                horizontalCenter: parent.horizontalCenter
                margins: 10
            }
            onClicked: {
                viewModel.subNum();
            }
        }
    }

}
