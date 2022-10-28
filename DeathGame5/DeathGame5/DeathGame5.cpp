#include <iostream>
#include <string>
#include <map> 

#pragma warning(disable: 4996)

std::string Replace(const std::string& _str, const std::string& _old, const std::string& _new)
{
	std::string _result = _str;
	size_t _pos = 0;
	while ((_pos = _result.find(_old, _pos)) != std::string::npos)
	{
		_result.replace(_pos, _old.size(), _new);
		_pos += _new.size();
	}
	return _result;
}

int MaxNum(const std::string& _str)
{
	const std::string _number = Replace(_str, " ", "");
	int* _tab = new int[_number.size()+1];

	for (int i = 0; i <= _number.size(); i++)
		_tab[i] = 0;

	for (int i = 0; i <= _number.size(); i++)
	{
		_tab[_number[i] - '0']++; 
	}

	int _result = 0, multiplier = 1; 

	for (int i = 0; i <= _number.size(); i++)
	{
		while (_tab[i] > 0)
		{
			_result += (i * multiplier);
			_tab[i]--;
			multiplier *= 10;
		}

	}

	return _result;
}
char* ToCharArray(const std::string& _str)
{
	char* _result = new char[_str.size() + 1];
	strcpy(_result, _str.c_str());
	return _result; 
}

//int n = 321;

//char* _array = ToCharArray(std::to_string(n)); 
//std::reverse(_array, _array + strlen(_array));
//std::cout << n - std::stoi(_array) << std::endl; 

int main()
{
	//1/2//3/4 = 2444 / map(1, 2)


	//for (int i = 0; i < _entry.size(); i++)
	//{
	//	for (int x = 0; x < i; x++)
	//	{
	//		_entry[x] = _entry[i];
	//		i++;
	//	}
	//}


	//std::cout << _entry << std::endl; 

	std::string _str = "1234";
	std::string _result = "";

	if (_str.size() % 2 != 0)
		throw std::exception();

	for (int i = 0; i < _str.length(); i += 2)
	{
		int _a = _str[i] - '0'; 
		_result += std::string(_a, _str[i + 1]);
	}
	std::cout << _result; 
}
