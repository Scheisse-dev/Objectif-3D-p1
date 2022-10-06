#include "FileWriter.h"

#pragma region constructor
FileWriter::FileWriter(const std::string& _path)
{
	path = _path;
	stream = std::ofstream(_path, std::ofstream::out | std::ofstream::app);
}

FileWriter::FileWriter(const FileWriter& _copy)
{
	path = _copy.path;
	stream = std::ofstream(_copy.path, std::ofstream::out | std::ofstream::app);
}
#pragma endregion constructor

#pragma region methods
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
void FileWriter::Clear()
{
	Close();
	stream = std::ofstream(path, std::ofstream::out | std::ofstream::trunc);
}
void FileWriter::Close()
{
	if (!IsOpen()) return;
	stream.close();
}
#pragma endregion methods