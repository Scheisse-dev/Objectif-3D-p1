#pragma once
#include <string>
class Vector2; 
class Map; 

class Entity
{
#pragma region f/p
private: 
	std::string name = ""; 
	float life = 0.0f;
	float maxLife = 100.0f;
	float mana = 0.0f;
	float maxMana = 100.0f;
	Vector2* position = nullptr; 
	Map* currentMap = nullptr; 
#pragma endregion f/p
#pragma region constructor/destructor
public: 
	Entity() = default; 
	Entity(const std::string& _name,Map* _currentMap, Vector2* _position, const float _maxLife = 100.0f, const float _maxMana = 100.0f) ;
	Entity(const Entity& _copy);
	virtual ~Entity();
#pragma endregion constructor/destructor
#pragma region methods
public: 
	Vector2* Position() const; 
	std::string Name() const; 
	std::string ToString() const; 
	float Life() const;
	float MaxLife() const;
	float Mana() const;
	float MaxMana() const; 
	bool IsDead() const; 
	bool HasMana(const float _cost);
	bool Equals(const Entity* _other);
	void SetLife(const float _life); 
	void SetMaxLife(const float _MaxLife); 
	void AddLife(const float _value);
	void TakeDamage(const float _dmg); 
	void AddMana(const float _value); 
	void SetMana(const float _mana);
	void SetMaxMana(const float _maxMana); 
	void DecreaseMana(const float _value); 
	Map* GetMap() const;
	virtual void Move() = 0; //delaye la déclaration aux classes filles 

	
#pragma endregion methods
};

