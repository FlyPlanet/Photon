#include "ControlBase.h"

Photon::Control::ControlBase::ControlBase() {}
Photon::Control::ControlBase::~ControlBase() {}
void Photon::Control::ControlBase::AddChild(Photon::Control::ControlBase *in) {
  this->children.push_back(in);
}
void Photon::Control::ControlBase::DelChild(Photon::Control::ControlBase *in) {
  //老子不会写
}
