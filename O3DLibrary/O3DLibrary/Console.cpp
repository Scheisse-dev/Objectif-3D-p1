#include "Console.h"
#include "FString.h"
#include "TextWritter.h"
#include "Path.h"
#include "Environnement.h"
#include "Directory.h"

Core::IO::TextWritter* Core::Console::Out = Out_Internal();

#pragma region methods
O3DLIBRARY_API Core::IO::TextWritter* Core::Console::Out_Internal()
{
	const PrimitiveType::FString& _directoryPath = IO::Path::Combine({ IO::Path::GetParent(Core::Environnement::CurrentDirectory), "App_Debug" });
	IO::Directory::MakeDirectory(_directoryPath);
	const PrimitiveType::FString& _fullPath = IO::Path::Combine({ _directoryPath, "Debug.log" });
	return new Core::IO::TextWritter(_fullPath.ToCstr());
}
O3DLIBRARY_API void Core::Console::WriterLine(const object _obj, const EConsoleColor _color)
{
	SetConsoleTextAttribute(console, (int)_color);
	std::cout << _obj->ToString() << std::endl; 
	*Out << _obj->ToString();
	SetConsoleTextAttribute(console, (int)EConsoleColor::Reset);
}

O3DLIBRARY_API void Core::Console::WriterLine(const Object& _obj, const EConsoleColor& _color)
{
	SetConsoleTextAttribute(console, (int)_color);
	std::cout << _obj.ToString() << std::endl;
	*Out << _obj.ToString();
	SetConsoleTextAttribute(console, (int)EConsoleColor::Reset);
}


#pragma endregion methods

