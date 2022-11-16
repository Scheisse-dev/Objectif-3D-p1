#include "Process.h"
#include "FString.h"
#include "Boolean.h"
#include <ShlObj_core.h>
#include <ShObjIdl_core.h>

O3DLIBRARY_API void Core::Diagnostics::Process::Start(const Core::PrimitiveType::FString& _path, const Core::PrimitiveType::FString& _parameters)
{
	if (PrimitiveType::FString::IsNullOrEmpty(_path)) return;
	const std::wstring _pathToOpen = _path.ToWString(); 
	const std::wstring _params = _parameters.ToWString(); 
	ShellExecute(nullptr, nullptr, _pathToOpen.c_str(), _params.c_str(), nullptr, SW_SHOWNORMAL);
}
