#ifndef UNICODE
#define UNICODE
#endif 

#include <windows.h>


const wchar_t CLASS_NAME[] = L"Sample Window Class";

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_SIZE:
    {
        int width = LOWORD(lParam);  // Macro to get the low-order word.
        int height = HIWORD(lParam); // Macro to get the high-order word.
    }
    break;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}




int main()
{
    WNDCLASS wc = {};

    wc.lpfnWndProc = WindowProc;
    wc.hInstance = nullptr;
    wc.lpszClassName = CLASS_NAME;

    HWND hwnd = CreateWindowEx(
        0,                              // Optional window styles.
        CLASS_NAME,                     // Window class
        L"Learn to Program Windows",    // Window text
        WS_OVERLAPPEDWINDOW,            // Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

        NULL,       // Parent window    
        NULL,       // Menu
        nullptr,      // Instance handle
        NULL        // Additional application data
    );
    ShowWindow(hwnd, 10);
    
}
