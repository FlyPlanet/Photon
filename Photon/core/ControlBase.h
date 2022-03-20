#pragma once

#include "../pch.h"
#include "Event.h"
#include "Window.h"
#include "Action.h"
#include "EventCenter.h"

namespace Photon::Control
{
	class ControlBase
	{
	public:
		ControlBase();
		~ControlBase();
		void AddChild(ControlBase *in);
		void DelChild(ControlBase *in);
		Photon::Window::Window *rWindow;
		std::vector<ControlBase *> children;

		std::map<Photon::Event::MsgOrigin, std::any *>
			MsgdataTemp; //数据位置第二节点,本体在window

		//一些关于消息传递的东西
		Event::EventCenter *ec;  //要想办法填充好这个指针
		void AddAction(Action::Action a);
		void runAction();
		std::vector<Action::Action> actions;

		//关于渲染相关的东西
		Photon::Shader shader;

	protected:
	};
} // namespace Photon::Control