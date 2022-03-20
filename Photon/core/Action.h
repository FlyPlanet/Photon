//
// Created by skywards on 2/25/22.
//
#pragma once
#ifndef PHOTONDEMO_ACTION_H
#define PHOTONDEMO_ACTION_H
#include "../pch.h"
#include "Event.h"
#include "Data.h"

namespace Photon::Action
{
	class Action
	{
	public:
		void addRequire(Event::MsgOrigin mo,Event::MsgType mt);
		void act();
		
		

	private:
		friend void Control::ControlBase::AddAction(Action::Action a);
		std::function<void(std::function<Data::Data(int)>)> body;
		std::map<Event::MsgOrigin, std::vector<Event::MsgType>> require;
		
	};
} // namespace Photon::Action
#endif // PHOTONDEMO_ACTION_H
