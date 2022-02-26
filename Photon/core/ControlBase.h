#pragma once

#include "../pch.h"
#include "Window.h"
#include "Msg.h"
#include "EventClient.h"
namespace Photon::Control {

class ControlBase {
 public:
  ControlBase();
  ~ControlBase();
  void AddChild(ControlBase *in);
  void DelChild(ControlBase *in);
  Photon::Window::Window *rWindow;
  std::vector<ControlBase *> children;

    std::map<Photon::Event::MsgOrigin, std::any *>
        dataTemp;  //数据位置第二节点,本体在window
                   //
    std::deque<Event::MsgOrigin> eventQuene;  //需要传达的消息队列

    std::map<Photon::Event::MsgOrigin, std::list<Photon::Event::EventClient>>
        events;

   protected:
};
}  // namespace Photon::Control