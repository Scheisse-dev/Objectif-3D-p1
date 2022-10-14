#include "Screen.h"
#include "Path.h"
#include "Environment.h"
#include "File.h"
#include "Case.h"

void Screen::Init()
{
	const std::string& _path = Path::Combine(Environment::CurrentDirectory(), "Screen", "wall.txt");
	std::vector<std::string> _lines = File::GetAllLines(_path);

}

void Screen::Display()
{
	const size_t _size = cases.size();
	for (size_t i = 0; i < _size; i++)
	{
			std::cout << cases[i]->CaseValue();
	}
}
