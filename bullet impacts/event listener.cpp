#include "event listener.hpp"
#include "interfaces.hpp"

EventListener::EventListener(std::string eventName, Callback_t callback)
{
	m_EventName = eventName;
	m_Callback = callback;
	interfaces.gameEventManager->addListener(this, eventName.c_str());
}
EventListener::~EventListener()
{
	interfaces.gameEventManager->removeListener(this);
}

void EventListener::FireGameEvent(GameEvent* event)
{
	if (event->getName() == m_EventName)
		m_Callback(event);
}

int EventListener::GetEventDebugID(void)
{
	return 42;
}