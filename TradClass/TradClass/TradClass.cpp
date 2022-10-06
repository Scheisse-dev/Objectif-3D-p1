#include <iostream>
#include "Environnement.h" 
#include "Utils.h"
#include "StringUtils.h" 
#include "Path.h"
#include "Directory.h"
#include "FileReader.h"
#include "FileWriter.h"
#include "FileStream.h"
#include "File.h"

int main()
{
	/*if (Directory::Exist(Environnement::CurrentDirectory()))
		Utils::Log("exist !"); 
	Directory::Create(Path::GetPath("C:\\Test"));
	if (!Directory::Exist("C:\\Test"))
		Utils::Log("test doesn't exist !");
	else Utils::Log("test exist !"); 

	if (Directory::Delete("C:\\Test"))
	{
		Utils::Log("test deleted !"); 
	}
	*/
	//Directory d = Directory(Environnement::CurrentDirectory()); 

	
	/*std::vector<std::string> _allLine = file.GetAllLine();
	for (int i = 0; i < _allLine.size(); i++)
		Utils::Log(_allLine[i]); 
	file.Close(); 
	
	FileWriter file = FileWriter("C:\\Users\\GAUT2905\\Documents\\GitHub\\Objectif-3D-p1\\TradClass\\Text.txt");
	file.Write("Gabriel");
	FileReader fileReader = FileReader("C:\\Users\\GAUT2905\\Documents\\GitHub\\Objectif-3D-p1\\TradClass\\Text.txt");

	std::vector<std::string> _allLine = fileReader.GetAllLine();
	for (int i = 0; i < _allLine.size(); i++)
		Utils::Log(_allLine[i]);
	file.Close();

	FileStream* _stream = File::Create("C:\\Users\\GAUT2905\\Documents\\GitHub\\Objectif-3D-p1\\TradClass\\Text.txt");
	_stream->Writer()->Write("Test"); 
	std::vector<std::string> _allLines = _stream->Reader()->GetAllLine();
	for (int i = 0; i < _allLines.size(); i++)
		Utils::Log(_allLines[i]); 
	_stream->Writer()->CLear();
	_allLines = _stream->Reader()->GetAllLine();
	for (int i = 0; i < _allLines.size(); i++)
		Utils::Log(_allLines[i]);
	_stream->Close();*/

	FileStream* _stream = File::Create("C:\\Users\\GAUT2905\\Documents\\GitHub\\Objectif - 3D - p1\\TradClass\\GameSave.exe");
	_stream->Writer()->Write("PlayerName: Toto");

	std::vector<std::string> _allLines = _stream->Reader()->GetAllLine();
	for (int i = 0; i < _allLines.size(); i++)
		Utils::Log(_allLines[i]);
	_stream->Close(); 
}

