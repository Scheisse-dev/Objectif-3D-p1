#include "File.h"
#include <fstream>
#include <string>
std::vector<std::string> File::GetAllLines(const std::string& _path)
{
    std::ifstream _stream = std::ifstream(_path); 
    if (!_stream.good()) throw std::exception("invalid path or path not found");
    std::vector<std::string> _result = std::vector<std::string>(); 
    std::string _line = "";
    while (std::getline(_stream, _line))
        _result.push_back(_line);
    return _result; 

    
}
