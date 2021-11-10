#include <iostream>
#include <Windows.h>
#include <string>
#include <stdlib.h>
using namespace std;
bool IsClicking;
int x;
int y;

void autoClicker() {
    while (true)
    {
        if (GetAsyncKeyState(VK_NUMPAD1))
        {
            Sleep(100);
            POINT cursorPos;
            GetCursorPos(&cursorPos);
            x = cursorPos.x;;
            y = cursorPos.y;
            std::cout << "[X] " << x << endl;
            std::cout << "[Y] " << y << endl;
        }
        if (GetAsyncKeyState(VK_ESCAPE))
        {
            system("CLS");
            std::cout << "[-] Autoclicker is now Closing";
            Sleep(1000);
            exit(0);
        }
        if (GetAsyncKeyState(VK_NUMPAD2))
        {
            std::cout << "[+] Clicking\n";
            Sleep(100);
            IsClicking = true;

            while (true)
            {

                if (!IsClicking)
                {
                    break;
                }
                //Sleep(100);
                SetCursorPos(x, y);
                mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
                mouse_event(MOUSEEVENTF_LEFTUP, x, y, 0, 0);

                if (GetAsyncKeyState(VK_NUMPAD3))
                {
                    IsClicking = false;
                    std::cout << "[-] AutoClicker is Stopping";
                }
                
                if (GetAsyncKeyState(VK_ESCAPE))
                {
                    std::cout << "[-] Autoclicker is now Closing";
                    Sleep(1000);
                    exit(0);
                }
            }
        }
    }
}

void initGUI() {
    IsClicking = false;
    system("TITLE Retro's AutoClicker V1");
    std::cout << "[ HOTKEYS ]\n\n";
    std::cout << "[ Numpad 1 ] Save Mouse Pos\n";
    std::cout << "[ Numpad 2 ] Activate AutoClicker on Saved Pos\n";
    std::cout << "[ Numpad 3 ] Stop AutoClicker\n";
    std::cout << "[ Escape ] Close Program\n\n\n";
    autoClicker();
}

int main()
{
    initGUI();
}

