#include <iostream>
#include "Environment.h"
#include "Utils.h"
#include "StringUtils.h"
#include "Path.h"
#include "Directory.h"
#include "File.h"
#include "FileReader.h"
#include "FileWriter.h"
#include "FileStream.h"

int main()
{
	FileStream* _stream = File::Create("D:\\Exo\\TraductionExo\\GameSave.exe");
	_stream->Writer()->Write("PlayerName: TOto");



	std::vector<std::string> _allLines = _stream->Reader()->GetAllLines();
	for (int i = 0; i < _allLines.size(); i++)
		Utils::Log(_allLines[i]);
	_stream->Close();
}