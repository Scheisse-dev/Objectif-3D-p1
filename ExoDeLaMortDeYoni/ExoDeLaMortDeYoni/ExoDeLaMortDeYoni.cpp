#include <iostream>
#include <string>



std::string dict = "poiuytrewq123456789";
std::string text = "I like to code"; 
std::string key = "iw3";

std::string InToOut(std::string _entry)
{
	std::string _result = ""; 
	for (int i = 0; i < _entry.size(); i++)
	{
		for (int x = 0; x < dict.size(); x++)
		{
			if (_entry[i] == dict[x])
				_result += text[x];
		}
	}
	return _result;

}
int main()
{
	for (char c : key)
	std::cout << text[dict.find(c)]; 
}
