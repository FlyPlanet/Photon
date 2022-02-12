#pragma once
#include "../Photon.h"
#include "../pch.h"
namespace Photon::Event {
class Event {
  public:
    Event();
    void addRequire( Photon::Event::MsgType mt, Photon::Event::MsgOrigin mo );
    void regisiter( EventCenter *ec );
    EventUnit fetch(); //进点新货
    Photon::Data::Data
        getEventValue( Photon::Event::MsgOrigin mo ); //获取event的值
  private:
   bool registered = false;
   EventCenter *boss;      //货源
    int          eventPosition = 0; //新货的地址
    std::map<Photon::Event::MsgOrigin, Photon::Data::Data *>   moData;
    std::map<Photon::Event::MsgOrigin, Photon::Event::MsgType> moMt;
};
} // namespace Photon::Event

/*
消息组织策略
窗口储存消息的源头数据
在更改源头数据的时候，通过变化，进行发消息
流程：
1.源头数据有更改
2.触发源头消息有关的MsgOrigin
3.从root节点开始进行消息传递

注册消息的流程：
1.建立消息类(类中包含需要申请监听的信息与监听类别)
2.将消息类，存储到父控件
3.在root窗口建立对应的数据，修改消息类中对应的引用
4.建立消息类，用于连接储存消息类和消息源头类
*/