#include "File.h"
#include "../PrimaryType/String/String.h"
#include <fstream>

Engine::File::File(const std::string& _path)
{
    path = _path;
}

Engine::File::File(const File& _copy)
{
    path = _copy.path;
}

std::vector<Engine::PrimaryType::String> Engine::File::ReadAllLines() const
{
    std::ifstream _stream = std::ifstream(path);
    std::string _line = "";
    std::vector<PrimaryType::String> _result = std::vector<PrimaryType::String>();
    while (std::getline(_stream, _line))
        _result.emplace_back(_line.c_str());
    _stream.close();
    return _result;
}
