#include "EventCenter.h"
bool Photon::Event::EventCenter::checkOrigin(Photon::Event::MsgOrigin mo)
{
	return (providers.count(mo) == 0) ? false : true;
}
void Photon::Event::EventCenter::update()
{
	for (auto &i : providers)
	{
		EventUnit &eu = events[i.first];
		Data::Data temp = i.second();

		events[i.first].Mt = (eu.body == temp) ? MsgType::Remain : MsgType::Changed;
		if (eu.Mt == MsgType::Changed)
		{
			eu.body = temp;
		}
	}
}
Photon::Event::EventUnit Photon::Event::EventCenter::getEvent(MsgOrigin mo)
{
	return events[mo];
}
void Photon::Event::EventCenter::addProvider(Photon::Event::MsgOrigin mo, std::function<Data::Data()> f)
{
	if (checkOrigin(mo))
		static_assert("不能重复添加Providers");
	else
	{
		providers.insert(std::make_pair(mo, f));
	}
}