#pragma once
#include "../pch.h"
#include "Data.h"

#include "../extension/ControlBase.h"

namespace Photon::Core
{
    using namespace Photon::Core;
    using namespace Photon::Extension;


    //事件的提供者，即Listener
    class Listener{
        public:
            //构造函数
            Listener();
            //析构函数
            virtual ~Listener();

            //虚函数:输出事件的数据
            virtual Data getData() = 0;

            //设置监听目标
            virtual void setTarget(ControlBase *target);
            
            //示范：如果监听的是按钮，则Listen应该要一个OnClick函数，返回布尔值，其中一个参数作为输出
            
    };
}