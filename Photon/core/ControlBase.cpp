#include "ControlBase.h"

Photon::Control::ControlBase::ControlBase() {}
Photon::Control::ControlBase::~ControlBase() {}
void Photon::Control::ControlBase::AddChild(Photon::Control::ControlBase *in)
{
	this->children.push_back(in);
}
void Photon::Control::ControlBase::DelChild(Photon::Control::ControlBase *in)
{
	//老子不会写
}
void Photon::Control::ControlBase::AddAction(Action::Action a)
{
	//首先还是要检查能否满足所有的需求
	//是加了友元的，下面如果require报错的话，没关系
	for(auto &i:a.require){
		if(!this->ec->checkOrigin(i.first)) static_assert("无法满足的action");
	}
	this->actions.push_back(a);
	
}
void Photon::Control::ControlBase::runAction(){
	
}