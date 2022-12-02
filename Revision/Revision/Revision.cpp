#include <iostream>
#include <Windows.h>
#include <string>
#include "Window\Window.h"
#include "Window\WindowItem\WindowItem.h"

int main()
{
	std::vector<Gdiplus::PointF> _points = std::vector<Gdiplus::PointF>(120);
	Window window = Window(std::string("Test"), 900, 800); 
	window.Register(new RectangleShape({ 10,10 }, 200, 100));
	window.Open(); 


}

