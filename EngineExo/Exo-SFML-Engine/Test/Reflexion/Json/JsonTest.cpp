#include "JsonTest.h"
#include "../../Z.h"
#include "../../../Engine/Utils/DebugMacro.h"
#include <filesystem>
#include <fstream>

void Test::JsonTest::Test()
{
    const std::string _path = std::filesystem::current_path().string();
    Z a = Z();
    std::ofstream _outFile = std::ofstream(_path + "\\a.asset");
    a.Serialize(_outFile);
    _outFile.close();

    //A b = A();
    //std::ifstream _inFile(_path + "\\a.asset");
    //b.DeSerialize(_inFile);
    //_inFile.close();
}