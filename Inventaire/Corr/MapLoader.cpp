#include "MapLoader.h"
#include "Map.h"
#include "Path.h"
#include "Environment.h"
#include "Utils.h"
#include <filesystem>

#pragma region constructor/destructor
MapLoader::MapLoader(const MapLoader& _copy)
{
	maps = _copy.maps;
	count = _copy.count; 
}

MapLoader::~MapLoader()
{
	maps.clear();
	count = 0; 
}
void MapLoader::Load()
{
	const std::string& _path = Path::Combine(Environment::CurrentDirectory(), "Maps");
	for (std::filesystem::directory_entry _entry : std::filesystem::directory_iterator(_path))
	{
		if (_entry.is_directory()) continue; 
		const std::string& _mapPath = Path::GetPath(_entry.path().string()); 
		maps.push_back(new Map(_mapPath)); 
	}
	count = maps.size(); 
}
int MapLoader::Count()
{
	return count;
}
bool MapLoader::IsEmpty()
{
	return count == 0; 
}
std::vector<std::string> MapLoader::MapsName() const
{
	std::vector<std::string> _result =  std::vector<std::string>();
	const size_t _size = maps.size(); 
	for (size_t i = 0; i < _size; i++)
		_result.push_back(maps[i]->MapName()); 
	return _result; 
}
Map* MapLoader::GetMap(const int _index) const
{
	const int _currentIndex = _index - 1; 
	if (_currentIndex < 0 || _currentIndex > count)
		throw std::exception("[Map] => index out of rane"); 
	return maps[_currentIndex]; 
}
void MapLoader::DisplayMapName()
{
	for (int i = 0; i < count; i++)
	{
		Utils::Log(std::to_string(i + 1) + ": " + maps[i]->MapName()); 
	}
}
#pragma endregion constructor/destructor