#pragma once
#include <string>

class Entity;

class Item
{
#pragma region f/p
private:
	std::string name = "";
	bool isStackable = true;
	int stack = 1;
	int maxStack = 64;
#pragma endregion f/p
#pragma region constructor/destructor
public:
	Item() = default;
	Item(const std::string& _name);
	Item(const Item& _copy);
	virtual ~Item() = default;
#pragma endregion constructor/destructor
#pragma region methods
public:
	bool IsStackable() const;
	int Stack() const;
	int MaxStack() const;
	void SetIsStackable(const bool _status);
	void AddStack(const int _value);
	void SetStack(const int _stack);
	void SetMaxStack(const int _maxStack);
	virtual void OnUse(Entity* _entity);
	virtual std::string ToString() const;
	virtual bool Equals(const Item* _other) const;
#pragma endregion methods
};

