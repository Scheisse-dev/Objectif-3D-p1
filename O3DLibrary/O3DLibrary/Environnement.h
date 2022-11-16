#pragma once
#include "Object.h"
#include <filesystem>
#include "FString.h"

namespace Core
{
	enum class ESpecialFolder
	{
		Desktop = 0x0000,
		Programs = 0x0002,
		MyDocuments = 0x0005,
		MyMusic = 0x000d,
		MyVideo = 0x000e,
		LocalAppData = 0x001c,
		ProgramsFiles = 0x0026,
		MyPicture = 0x0027,
		Profile = 0x0028,
		ProgramFilesx86 = 0x002a

		
	};
	class Environnement : public Object
	{
	public: 
		O3DLIBRARY_API static const inline PrimitiveType::FString CurrentDirectory = std::filesystem::current_path().string().c_str();
		O3DLIBRARY_API static PrimitiveType::FString SpecialFolder(const ESpecialFolder& _specialFolder);
	};

}