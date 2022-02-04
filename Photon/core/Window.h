#pragma once
#include "../Photon.h"
#include "../pch.h"
namespace Photon::Window {
class Window : public Photon::Control::ControlBase {
  public:
    Window();
    ~Window();
    void Show();
    int  fps();

    static std::once_flag glInited, glTermed;  // opengl callonce的标识
    GLFWwindow*           window;              // opengl窗口句柄
    std::chrono::time_point<
        std::chrono::system_clock,
        std::chrono::duration<long, std::ratio<1, 1000000000>>>
        clock = std::chrono::system_clock::now();  //用于计时的时钟

    void InitGlWindow(int width, int height, char* title);
    void MsgLoop();
    std::map<Photon::Event::MsgOrigin, std::any>
        eventData;  //储存所有数据的容器

    std::map<Photon::Event::MsgOrigin,
             std::map<Photon::Event::MsgType, std::set<Control::ControlBase*>>>
        subControlEvents;  //用于储存组件所需的事件
};
}  // namespace Photon::Window