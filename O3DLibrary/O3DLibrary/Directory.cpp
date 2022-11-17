#include "Directory.h"
#include "FString.h"
#include "Boolean.h"
#include "Exception.h"
#include <direct.h>


#pragma region methods
O3DLIBRARY_API void Core::IO::Directory::MakeDirectory(const Core::PrimitiveType::FString& _path)
{
	if (Exist(_path)) return;
	if(_mkdir(_path.ToCstr()) != 0)
		throw Exception("error when creating the directory !");

	
}

O3DLIBRARY_API Core::PrimitiveType::Boolean Core::IO::Directory::Exist(const Core::PrimitiveType::FString& _path)
{
	struct stat _info; 
	if (stat(_path.ToCstr(), &_info) != 0) return false;
	return _info.st_mode & S_IFDIR; 
}
#pragma endregion methods