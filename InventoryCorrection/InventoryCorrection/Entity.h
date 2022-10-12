#pragma once
#include <string>

class Entity
{
#pragma region f/p
private:
	std::string name = "";
	float life = 0.0f;
	float maxLife = 100.0f;
	float mana = 0.0f;
	float maxMana = 100.0f;
#pragma endregion f/p
#pragma region constructor/destructor
public:
	Entity() = default;
	Entity(const std::string& _name, const float _maxLife = 100.0f, const float _maxMana = 100.0f);
	Entity(const Entity& _copy);
	virtual ~Entity() = default;
#pragma endregion constructor/destructor
#pragma region methods
public:
	std::string Name() const;
	std::string ToString() const;
	float Life() const;
	float MaxLife() const;
	float Mana() const;
	float MaxMana() const;
	bool IsDead() const;
	bool HasMana(const float _cost) const;
	bool Equals(const Entity* _other) const;
	void SetLife(const float _life);
	void SetMaxLife(const float _maxLife);
	void AddLife(const float _value);
	void TakeDamage(const float _dmg);
	void AddMana(const float _value);
	void SetMana(const float _mana);
	void SetMaxMana(const float _maxMana);
	void DecreaseMana(const float _value);
#pragma endregion methods
};

