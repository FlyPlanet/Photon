#pragma once
#include "../pch.h"
namespace Photon::Window{
    class glWindow{
    public:
        //一些opengl内部的需要复用的资源
        GLFWWindow window *;        //记得初始化

        static std::once_flag glInitFlag;
        glWindow();
        ~glWindow();
        void Show(int width,int height,char[] title);//会完成窗体的创建，并开始消息循环
        void eventForward(GLFWwindow *window);

        virtual void eventLoop() = 0;

        //glfw的事件转photon的事件形式
    }
}