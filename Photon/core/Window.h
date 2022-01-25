#pragma once
#include "../pch.h"
#include "../Photon.h"
#include "ControlBase.h"
#include <GLFW/glfw3.h>
#include <mutex>
namespace Photon {
namespace Window {
    class Window : public Control::ControlBase {
      public:
        Window();
        ~Window();
        void Show();

      private:
        static std::once_flag glInited,glTermed;
        GLFWwindow* window;
        void InitGlWindow(int width,int height,char* title);
        void MsgLoop();
    };
}
}