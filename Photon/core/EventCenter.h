//
// Created by skywards on 2/10/22.
//

#ifndef PHOTONDEMO_EVENTCENTER_H
#define PHOTONDEMO_EVENTCENTER_H

#include "../pch.h"
#include "Event.h"
#include "Data.h"
namespace Photon::Event
{
	class EventCenter
	{
	public:
		EventCenter();
		~EventCenter();
		void addProvider(Photon::Event::MsgOrigin mo, std::function<Data::Data()> f);
		void update();			//用于事件更新
		bool checkOrigin(Photon::Event::MsgOrigin mo);  //	用于检查是否支持此来源的获取
		EventUnit getEvent(MsgOrigin mo);

	private:
		std::map<Event::MsgOrigin, std::function<Data::Data()>> providers;
		std::map<Event::MsgOrigin, EventUnit> events;		//用来存储最新的东西


	};
}

#endif // PHOTONDEMO_EVENTCENTER_H
