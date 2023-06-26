# Qt_Practice
 Qt Creator IDE에서 C++과 QML 개념을 연습하기 위한 레포입니다.

## On Going Toy Project
- 시리얼 통신을 이용한 Superlum 기기와의 통신 프로그램
- https://github.com/Jeremy-0204/Qt_Practice/tree/main/Test

## QT 개념정리
### 1) Flow
- QGuiApplication 객체 생성, Qt 애플리케이션 초기화
- QQmlApplication 객체 생성, QML 파일 업로드 및 실행 역할
- 작성한 클래스를 QML 엔진의 타입으로 등록
- 로드할 QML URL 지정
- QQmlApplication 객체 생성 실패시 objectCreationFailed 시그널 발생, QGuiApplication의 slot인 exit 함수로 애플리케이션 종료
- QML 로드
- 이벤트 루프 실행


```
int main(int argc, char *argv[])
{
    // QGuiApplication 객체를 생성하여 Qt 애플리케이션을 초기화합니다.
    QGuiApplication app(argc, argv);

    // QQmlApplicationEngine 객체를 생성합니다. 이 엔진은 QML 파일을 로드하고 실행하는 역할을 합니다.
    QQmlApplicationEngine engine;

    // SerialPort 클래스를 "SerialPort"라는 이름으로 QML 엔진에 등록합니다.
    qmlRegisterType<SerialPort>("SerialPort", 1, 0, "SerialPort");

    // SuperlumBS840 클래스를 "SuperlumBS840"라는 이름으로 QML 엔진에 등록합니다.
    qmlRegisterType<SuperlumBS840>("SuperlumBS840", 1, 0, "SuperlumBS840");

    // QML 파일의 URL을 정의합니다. "qrc:/Test/Main.qml"은 리소스 파일에 있는 Main.qml 파일을 가리킵니다.
    const QUrl url(QStringLiteral("qrc:/Test/Main.qml"));

    // QQmlApplicationEngine의 objectCreationFailed 시그널과 QGuiApplication의 exit 함수를 연결하여 객체 생성 실패 시 애플리케이션을 종료합니다.
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    // QML 파일을 로드하여 애플리케이션을 실행합니다.
    engine.load(url);

    // 이벤트 루프를 시작하고 애플리케이션을 실행합니다.
    return app.exec();
}
```