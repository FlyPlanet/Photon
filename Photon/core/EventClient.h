#pragma once

#include "../pch.h"
#include "EventCenter.h"
#include "Msg.h"
namespace Photon::Event {
class EventClient {
 public:
  EventClient();
  void addRequire(Photon::Event::MsgType mt, Photon::Event::MsgOrigin mo);
  void regisiter(EventCenter *ec);
  EventUnit fetch(Photon::Event::MsgOrigin mo,
                  Photon::Event::MsgType mt);  //进点新货
  Photon::Data::Data getEventValue(
      Photon::Event::MsgOrigin mo);  //获取event的值
 private:
  bool registered = false;
  EventCenter *boss;      //货源
  int eventPosition = 0;  //新货的地址
  std::map<Photon::Event::MsgOrigin, Photon::Data::Data *> moData;
  std::map<Photon::Event::MsgOrigin, Photon::Event::MsgType> moMt;
};
}  // namespace Photon::Event
