//信号只是用来寻找Observer和需求函数，找到后就建立对应的函数回调
#pragma once
#include "../pch.h"
#include "DOMTree.hpp"
#include <cstddef>
#include <typeinfo>
#define NewSignal(SIGNATURE, NAME) Signal<#SIGNATURE>##NAME(#NAME)
//用于传播的信号
class Signal_
{
  public:
    long id;            //信号的id
    size_t signHash;        //对应的相应函数的签名
    std::string rawname;
    Signal_()=delete;
    Signal_(size_t signHash,std::string rawname,size_t id):signHash(signHash),rawname(rawname),id(id){}
};
//定义的信号
template <class T>
class Signal;
template <class R,class... Arg>
class Signal<R(Arg...)>
{
  private:
    std::string name;
    static long id_now;
    std::vector<std::function<R(Arg...)>> functions;
    bool rebuildPath = true;
    Signal()
    {
        id = id_now;
        id_now++;
    }
  public:
    Signal(std::string name):Signal(),name(name){}
    long id;
    operator Signal_()
    {
        const std::type_info& t=typeid(R(Arg...));
        return Signal_(t.hash_code(),name,id);
    }
    
    template <class... T>
    requires (std::is_same_v<T...,Arg...>)
    void Emit(T...arg)
    {
        if (rebuildPath)
        {
            
        }
        else
        {
            for (auto &i : functions)
            {
                i(std::forward<T>(arg)...);
            }
        }
    }
};
template <class T,class ...H>
long Signal<T(H...)>::id_now=0;