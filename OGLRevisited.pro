QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

LIBS += -lGLEW -lglfw3 -lGL -lX11 -lXi -lXrandr -lXxf86vm -lXinerama -lXcursor -lrt -lm -pthread -lSDL2 -ldl

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
    shader.cpp \
    stb_image.cpp \
    camera.cpp \
    ImGui/imgui.cpp \
    ImGui/imgui_draw.cpp \
    ImGui/imgui_impl_glfw.cpp \
    ImGui/imgui_impl_opengl3.cpp \
    ImGui/imgui_widgets.cpp \
    ImGui/imgui_demo.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    shader.h \
    stb_image.h \
    camera.h \
    ImGui/imconfig.h \
    ImGui/imgui.h \
    ImGui/imgui_impl_glfw.h \
    ImGui/imgui_impl_opengl3.h \
    ImGui/imgui_internal.h \
    ImGui/imstb_rectpack.h \
    ImGui/imstb_textedit.h \
    ImGui/imstb_truetype.h
