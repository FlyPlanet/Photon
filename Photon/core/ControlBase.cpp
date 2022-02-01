#include "ControlBase.h"

Photon::Control::ControlBase::ControlBase() {}
Photon::Control::ControlBase::~ControlBase() {}
void Photon::Control::ControlBase::registerEvent(Event::Event* event)
{
    for (auto& i : event->data) {
        this->events[i.first.second].push_back(*event);
        this->fWindow.data[i.first.second] = NULL;
        this->dataTemp[i.first.second]     = &(fWindow.data[i.first.second]);
    }

}

void Photon::Control::ControlBase::changeData(Photon::Event::MsgOrigin ms,
                                              std::any data)
{
    *(this->dataTemp[ms]) = data;
    //可以通知各部门了
    for (auto& i : this->events[ms]) {
        i.callback(std::as_const(i));
    }
}