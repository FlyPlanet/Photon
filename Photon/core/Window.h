#pragma once
#include "../pch.h"
#include "../Photon.h"
namespace Photon::Window {
    class Window : public Control::ControlBase {
      public:
        Window();
        ~Window();
        void Show();
        int fps();

      private:
        static std::once_flag glInited,glTermed;    //opengl callonce的标识
        GLFWwindow*           window;  //opengl窗口句柄
        std::chrono::time_point<
            std::chrono::system_clock,
            std::chrono::duration<long, std::ratio<1, 1000000000>>>
            clock = std::chrono::system_clock::now();  //用于计时的时钟

        std::map<Photon::Event::MsgOrigin,std::any> data;        //储存所有数据的容器
        

        
        void InitGlWindow(int width,int height,char* title);
        void MsgLoop();
        friend class Photon::Control::ControlBase;


        
    };
}