# Qt_Practice
 Qt Creator IDE에서 C++과 QML 개념을 연습하기 위한 레포입니다.

## On Going Toy Project
- 시리얼 통신을 이용한 Superlum 기기와의 통신 프로그램
- https://github.com/Jeremy-0204/Qt_Practice/tree/main/Test

## QT 개념 정리
### **1) QT Creator IDE 설치**

사이트에 바로 뜨는 다운로드를 하려면 결제 필요함 -> 
Download Opensource 에서 Online installer 설치 (https://www.qt.io/download-open-source)   
- 설치시 cmd창에서 --mirror 옵션으로 installer 실행 필요 (https://thirdnsov.github.io/tech/2021/11/02/T_Qt_OnlineInstaller.html)  

### **2) QT 프로젝트 생성**
Qt Widget, Qt Console, Qt Quick 3가지 Application 종류 존재  
주로 Qt Quick 사용  

- Qt Widget   -> 데스크탑 전용, ".ui" 파일 따로 존재  
- Qt Console  -> 콘솔 전용, Command Line을 통한 텍스트 기반의 애플리케이션  
- Qt Quick    -> QML과 JavaScript 기반의 UI 구현, 모바일 및 임베디드까지 구현 가능  

### **3) QT Main 함수 플로우**
- QGuiApplication 객체 생성, Qt Quick 기반 GUI 애플리케이션 초기화
- QQmlApplication 객체 생성, QML 파일 업로드 및 실행 역할
- 작성한 클래스를 QML 엔진의 타입으로 등록
- 로드할 QML URL 지정
- 예외처리 (connect를 사용하여 QQmlApplication 객체 생성 실패시 objectCreationFailed 시그널 발생, QGuiApplication의 slot인 exit 함수로 애플리케이션 종료)
- QML 로드
- 이벤트 루프 실행

### **4) MVVM Pattern**
Model의 QML, View와 ViewModel은 CPP으로 개발할 수 있다.  
MVVM 패턴의 적용을 위해서는 View와 ViewModel 간의 Binding이 필요함.  
이때 사용하는 것이 Signal, Slot의 개념이다.  

    간단한 예시:
    - https://forum.qt.io/topic/143391/mvvm-example-with-qt-qml-c

### **5) Signal & Slot**
Signal 발생시 Slot에 등록된 무언가 실행되는 구조  
 Signal and Slot 메커니즘이 작동하기 위해서는 connection을 해줘야 하는데 반드시 QObject를 상속받아야 함  

    C++ 과 Qt/QML을 이용한 개발 - 004: (Qt5 기본) Signal and Slot  
    - https://dev-optimist.tistory.com/38  

    Qml프로그래밍 cpp qml 연동1(c++에서 qml 함수 호출하기) 
    - https://youonlyliveonce1.tistory.com/23

    Qml프로그래밍 cpp qml 연동2(qml 에서 C++ 함수 호출하기)
    - https://youonlyliveonce1.tistory.com/25?category=712090

    Qml프로그래밍 cpp qml 연동3(qml 에서 C++ 함수 호출하기)
    - https://youonlyliveonce1.tistory.com/26

### **6) 그 외의 cpp, qml 연동방법**  




