#include <Object.h>
#include <iostream>
#include <FString.h>
#include <Process.h>
#include <iomanip>
#include <Environnement.h>
#include <Integer.h>
#include <Console.h>
#include <DateTime.h>
#include <EDayOfWeek.h>
#include <BoxFile.h>

using namespace Core::PrimitiveType;
using namespace Core::IO;

 
int main()
{
	//Core::BoxFile box = Core::BoxFile("Test");
	//box.Open();
	//LOG(box.Result()); 
	
    int msgboxID = MessageBox(
        NULL,
        (LPCWSTR)L"enfin j'ai réussi",
        (LPCWSTR)L"Yolo",
        MB_ICONASTERISK |MB_DEFBUTTON2
    );

	return msgboxID;
}
