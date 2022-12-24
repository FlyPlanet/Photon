#pragma once
//使用方法大概是通过Observer_作为基类定义新的observer,然后使用新的observer再作为基类做出新的组件
#include "../pch.h"
typedef void(*ObserveFunction)();
class Observer_
{
    virtual void Observe()=0;
};