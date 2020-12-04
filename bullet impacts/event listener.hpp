#pragma once
#include <string>
#include "game event.hpp"

class IGameEventListener2
{
public:
	virtual ~IGameEventListener2() {};
	virtual void FireGameEvent(GameEvent* Event) = 0;
	virtual int GetEventDebugID() = 0;
};

class EventListener : public IGameEventListener2
{
	typedef void(*Callback_t)(GameEvent*);

private:
	EventListener() = delete;
	EventListener(EventListener&) = delete;

protected:
	std::string m_EventName;
	Callback_t	m_Callback;

public:
	EventListener(std::string eventName, Callback_t callback);
	~EventListener();
	virtual void FireGameEvent(GameEvent* event);
	int GetEventDebugID(void) override;
};