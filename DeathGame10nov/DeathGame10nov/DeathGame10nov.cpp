#include <iostream>
#include <string>
#include <vector>

std::string Decrypt(const std::string& _crypted)
{
    std::string _str = _crypted;
    std::vector<char> _values = std::vector<char>();
    int _index = 0; 
    while (_str.size() > 0)
    {
        if (_index % 2 == 0)
        {
            _values.push_back(_str[0]);
            _str = _str.erase(0, 1);

        }
        else
        {
            _values.push_back(_str[_str.length() - 1]);
            _str = _str.erase(_str.length() - 1, 1);
        }
        _index++;

    }
    return std::string(_values.begin(), _values.end());

}

int main()
{
    std::cout << Decrypt("Ioeoig !ndcvl");
   
}
