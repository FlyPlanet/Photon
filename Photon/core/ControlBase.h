#pragma once
#include "../Photon.h"
#include "../pch.h"
#include "Event.h"
#include "Msg.h"
#include "Window.h"
namespace Photon::Control {

class ControlBase {
  public:
    ControlBase();
    ~ControlBase();
    void                      AddChild(ControlBase* in);
    void                      DelChild(ControlBase* in);
    void                      registerEvent(Event::Event e);
    Window::Window*           rWindow;
    std::vector<ControlBase*> children;
    void registerEvent(Event::MsgOrigin mo,Event::MsgType mt,std::function<void(const Photon::Event::Event*)> callback);
    void receiveEvent(Event::MsgOrigin mo);  //用于接受事件
    void spreadEvent();
    std::map<Photon::Event::MsgOrigin, std::any*>
        dataTemp;  //数据位置第二节点,本体在window
    std::deque<Event::MsgOrigin> eventQuene;  //需要传达的消息队列
    std::map<Photon::Event::MsgOrigin, std::list<Photon::Event::Event>> events;

  protected:
    void changeData(Photon::Event::MsgOrigin ms, std::any data);
};
}  // namespace Photon::Control