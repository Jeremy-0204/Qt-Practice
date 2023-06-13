cmake_minimum_required(VERSION 3.16)

project(SuperlumBS840 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick)

qt_standard_project_setup()

qt_add_executable(appSuperlumBS840
    main.cpp
    serialport.h
    serialport.cpp
)

qt_add_qml_module(appSuperlumBS840
    URI SuperlumBS840
    VERSION 1.0
    QML_FILES Main.qml
)

find_package(Qt6 REQUIRED COMPONENTS SerialPort)
target_link_libraries(appSuperlumBS840 PRIVATE Qt6::SerialPort)

set_target_properties(appSuperlumBS840 PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appSuperlumBS840
    PRIVATE Qt6::Quick
)

install(TARGETS appSuperlumBS840
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
