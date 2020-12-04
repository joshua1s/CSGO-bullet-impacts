#include <Windows.h>
#include <thread>
#include <iostream>
#include "interfaces.hpp"
#include "event listener.hpp"
#include "game events.hpp"

Interfaces interfaces;
EventListener* OnBulletImpact;

DWORD WINAPI OnDllAttach(LPVOID base)
{
    AllocConsole();
    freopen_s((FILE**)stdin, "CONIN$", "r", stdin);
    freopen_s((FILE**)stdout, "CONOUT$", "w", stdout);

    std::cout << "Waiting for serverbrowser.dll...\n";

    while (!GetModuleHandleA("serverbrowser.dll"))
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

    std::cout << "serverbrowser.dll found.\n";

    OnBulletImpact = new EventListener("bullet_impact", gameEvents::onBulletImpact);

    std::cout << "bullet_impact event listener created.\n";

    while (!GetAsyncKeyState(VK_DELETE))
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

    FreeLibraryAndExitThread(static_cast<HMODULE>(base), 0);
}

BOOL WINAPI OnDllDetach()
{
    OnBulletImpact->~EventListener();

    fclose((FILE*)stdin);
    fclose((FILE*)stdout);
    FreeConsole();
    PostMessageW(GetConsoleWindow(), WM_CLOSE, 0, 0);

    return TRUE;
}

BOOL WINAPI DllMain(HINSTANCE hinstDll, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason)
    {
    case DLL_PROCESS_ATTACH:
        DisableThreadLibraryCalls(hinstDll);
        CreateThread(nullptr, 0, OnDllAttach, hinstDll, 0, nullptr);
        return TRUE;
    case DLL_PROCESS_DETACH:
        if (lpvReserved == nullptr)
            return OnDllDetach();
        return TRUE;
    default:
        return TRUE;
    }
}
