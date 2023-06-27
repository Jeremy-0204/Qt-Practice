# Qt_Practice
 Qt Creator IDE에서 C++과 QML 개념을 연습하기 위한 레포입니다.

## On Going Toy Project
- 시리얼 통신을 이용한 Superlum 기기와의 통신 프로그램
- https://github.com/Jeremy-0204/Qt_Practice/tree/main/Test

## QT 개념 정리
### 1) QT Creator IDE 설치
사이트에 바로 뜨는 다운로드를 하려면 결제 필요함 -> 
Download Opensource 에서 Online installer 설치 (https://www.qt.io/download-open-source)   
- 설치시 cmd창에서 --mirror 옵션으로 installer 실행 필요 (https://thirdnsov.github.io/tech/2021/11/02/T_Qt_OnlineInstaller.html)  

### 2) QT 프로젝트 생성
Qt Widget, Qt Console, Qt Quick 3가지 Application 종류 존재  

Qt Widget   -> 데스크탑 전용, ".ui" 파일 따로 존재  
Qt Console  -> 콘솔 전용, Command Line을 통한 텍스트 기반의 애플리케이션  
Qt Quick    -> QML과 JavaScript 기반의 UI 구현, 모바일 및 임베디드까지 구현 가능  

### 3) QT Main 함수 플로우
- QGuiApplication 객체 생성, Qt Quick 기반 GUI 애플리케이션 초기화
- QQmlApplication 객체 생성, QML 파일 업로드 및 실행 역할
- 작성한 클래스를 QML 엔진의 타입으로 등록
- 로드할 QML URL 지정
- 예외처리 (connect를 사용하여 QQmlApplication 객체 생성 실패시 objectCreationFailed 시그널 발생, QGuiApplication의 slot인 exit 함수로 애플리케이션 종료)
- QML 로드
- 이벤트 루프 실행



