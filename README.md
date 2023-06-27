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
- C++ 과 Qt/QML을 이용한 개발 - 008: (Quantum Jump-1)주소록 프로그램- 3. C++ 연동과 MVVM Pattern (https://dev-optimist.tistory.com/46)

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
Signal Slot을 사용하지 않고도 Q_INVOKABLE, Q_PROPERTY로 cpp에서 정의된 메소드와 멤버변수에 qml에서 접근하는 방법도 존재한다. Cpp 클래스를 메인함수에서 qml에서 사용가능하게 만들 수 있는 방법이 2가지 존재한다. qmlRegisterType을 사용하면 QMl에서 직접 인스턴스를 생성하고 메소드나 프로퍼티에 접근할 수 있음.  

다른 방법은 engine.rootContext로 미리 생성된 객체를 QML에서 참조하는 방식으로 사용된다.  

QML/C++ 통합하기(Q_PROPERTY, Q_INVOKABLE, SIGNAL)  
https://1d1cblog.tistory.com/494

### 7) QSerialPort
Qt에는 자체적으로 시리얼 통신을 위한 QSerialPort, QSerialPortInfo 모듈이 존재함.  
https://doc.qt.io/qt-5/qserialport.html  
https://doc.qt.io/qt-5/qserialportinfo.html  

해당 클래스를 사용하려면 Cmake, qmake에서는 직접 모듈을 추가해주어야 함.  
https://doc.qt.io/qt-6/qtserialport-index.html

SuperlumBS840 통신 구현의 경우 QSerialPort 클래스의 인스턴스를 멤버변수로 선언하여 해당 인스턴스의 멤버 함수들을 호출하는 별개의 SerialPort 클래스를 구현했다.  


## 2. SuperlumBS840 구현
### **1) 클래스 구성**
main.cpp, superlumbs840vm.cpp, superlumbs840.cpp, serialport.cpp, MGenSweepLaser.cpp 

### **2) QML 구성**
main.qml -> settings.qml, singletone.qml, singlesweep.qml, continuousesweep.qml

### **3) 전반적인 FLow**
model -> SuperlumBS840, SerialPort  
ViewModel -> SuperlumBS840VM   
View -> 그 외 모두들  

QML에서는 ViewModel인 SuperlumBS840VM 클래스와만 소통한다. SuperlumBS840VM의 메소드는 모두 Q_INVOKABLE로 선언되어 있으며 해당 메소드 호출시 SuperlumBS840의 클래스 멤버 메소드를 호출하여 Model에 접근한다.  


