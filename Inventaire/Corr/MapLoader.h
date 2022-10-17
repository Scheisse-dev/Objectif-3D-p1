#pragma once
#include <vector>
#include <string>

class Map; 

class MapLoader
{
#pragma region f/p
private : 
	std::vector<Map*> maps = std::vector<Map*>();
	int count = 0; 
#pragma endregion f/p
#pragma region constructor/destructor
public: 
	MapLoader() = default; 
	MapLoader(const MapLoader& _copy);
	~MapLoader();
#pragma endregion constructor/destructor

#pragma region methods 
public: 
	void Load(); 
	int Count(); 
	bool IsEmpty(); 
	std::vector<std::string> MapsName() const; 
	Map* GetMap(const int _index) const; 
	void DisplayMapName(); 
#pragma endregion methods 
};

