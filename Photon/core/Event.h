#pragma once
#include "../pch.h"
#include "Data.h"
//用来定义一些关于Event的数据类型
namespace Photon::Event {
enum class MsgType { Changed, Remain };

enum MsgOrigin { MouseX = 0, MouseY, KeyDown, KeyUp };

//消息使用：指定自己需要什么时候被通知，以及监听的源
struct EventUnit{
    MsgType Mt;
    Data::Data &body;
};

}  // namespace Photon::Event