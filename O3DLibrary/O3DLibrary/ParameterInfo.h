#pragma once

struct O3DLIBRARY_API ParameterInfo
{
#pragma region f/p
private:
	const char* name = "";
	const char* typeName = "";
	int position = 0;
public:
	ParameterInfo() = default; 
	ParameterInfo(const char* _typeName, const char* _name, int _position)
	{
		name = _name;
		typeName = _typeName;
		position = _position;
	}
#pragma endregion f/p
#pragma region methods
public:

	const char* TypeName() const
	{
		return typeName;
	}
	const char* Name() const
	{
		return name; 
	}
	int Position() const
	{
		return position;

	}

#pragma endregion methods
};