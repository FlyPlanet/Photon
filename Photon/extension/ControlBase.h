#include "../pch.h"

namespace Photon::Extension {
    //所有控件的基类
    class ControlBase{
        public:
            //构造函数
            ControlBase();
            //析构函数
            virtual ~ControlBase();
            
        private:
            void run();
    };
}