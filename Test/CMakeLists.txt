cmake_minimum_required(VERSION 3.16)

project(Test VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick)

qt_standard_project_setup()

qt_add_executable(appTest
    main.cpp
    serialport.h serialport.cpp
    superlumbs840.h superlumbs840.cpp
)

qt_add_qml_module(appTest
    URI Test
    VERSION 1.0
    QML_FILES Main.qml settings.qml singletone.qml singlesweep.qml
)

find_package(Qt6 REQUIRED COMPONENTS SerialPort)
target_link_libraries(appTest PRIVATE Qt6::SerialPort)

find_package(Qt6 COMPONENTS Core Quick QuickControls2 REQUIRED)
target_link_libraries(appTest PRIVATE Qt6::Core Qt6::Quick Qt6::QuickControls2)

set_target_properties(appTest PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appTest
    PRIVATE Qt6::Quick
)

install(TARGETS appTest
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
