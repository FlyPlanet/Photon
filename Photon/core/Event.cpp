
#include "Event.h"

Photon::Data::Data
    Photon::Event::Event::getEventValue( Photon::Event::MsgOrigin mo ) {
    return this->moData[ mo ];
}
EventUnit Photon::Event::Event::fetch() {
  if (!registered) throw std::runtime_error("在没有注册事件的情况下fetch");
  return boss->findNew(this->eventPosition);
}
void Photon::Event::Event::regisiter(EventCenter *ec) {
  this->eventPosition = ec->checkClient(&this->moData);
  // TODO:记得去要货的地址
}
void Photon::Event::Event::addRequire(Photon::Event::MsgType mt,
                                      Photon::Event::MsgOrigin mo) {
  moData.insert(std::make_pair(mo, nullptr));
  moMt.insert(std::make_pair(mo, mt));
}
