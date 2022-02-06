#include "ControlBase.h"

Photon::Control::ControlBase::ControlBase() {}
Photon::Control::ControlBase::~ControlBase() {}
void Photon::Control::ControlBase::registerEvent(
    Event::MsgOrigin mo, Event::MsgType mt,
    std::function<void( const Photon::Event::Event * )> callback ) {
    Event::Event te;
    te.callback = callback;
    std::any *p;

    if ( rWindow->eventData.count( mo ) == 0 ) {
        rWindow->eventData[ mo ] = std::any( NULL );
    }
    p              = &( rWindow->eventData[ mo ] );
    dataTemp[ mo ] = p;

    rWindow->subControlEvents[ mo ][ mt ].push_back( this );
}
void Photon::Control::ControlBase::spreadEvent() {
    while ( !eventQuene.empty() ) {
        eventQuene.pop_back();
    }
}

void Photon::Control::ControlBase::receiveEvent( Event::MsgOrigin mo ) {
    eventQuene.push_back( mo );
}
