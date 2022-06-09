#pragma once
#include "../pch.h"
#include "Listener.h"
#include "Data.h"
#include "Context.h"
namespace Photon::Core{
    using namespace Photon::Core;
    class Require
    {
    public:
        //接受模板T1\T2，T1必须是Listener的子类，T2必须是T1的成员函数
        template<typename T1, typename T2> requires std::is_base_of_v<Listener, T1> && std::is_member_function_pointer_v<T2>
        void addRequire(ControlBase* control,T1 *listener,T2 func){
            //判断不为空
            if(listener == nullptr){
                return;
            }
            

        }

        static Context 
    };
}