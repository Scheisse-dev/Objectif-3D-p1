#include "Object.h"
#include <iostream>
#include <FString.h>
#include <Process.h>
#include <iomanip>
#include <Environnement.h>
#include <Integer.h>
#include <Console.h>
#include <DateTime.h>
#include <EDayOfWeek.h>


using namespace Core;
using namespace PrimitiveType;
using namespace Core::IO;
 
int main()
{
	DateTime date = DateTime(17, 11, 2022);
	date.AddYears(1000);
	Console::WriterLine(*date.DayOfWeek());
	return 0;
}
