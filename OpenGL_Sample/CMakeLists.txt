cmake_minimum_required(VERSION 3.16)

project(OpenGL_Sample VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick)



qt_standard_project_setup()

qt_add_executable(appOpenGL_Sample
    main.cpp
    opengltriangleitem.h opengltriangleitem.cpp
)

qt_add_qml_module(appOpenGL_Sample
    URI OpenGL_Sample
    VERSION 1.0
    QML_FILES Main.qml
)

#qt_add_resources(QML_RESOURCES resources.qrc Main.qml)


find_package(Qt6 REQUIRED COMPONENTS OpenGL)
target_link_libraries(appOpenGL_Sample PRIVATE Qt6::OpenGL)

find_package(Qt6 REQUIRED COMPONENTS OpenGLWidgets)
target_link_libraries(appOpenGL_Sample PRIVATE Qt6::OpenGLWidgets)

set_target_properties(appOpenGL_Sample PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appOpenGL_Sample
    PRIVATE Qt6::Quick
)

install(TARGETS appOpenGL_Sample
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
