
#include "EventClient.h"

Photon::Data::Data Photon::Event::EventClient::getEventValue(
    Photon::Event::MsgOrigin mo) {
  return *this->moData[mo];
}
Photon::Event::EventUnit Photon::Event::EventClient::fetch(
    Photon::Event::MsgOrigin mo, Photon::Event::MsgType mt) {
  if (!registered) throw std::runtime_error("在没有注册事件的情况下fetch");
  return boss->findLatest(mo, mt);
}
void Photon::Event::EventClient::regisiter(EventCenter *ec) {
  this->registered = true;
  this->eventPosition = ec->checkClient(&this->moData);
  // TODO:记得去要货的地址
}
void Photon::Event::EventClient::addRequire(Photon::Event::MsgType mt,
                                            Photon::Event::MsgOrigin mo) {
  moData.insert(std::make_pair(mo, nullptr));
  moMt.insert(std::make_pair(mo, mt));
}
Photon::Event::EventClient::EventClient() {}
