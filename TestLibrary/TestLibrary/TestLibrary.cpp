#include <Object.h>
#include <iostream>
#include <FString.h>
#include <Process.h>
#include <Windows.h>
#include <iomanip>
#include <Environnement.h>
#include <Integer.h>
#include <Console.h>
#include <DateTime.h>
#include <EDayOfWeek.h>
#include <BoxFile.h>
#include <Window.h>
#include <RectangleShape.h>
#include <CircleShape.h>
#include <ComplexShape.h>
#include <vector>
#include <FieldInfo.h>
#include <MethodsInfo.h>
#include <ParameterInfo.h>
#include <Enum.h>
#include <ClipBoard.h>


//
//using namespace Core::PrimitiveType;
//using namespace Core::IO;
//using namespace Core;
//
//template<typename Base, typename Derived>
//static bool InstanceOf(const Derived*)
//{
//    return std::is_same<Base, Derived>::value;
//}
//
//#define instanceof(a,b) InstanceOf<a>(b)
//
//
//class A  : public Object
//{
//public: 
////private:
////    PrimitiveType::FString name = "";
////public: 
////    PrimitiveType::Integer age = 20; 
////    int Test()
////    {
////        return 0;
////    }
////public:
////    A()
////    {
////        REGISTER_FIELD("name", &name, (int)BindingFlags::Private);
////        RegisterField("age", &age, (int)BindingFlags::Public);
////    }
//    void Test(const FString& msg, const FString& a)
//    {
//        LOG(msg);
//        LOG(a);
//    }
//    REGISTER_METHOD(Test, &A::Test, this, std::vector<ParameterInfo>({ ParameterInfo("msg", "FString", 0), ParameterInfo("a", "FString", 1) }));
//};
//
////#define GetName(var) #var
////FString operator*(FString type)
////{
////   return GetName(type);
////}
//
//
//
//
//
//
//
//ENUM(Type, Int = 5, Float = 15);
//
//int main()
//{
//    //std::cout << *Type::Int << std::endl;
//    //std::cout << (int)Type::Float << std::endl;
//    //return 0; 
//
//
//    
//
//
//
//
//
//
//
//	//Core::BoxFile box = Core::BoxFile("Test");
//	//box.Open();
//	//LOG(box.Result()); 
//    //Object* o = new Object(); 
//    //DateTime* time = new DateTime(0, 0, 0);
//
//    //if (instanceof(Object, o))
//    //{
//    //    std::cout << "o is an object" << std::endl; 
//    //}
//    //if (instanceof(Object, time))
//    //{
//    //    std::cout << "time is object" << std::endl;
//    //}
//    //if (instanceof(DateTime, time))
//    //{
//    //    std::cout << "time is DateTime" << std::endl;
//    //}
//
//    //return 0; 
//
// 
//
// //   int msgboxID = MessageBox(
// //       NULL,
// //       (LPCWSTR)L"enfin j'ai réussi",
// //       (LPCWSTR)L"Yolo",
// //       MB_ICONASTERISK |MB_DEFBUTTON2
// //   );
//
//	//return msgboxID;
//
//    
//    //std::vector<Gdiplus::PointF> _points = std::vector<Gdiplus::PointF>(120);
//    //Window window = Window(PrimitiveType::FString("Test"), 900, 800);
//    //window.Register(new RectangleShape({ 10,10 }, 200, 100));
//    //window.Register(new CircleShape({ 10,120 }, 100));
//    //window.Register(new ComplexShape(_points));
//    ////window.Open(); 
//    //Object o = Object();
//    //o.Register("name", 1, 1);
//
//    //A a;
//    //LOG(a.age);
//    //a.SetFieldValue("age", new PrimitiveType::Integer(10)); 
//    //LOG_WARNING(a.GetFields(BindingFlags::Public)[0]->ReflectedObject()); 
//    //LOG(a.age);
//    //return 0;
//
//    A a;
//    MethodInfo<void, const FString& , const FString&>* method = a.GetMethod<void, const FString&, const FString&>("Test");
//    if (method == nullptr)
//    {
//        std::cout << "Function null";
//        return -1;
//    }
//    for (ParameterInfo _params : method->Parameters())
//    {
//        std::cout << "Type " << _params.TypeName() << ", param name : " << _params.Name() << " position: " << _params.Position();
//    }
//    return 0;
//
//    
//}

#include <TimeZone.h>
#include <Hash.h>
#include <Map.h>
#include <KeyValuePair.h>
#include <WebClient.h>
#include <Uri.h>

using namespace Core;
using namespace PrimitiveType;
using namespace Collections; 
using namespace Net;

int main()
{   
	//Map<Integer, FString> map = Map<Integer, FString>
	//{
	//	{0, "Hello"},
	//	{1000, "World"}
	//};

	//LOG(map[0]);
	//LOG(map[1000]);

	//map.Remove(0);

		WebClient _request = WebClient(Uri("https://s50.notube.io/download.php?token=f11212534b5bb7b69220a888e6c7e3eb"));
		_request.DownloadFile("D:/P1.mp4");


}