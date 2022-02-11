
#include "Event.h"

Photon::Data::Data Photon::Event::Event::getEventValue() { return nullptr; }
Photon::Data::Data
    Photon::Event::Event::getEventValue( Photon::Event::MsgOrigin mo ) {
    return this->moData[ mo ];
}
EventUnit Photon::Event::Event::fetch() {
    boss->findNew( t ) return EventUnit();
}
void Photon::Event::Event::regisiter( EventCenter *ec ) {
    // TODO:记得去要货的地址
}
