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
    void AddChild(ControlBase* in);
    void DelChild(ControlBase* in);
    void registerEvent(Event::Event* event);

  private:
    std::vector<ControlBase*> children;
    Photon::Window::Window fWindow;       //自己所在的父窗口

    std::map<Photon::Event::MsgOrigin,std::any*> dataTemp;//数据位置第二节点,本体在window

    std::map<Photon::Event::MsgOrigin, std::list<Photon::Event::Event>> events;

  protected:
    void changeData(Photon::Event::MsgOrigin ms,std::any data);          
};
}  // namespace Photon::Control