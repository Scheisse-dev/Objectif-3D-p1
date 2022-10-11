#include <iostream>
#include "invent.h"

int main()
{
    Invent<std::string> _invent = Invent<std::string>();
    _invent.Add("popo");

    _invent.Display();
}