#pragma once
#include "Object.h"
#include "FString.h"
#include <ShObjIdl_core.h>

namespace Core
{
	class BoxFile : public Object 
	{
#pragma region f/p
	private:
		const char* title = "find path";
		PrimitiveType::FString pathResult = ""; 
		HRESULT hResult = HRESULT(); 
#pragma endregion f/p
#pragma region constructor/destructor
	public:
		O3DLIBRARY_API BoxFile() = default; 
		O3DLIBRARY_API BoxFile(const char* _title);
		O3DLIBRARY_API BoxFile(const BoxFile& _copy);
		O3DLIBRARY_API ~BoxFile() override = default;
#pragma endregion constructor/destructor
#pragma region methods
	private: 
		O3DLIBRARY_API bool InitializeBox();
		O3DLIBRARY_API bool CreateInstanceDialog(IFileOpenDialog*& _fileOpen); 
		O3DLIBRARY_API bool OpenFile(IFileOpenDialog* _fileOpen, IShellItem*& _item); 
		O3DLIBRARY_API bool GetDisplayName(IShellItem* _item, PWSTR& _filePath);
		O3DLIBRARY_API void SaveResult(IFileOpenDialog* _fileOpen, IShellItem* _item, PWSTR _filePath);
	public:
		O3DLIBRARY_API void Open();
		O3DLIBRARY_API Core::PrimitiveType::FString Result() const;

#pragma endregion methods
	};

}

