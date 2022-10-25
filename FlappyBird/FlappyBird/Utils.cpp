#include "Utils.h"
#include "Object.h"
#include <windows.h>
#include <conio.h>


#pragma warning (disable : 4996) 


int Utils::CinNoBlock()
{
    if (kbhit())
    {
        return getch(); 
    }
    return -1;
}

void Utils::LoadingBar(const std::string& _msg)
{
    float _progress = 0.0f;
    const int _barWidth = 70;
    while (_progress < 1.0f)
    {
        std::cout << "[";
        int _pos = _barWidth * _progress;
        for (int i = 0; i < _barWidth; i++)
        {
            if (i < _pos) std::cout << "=";
            else if (i == _pos) std::cout << ">";
            else std::cout << " ";
        }
        std::cout << "] " << int(_progress * 100.0f) << " % " << _msg << "\r";
        std::cout.flush();
        _progress += 0.001f;
    }
}


void Utils::SetCursorPosition(const int _x, const int _y)
{
    cursorPosition.X = _x;
    cursorPosition.Y = _y; 
    SetConsoleCursorPosition(console, cursorPosition);
}


std::string Utils::Underline(const std::string& _str)
{
    int _tabCount = 0, _count = 0;
    for (char _c : _str)
    {
        if (_c == '\t')
        {
            _tabCount++;
            continue;
        }
        _count++;
    }
    return std::string(_tabCount, '\t') + std::string(_count, '-');
}

void Utils::ClearConsole()
{
    system("cls");
}

void Utils::Pause()
{
    system("pause");
}

std::string Utils::Separator(const int _count, const char _c)
{
    return std::string(_count, _c);
}