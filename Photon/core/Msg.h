#pragma once
#include "../pch.h"
#include "Data.h"
namespace Photon::Event {
enum class MsgType { Changed, Remain };

enum MsgOrigin { MouseX = 0, MouseY, KeyDown, KeyUp };

//消息使用：指定自己需要什么时候被通知，以及监听的源

//下面是类型

}  // namespace Photon::Event