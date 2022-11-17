#include "Path.h"
#include "FString.h"
#include "Integer.h"


#pragma region methods
O3DLIBRARY_API Core::PrimitiveType::FString Core::IO::Path::GetPath(const PrimitiveType::FString& _path)
{
	return _path.Replace('\\', DirectorySeparator); 
}

O3DLIBRARY_API Core::PrimitiveType::FString Core::IO::Path::GetParent(const PrimitiveType::FString& _path)
{
	const PrimitiveType::FString _p = GetPath(_path); 
	const int _index = _p.LastIndexOf(DirectorySeparator); 
	return _path.SubString(0, _index);
}

O3DLIBRARY_API Core::PrimitiveType::FString Core::IO::Path::Combine(const std::initializer_list<PrimitiveType::FString>& _paths)
{
	PrimitiveType::FString _result = "";
	const size_t _size = _paths.size(); 
	int _index = 0;
	for (const PrimitiveType::FString& _item : _paths)
	{
		_result += _item; 
		if (_index < _size - 1)
			_result.Append(DirectorySeparator);
		_index++;

	}
	return GetPath(_result);
}
#pragma endregion methods