#include "JsonTest.h"
#include "../../A.h"
#include "../../C.h"
#include <iostream>
#include <filesystem>
#include <fstream>

void Test::JsonTest::JTest()
{
	A a = A();
	const std::string _path = std::filesystem::current_path().parent_path().string();
	std::ofstream _outFile = std::ofstream(_path + "\\a.asset");
	a.Serialize(_outFile);
	_outFile.close();
	//std::ifstream _inFile = std::ifstream(_path + "\\a.asset");
	//a.DeSerialize(_inFile);
	//_inFile.close();



}
