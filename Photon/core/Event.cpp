#include "Event.h"
Photon::Event::Event::Event(
    std::initializer_list<
        std::pair<Photon::Event::MsgType, Photon::Event::MsgOrigin>> events)
{
    for (auto &i : events) {
        this->data.insert(std::make_pair(i,NULL));
    }
}