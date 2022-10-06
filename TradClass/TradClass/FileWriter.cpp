#include "FileWriter.h"

#pragma region constructor
FileWriter::FileWriter(const std::string& _path)
{
	path = _path;
	stream = std::ofstream(_path);
	
}
FileWriter::FileWriter(const FileWriter& _copy)
{
path = _copy.path;
stream = std::ofstream(_copy.path);
}
bool FileWriter::IsOpen() const
{
	return stream.is_open();
}
void FileWriter::Write(const std::string& _value)
{
	if (!IsOpen()) return;
	stream << _value;
	stream << std::endl;
}
void FileWriter::CLear()
{
	Close(); 
	std::ofstream of = std::ofstream(path, std::ofstream::out | std::ofstream::trunc); 
}
void FileWriter::Close()
{
	if (!IsOpen()) return;
	stream.close(); 
}

#pragma endregion constructor
