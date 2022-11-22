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
#include <Window.h>

using namespace Core::PrimitiveType;
using namespace Core::IO;
using namespace Core;

template<typename Base, typename Derived>
static bool InstanceOf(const Derived*)
{
    return std::is_same<Base, Derived>::value;
}

#define instanceof(a,b) InstanceOf<a>(b)

int main()
{
	//Core::BoxFile box = Core::BoxFile("Test");
	//box.Open();
	//LOG(box.Result()); 
    //Object* o = new Object(); 
    //DateTime* time = new DateTime(0, 0, 0);

    //if (instanceof(Object, o))
    //{
    //    std::cout << "o is an object" << std::endl; 
    //}
    //if (instanceof(Object, time))
    //{
    //    std::cout << "time is object" << std::endl;
    //}
    //if (instanceof(DateTime, time))
    //{
    //    std::cout << "time is DateTime" << std::endl;
    //}

    //return 0; 

 

 //   int msgboxID = MessageBox(
 //       NULL,
 //       (LPCWSTR)L"enfin j'ai réussi",
 //       (LPCWSTR)L"Yolo",
 //       MB_ICONASTERISK |MB_DEFBUTTON2
 //   );

	//return msgboxID;

    Window window = Window(PrimitiveType::FString("Test"), 900, 800);
    window.Open(); 
    return 0; 

}
