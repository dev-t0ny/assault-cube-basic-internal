#include "framework.h"


void processAttach()
{
    while (true) {
        if (GetAsyncKeyState(VK_INSERT))
        {
            DWORD* playerBase = (DWORD*)0x57E0A8;
            DWORD* playerHealth = (DWORD*)(*playerBase + 0xEC);
            *playerHealth = 9999;        

            DWORD* playerAmmo = (DWORD*)(*playerBase + 0x140);
            *playerAmmo = 9999;

            DWORD* playerArmor = (DWORD*)(*playerBase + 0xF0);
            *playerArmor = 9999;
        }

        Sleep(1);
    }
    
}


BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)processAttach, NULL, 0, NULL);
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}


