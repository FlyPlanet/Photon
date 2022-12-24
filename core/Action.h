#pragma once
#include "../pch.h"
#include "Object.h"
#include "Signal.hpp"
template <class T> class Action;
template <class R, class... Arg>
class Action<R(Arg...)>
{
  private:
    std::function<R(Arg...)> f;
    long idWaitingFor=-1;
  public:
    Action(Object *parent = nullptr)
    {
        if (parent == nullptr)
        {
            
        }
    }
    void Requiring(long id)
    {
        idWaitingFor = id;
    }
    bool isFit(Signal_ s)
    {
        const std::type_info &t = typeid(R(Arg...));
        if (t.hash_code() == s.signHash && idWaitingFor == s.id)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    std::function<R(Arg...)> OutFunc()
    {
        return f;
    }
};