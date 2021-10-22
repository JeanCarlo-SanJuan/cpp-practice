#include <iostream>
#include <Windows.h>
#include <unistd.h>
using namespace std;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    wchar_t msg[32];
    switch (uMsg)
    {
    case WM_SYSKEYDOWN:
        swprintf_s(msg, L"WM_SYSKEYDOWN: 0x%x\n", wParam);
        OutputDebugString(msg);
        break;

    case WM_SYSCHAR:
        swprintf_s(msg, L"WM_SYSCHAR: %c\n", (wchar_t)wParam);
        OutputDebugString(msg);
        break;

    case WM_SYSKEYUP:
        swprintf_s(msg, L"WM_SYSKEYUP: 0x%x\n", wParam);
        OutputDebugString(msg);
        break;

    case WM_KEYDOWN:
        swprintf_s(msg, L"WM_KEYDOWN: 0x%x\n", wParam);
        OutputDebugString(msg);
        break;

    case WM_KEYUP:
        swprintf_s(msg, L"WM_KEYUP: 0x%x\n", wParam);
        OutputDebugString(msg);
        break;

    case WM_CHAR:
        swprintf_s(msg, L"WM_CHAR: %c\n", (wchar_t)wParam);
        OutputDebugString(msg);
        break;

    /* Handle other messages (not shown) */

    }
    return DefWindowProc(m_hwnd, uMsg, wParam, lParam);
}

int main() {
    string txt = "";
    for (;;) {

    }
/*     string txt = "";

    for (;;) {
        if (GetKeyState(0x4A)) {
            txt += "J";
            cout << txt;
        }
        if (GetKeyState(0x4B)) {
            txt += "K";
            cout << txt;

        }
        if (GetKeyState(0x53)) {
            txt += "S";
            cout << txt;

        }
        if (GetKeyState(0x59)) {
            txt += "Y";
            cout << txt;
        }

        if (txt == "JSYK") {
            cout << "Just So You Know";
        }
    } */

}