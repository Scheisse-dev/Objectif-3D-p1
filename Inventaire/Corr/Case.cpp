#include "Case.h"
#include "Vector2.h"
#pragma region constructor
Case::Case(const char _value, Vector2* _position)
{
	caseValue = _value; 
	position = _position;
}

Case::Case(const Case& _copy)
{
	caseValue = _copy.caseValue; 
	position = _copy.position;
}

Case::~Case()
{
	delete position; 
}
#pragma endregion constructor
#pragma region methods
bool Case::IsWall() const
{
	return caseValue == MapDataBase::WALL; 
}
bool Case::HasMob() const
{
	return caseValue == MapDataBase::Mob;
}
bool Case::IsEnter() const
{
	return caseValue == MapDataBase::Enter;
}
bool Case::IsExit() const
{
	return caseValue == MapDataBase::Exit;
}
char Case::CaseValue() const
{
	return caseValue;
}

Vector2* Case::Position() const
{
	return position; // nullptr...
}



#pragma endregion methods