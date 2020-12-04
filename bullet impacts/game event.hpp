#pragma once
#include "virtual method.hpp"

class GameEvent 
{
public:
    VIRTUAL(const char*, getName, 1, (), (this))
    VIRTUAL(int, getInt, 6, (const char* keyName, int defaultValue = 0), (this, keyName, defaultValue))
    VIRTUAL(float, getFloat, 8, (const char* keyName, float defaultValue = 0.0f), (this, keyName, defaultValue))
    VIRTUAL(const char*, getString, 9, (const char* keyName, const char* defaultValue = ""), (this, keyName, defaultValue))
    VIRTUAL(void, setString, 16, (const char* keyName, const char* value), (this, keyName, value))
};

class GameEventListener 
{
public:
    virtual ~GameEventListener() {}
    virtual void fireGameEvent(GameEvent* event) = 0;
    virtual int getEventDebugId() { return 42; }
};

class GameEventManager 
{
public:
    VIRTUAL(bool, addListener, 3, (void* listener, const char* name), (this, listener, name, false))
    VIRTUAL(void, removeListener, 5, (void* listener), (this, listener))
};
