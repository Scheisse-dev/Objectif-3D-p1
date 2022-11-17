#pragma once
#include "Object.h"

namespace Core
{
	namespace IO
	{
		class TextReader;
		class TextWritter; 

		class FileStream : public Object
		{
#pragma region f/p
		private:
			const char* path = ""; 
			TextReader* reader = nullptr; 
			TextWritter* writter = nullptr; 

#pragma endregion f/p
#pragma region constructor/desructor
		public:
			O3DLIBRARY_API FileStream() = default;
			O3DLIBRARY_API FileStream(const char* _path);
			O3DLIBRARY_API FileStream(const FileStream& _copy);
			O3DLIBRARY_API ~FileStream() override;
#pragma endregion constructor/desructor
#pragma region methods
		public: 
			O3DLIBRARY_API void Close();
			O3DLIBRARY_API TextReader* Reader() const;
			O3DLIBRARY_API TextWritter* Writter() const;
			O3DLIBRARY_API PrimitiveType::FString Path() const;
			O3DLIBRARY_API PrimitiveType::Boolean Equals(const FileStream& _other) const;
#pragma endregion methods
#pragma region override
		public:
			O3DLIBRARY_API PrimitiveType::FString ToString() const override;
			O3DLIBRARY_API PrimitiveType::Boolean Equals(const Object* _obj) const override;
#pragma endregion override
#pragma region operator
		public: 
			void operator<<(const Object* _obj);
			void operator<<(const Object& _obj);
#pragma endregion operator
		};
	}
}