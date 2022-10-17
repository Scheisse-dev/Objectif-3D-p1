#include "Map.h"
#include "Path.h"
#include "Environment.h"
#include "File.h"
#include "Vector2.h"
#include "Case.h"
#include "Utils.h"
#include"Player.h"
#include <iostream>

#pragma region constructor/destructor 
Map::Map(const std::string& _mapPath)
{
	mapPath = _mapPath; 
	mapName = Path::GetFileNameWithoutExtension(mapPath); 
	Init();
}

Map::Map(const Map& _copy)
{
	mapName = _copy.mapName;
	cases = _copy.cases;
}

Map::~Map()
{
	cases.clear(); 
}

#pragma endregion constructor/destructor 
#pragma region methods
void Map::Init()
{
	std::vector<std::string> _lines = File::GetAllLines(mapPath); 
	const size_t _size = _lines.size(); 
	for (size_t y = 0; y < _size; y++)
	{
		const std::string _line = _lines[y];
		const size_t _length = _line.length(); 
		for (size_t x = 0; x < _length; x++)
		{
			Vector2* _position = new Vector2(x, y); 
			Case* _case = new Case(_line[x], _position); 
			if (_case->IsEnter()) enter = _case;
			else if (_case->IsExit()) exit = _case; 
			cases.push_back(_case); 
		}
		cases.push_back(new Case('\n', new Vector2(-1, -1))); //TODO to change ! 
	}
}

void Map::Display()
{
	const size_t _size = cases.size(); 
	for (size_t i = 0; i < _size; i++)
	{
		if (player->Position()->Equals(cases[i]->Position()))
			std::cout << MapDataBase::Player; 
		else
			std::cout << cases[i]->CaseValue(); 
	}
}

bool Map::IsValid() const
{
	return enter != nullptr && exit != nullptr; 
}

Case* Map::GetCaseAtPosition(const Vector2& _position)
{
	const size_t _size = cases.size(); 
	for (size_t i = 0; i < _size; i++)
	{
		if (cases[i]->Position()->Equals(&_position))
			return cases[i];
	}
	return nullptr;
}

void Map::SetPlayer(Player* _player)
{
	player = _player; 
	player->Position()->Set(*enter->Position()); 
	player->SetMap(this); 
}

void Map::SetSkeleton(Mob* _mob)
{
//	skeleton = _mob;
//	skeleton->Position()->Set(*mob->Position()); AHAHAHAHAHAHAHAHAHHAHAHAHAHAHAHAHHA PKAOEMµGHJPEIZGF j'en peux plus 
//	skeleton->SetMap(this); 
}

Mob* Map::GetMob() const
{
	return skeleton;
}

Player* Map::GetPlayer() const
{
	return player;
}

Case* Map::Enter() const
{
	return enter;
}

Case* Map::Exit() const
{
	return exit;
}
std::string Map::MapName() const
{
	return mapName;
}


#pragma endregion methods