#include "Directory.h"

bool Directory::DirectoryExist(const std::string& _path)
{
    struct stat _info = {};
    if (stat(_path.c_str(), &_info) != 0) return false;
    return _info.st_mode & S_IFDIR;
}
