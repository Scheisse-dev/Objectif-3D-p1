#pragma once
#include <vector>
#include <string>

class Case; 
class Player; 
class Vector2;

class Map
{
#pragma region f/p
private:
	std::vector<Case*> cases = std::vector<Case*>();  
	std::string mapName = "default name";  //test 1 
	std::string mapPath =  "";
	Case* enter = nullptr;
	Case* exit = nullptr; 
	Player* player = nullptr; 

#pragma endregion f/p
#pragma region constructor destructor
public: 
	Map() = default; 
	Map(const std::string& _mapPath);
	Map(const Map& _copy);
	~Map(); 

#pragma endregion constructor destructor
#pragma region methods
private: 
	void Init(); 
public: 
	void Display(); 
	bool IsValid() const;
	Case* GetCaseAtPosition(const Vector2& _position);
	void SetPlayer(Player* _player); 
	Player* GetPlayer() const;
	Case* Enter() const;
	Case* Exit() const;
	std::string MapName() const;
#pragma endregion methods

};

