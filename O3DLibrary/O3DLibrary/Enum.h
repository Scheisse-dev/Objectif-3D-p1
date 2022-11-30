#pragma once
#include <string>
#include <map>
#include <sstream>
#include <vector>
namespace Core
{
	struct EnumSupportBase
	{
		static void Trim(std::string& str)
		{
			size_t _startPos = 0;
			std::string _from = " ";
			std::string _to = "";
			while ((_startPos = str.find(_from, _startPos)) != std::string::npos)
			{
				str.replace(_startPos, _from.length(), _to); 
				_startPos += _to.length();
			}
		}
		static std::map<int, std::string> Split(const std::string& _str)
		{
			std::stringstream _ss(_str); 
			std::string _item = "";
			std::map<int, std::string> _result = std::map<int, std::string>();
			int _currentIndex = -1;
			size_t _pos = 0;
			while (std::getline(_ss, _item, ','))
			{
				std::string _value = _item;
				Trim(_value); 
				_pos = _value.find_first_of('=');
				if (_pos != std::string::npos)
				{
					_currentIndex = std::stoi(_value.substr(_pos + 1));
					_item.erase(_pos+1);
				}
				else _currentIndex++;
				Trim(_item); 
				_result.insert(std::pair(_currentIndex, _item)); 
			}
			return _result; 
		}
	};

#define ENUM(Name, ...)\
	enum class Name : int {__VA_ARGS__};\
	struct Name##Support : EnumSupportBase\
	{\
		static inline std::map<int,std::string> values = Split(#__VA_ARGS__);\
		static constexpr std::string GetName(Name value)\
		{\
			const int _index = (int)value;\
			return values[_index];\
		}\
		static std::vector<Name> Values()\
		{\
			std::vector<Name> _result = std::vector<Name>();\
			for(std::pair<int, std::string> _pair : values)\
			{\
				_result.push_back((Name)_pair.first);\
			}\
		return _result;\
		}\
	};\
	inline std::string operator*(const Name& value)\
		{return Name##Support::GetName(value);}
}
