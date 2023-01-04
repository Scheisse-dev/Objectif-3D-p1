#pragma once
#include <string>


namespace Core
{
	namespace Utils
	{
		class Hash
		{
		public:
			template <typename T>
			static int GetObjectHashCode(const T& obj)
			{
				return obj.GetHashCode();
			}

			template <typename T>
			static int GetObjectHashCode(const T* obj)
			{
				return obj->GetHashCode();
			}

			template <typename T>
			static const char* GetObjectToString(const T* obj)
			{
				return obj->ToString();
			}
			template <typename T>
			static const char* GetObjectToString(const T& obj)
			{
				return obj.ToString();
			}



			static size_t HashCode(const char* _str)
			{

				size_t _result = 0;
				const size_t _length = std::strlen(_str);
				for (int i = 0; i < _length; i++)
				{
					int _multiplier = 1;
					for (int j = 0; j < _length; j++)
					{
						_multiplier += 31;
					}
					_result += _str[i] * _multiplier;
				}
				return _result;


			}
		};
	}
		
}