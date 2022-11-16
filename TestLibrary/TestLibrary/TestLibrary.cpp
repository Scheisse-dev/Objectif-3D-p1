
#include "Object.h"
#include <iostream>
#include <FString.h>
#include <Process.h>
#include <iomanip>
#include <Environnement.h>
#include <Integer.h>


using namespace Core;
using namespace PrimitiveType;

int main()
{
	const FString _path = "C:\\Users\\GAUT2905\\AppData\\Local\\Programs\\Opera GX\\launcher.exe";
	Core::Diagnostics::Process::Start(_path, "https://facebook.com"); 
	return 0;
}
