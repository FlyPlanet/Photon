#pragma once
#include "../pch.h"
#include "../opengl/glWindow.h"
namespace Photon::Extension {
    class WindowBase{
        public:
            //构造函数
            WindowBase();
            //析构函数
            virtual ~WindowBase();
        private:
            void messageLoop();
            
    }
}  // namespace Photon::Window