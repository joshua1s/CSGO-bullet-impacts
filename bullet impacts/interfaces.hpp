#pragma once
#include <Windows.h>
#include <type_traits>
#include <thread>
#include <iostream>
#include "debug overlay.hpp"
#include "engine.hpp"
#include "entity.hpp"
#include "game event.hpp"

class Interfaces
{
public:

    DebugOverlay* debugOverlay = find<DebugOverlay>(L"engine", "VDebugOverlay004");
    Engine* engine = find<Engine>(L"engine", "VEngineClient014");
    EntityList* entitylist = find<EntityList>(L"client", "VClientEntityList003");
    GameEventManager* gameEventManager = find<GameEventManager>(L"engine", "GAMEEVENTSMANAGER002");

private:

    template <typename T>
    static auto find(const wchar_t* _module, const char* name) noexcept
    {
        //interfaces are initalized first
        while (!GetModuleHandleA("serverbrowser.dll"))
            std::this_thread::sleep_for(std::chrono::milliseconds(100));

        if (HMODULE moduleHandle = GetModuleHandleW(_module))
            if (const auto createInterface = reinterpret_cast<std::add_pointer_t<T*(const char* name, int* returnCode)>>(GetProcAddress(moduleHandle, "CreateInterface")))
                if (T* foundInterface = createInterface(name, nullptr))               
                    return foundInterface;
                
        exit(EXIT_FAILURE);
    }
};

extern Interfaces interfaces;