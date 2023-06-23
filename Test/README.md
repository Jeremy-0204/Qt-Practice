# ABOUT
토이 프로젝트로 SuperlumBS840 Swept Laser에 대한 QT 기반 시리얼 통신 프로그램을 만들어 봅니다.

# PROBLEM TO FIX
## 1) 패킷 송수신
- ### 현재 상황
QSerialPort를 통해 패킷 송수신 진행  
시리얼 통신중 패킷이 도착하면 ReadyRead 시그널 발생, handleReadyRead 슬롯 호출  
패킷을 읽어올때는 "\n"을 기준으로 readall()로 불러옴  
패킷을 여러번 연속해서 보내면 패킷을 제대로 못 읽어오는 현상 발생  
ReadyRead 시그널이 패킷 중간에도 발생할 수 있는걸까?  

- ### 해결 방안
패킷을 한번 보낼때마다 waitForReadyRead()로 ReadyRead 시그널을 기다려보기로 함  
ReadyRead 시그널이 발생해도 waitForReadyRead() 매개변수의 시간만큼 다 기다리는 현상 발생  
패킷은 제대로 받아오지만 ReadyRead가 발생해도 waitForReadyRead가 풀타임으로 대기 중  

- ### TODO
ReadyRead 시그널이 한 패킷이 도착할때마다 발생할 수 있게 확인  
waitForReadyRead()가 ReadyRead 시그널이 발생하면 return 할 수 있게 확인

  
## 2) MVVM 패턴 적용
- ### 현재 상황
본 프로그램의 주요 클래스인 SuperlumBS840, SerialPort는 Model의 역할을 함  
View 역할을 하는 QML에서는 해당 클래스에 대한 인스턴스를 qml에서 프로퍼티로 생성한 뒤 직접 접근하여 사용 중  

어디까지가 현재 MVVM 패턴 적용이 되어있는가?  
SerialPort 클래스의 인스턴스는 Setting.qml에서 한번, SuperlumBS840 클래스에서 한번 총 두번 생성 된다  
Setting.qml에서는 포트 목록을 불러오기 위해서고, 이를 직접 연결할때는 Superlum 내부의 SerialPort 클래스를 호출해서 사용함  

- ### 해결 방안
Superlum에서 직접 SerialPort를 호출하는 메서드는 viewModel로서의 역할을 하고 있는게 아닐까?  

- ### TODO
QML에서 Superlum 클래스와 직접 연동되는 부분들을 모아서 정리  
해당 부분들에 대한 ViewModel 클래스 생성  
해당 ViewModel 클래스로 QML 연동하기  

근데 SuperlumBS840 클래스는 MGenSweeplaser를 상속받아서 오버라이딩을 하는데, SuperlumBS840의 기존에 오버라이딩 되던 함수들을 별개의 함수로 만들고 오버라이딩은 viewModel 클래스에서 상속받아와서 선언하면 될까??  
