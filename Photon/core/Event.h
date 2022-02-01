#pragma once
#include "../pch.h"
#include "../Photon.h"

namespace Photon::Event {
class Event {
  public:
    Event(std::initializer_list<
          std::pair<Photon::Event::MsgType, Photon::Event::MsgOrigin>> events);
    Control::ControlBase* origin;
    void getEventValue(std::any* p);  //获取event的值
    void                  getEventValue(std::any& p);  //获取event的值
    std::function<void(const Photon::Event::Event&)> callback;

  private:
    std::map<std::pair<Photon::Event::MsgType, Photon::Event::MsgOrigin>,
             const std::any&>
        data;//填空
    friend class Control::ControlBase;
};
}  // namespace Photon::Event
