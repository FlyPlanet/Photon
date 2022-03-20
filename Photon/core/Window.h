#pragma once
#include "../pch.h"
#include "../opengl/glWindow.h"
namespace Photon::Window {
class Window:glWindow {
  public:
    Window();
    ~Window();
    void Show();
    int  fps();

    static std::once_flag glInited, glTermed; // opengl callonce的标识
    GLFWwindow           *window;             // opengl窗口句柄
    std::chrono::time_point<
        std::chrono::system_clock,
        std::chrono::duration<long, std::ratio<1, 1000000000>>>
        clock = std::chrono::system_clock::now(); //用于计时的时钟

    void InitGlWindow( int width, int height, char *title );
    void MsgLoop();

};
}  // namespace Photon::Window