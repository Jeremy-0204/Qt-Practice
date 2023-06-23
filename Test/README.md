# ABOUT
토이 프로젝트로 SuperlumBS840 Swept Laser에 대한 QT 기반 시리얼 통신 프로그램을 만들어 봅니다.

# PROBLEM TO FIX
### 1) 패킷 송수신
- #### 현재 상황
QSerialPort를 통해 패킷 송수신 진행  
시리얼 통신중 패킷이 도착하면 ReadyRead 시그널 발생, handleReadyRead 슬롯 호출  
패킷을 읽어올때는 "\n"을 기준으로 readall()로 불러옴  

- #### 문제점
패킷을 여러번 연속해서 보내면 패킷을 제대로 못 읽어오는 현상 발생  
ReadyRead 시그널이 패킷 중간에도 발생할 수 있는걸까?  

- #### 해결 방안
패킷을 한번 보낼때마다 waitForReadyRead()로 ReadyRead 시그널을 기다려보기로 함  
ReadyRead 시그널이 발생해도 waitForReadyRead() 매개변수의 시간만큼 다 기다리는 현상 발생  
패킷은 제대로 받아오지만 ReadyRead가 발생해도 waitForReadyRead가 풀타임으로 대기 중  

- #### TODO
ReadyRead 시그널이 한 패킷이 도착할때마다 발생할 수 있게 확인  
waitForReadyRead()가 ReadyRead 시그널이 발생하면 return 할 수 있게 확인

  
### 2) MVVM 패턴 적용
- #### 현재 상황
본 프로그램의 주요 클래스인 SuperlumBS840, SerialPort는 Model의 역할을 함  
View 역할을 하는 QML에서는 해당 클래스에 대한 인스턴스를 qml에서 프로퍼티로 생성한 뒤 직접 접근하여 사용 중  

- #### 문제점
어디까지가 현재 MVVM 패턴 적용이 되어있는가?  
SerialPort 클래스의 인스턴스는 Setting.qml에서 한번, SuperlumBS840 클래스에서 한번 총 두번 생성 된다  
Setting.qml에서는 포트 목록을 불러오기 위해서고, 이를 직접 연결할때는 Superlum 내부의 SerialPort 클래스를 호출해서 사용함  
