#include <iostream>
//067111100105110103 => Coding
//67 111 100 105 110 103
// C  o   d   i   n   g 
// char = nombre = 3 chiffres 
//int a = 10;
// int b = 5;
// int c = a % b; modulo donc reste de la division 
//


int main()
{
	std::string _code = "067111100105110103";
	if(_code.size() % 3 != 0)
	{
		std::cout << "ERROR" << std::endl;
		return 0; 
	}
	std::string _result = ""; 
	int _index = 0; 
	for (int i = 3; i <= _code.size(); i += 3)
	{
		std::string _str = _code.substr(_index, 3); 
		_index = i; 
		int _value = std::atoi(_str.c_str()); 
		_result += (char)_value;
	}
	std::cout << _result << std::endl; 
}

