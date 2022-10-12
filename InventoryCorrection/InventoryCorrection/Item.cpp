#include "Item.h"
#include "Utils.h"

#pragma region constructor
Item::Item(const std::string& _name)
{
	name = _name;
}

Item::Item(const Item& _copy)
{
	name = _copy.name;
	isStackable = _copy.isStackable;
	stack = _copy.stack;
	maxStack = _copy.maxStack;
}
#pragma endregion constructor

#pragma region methods
bool Item::IsStackable() const
{
	return isStackable;
}

int Item::Stack() const
{
	return stack;
}

int Item::MaxStack() const
{
	return maxStack;
}

void Item::SetIsStackable(const bool _status)
{
	isStackable = _status;
}

void Item::AddStack(const int _value)
{
	if (!isStackable) return;
	stack = Utils::Clamp(stack + _value, 0, maxStack);
}

void Item::SetStack(const int _stack)
{
	if (!isStackable) return;
	stack = Utils::Clamp(_stack, 0, maxStack);
}

void Item::SetMaxStack(const int _maxStack)
{
	maxStack = _maxStack;
}

void Item::OnUse(Entity* _entity)
{
	stack = Utils::Clamp(stack - 1, 0, maxStack);
}

std::string Item::ToString() const
{
	return name + " x" + std::to_string(stack);
}
bool Item::Equals(const Item* _other) const
{
	return name == _other->name && isStackable == _other->isStackable;
}
#pragma endregion methods