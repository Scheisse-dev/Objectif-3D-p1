#pragma once
class Vector2
{
#pragma region f/p
private:
	int x = 0; 
	int y = 0;

#pragma endregion f/p
#pragma region constructor
public:
	Vector2() = default;
	Vector2(const int _x, const int _y);
	Vector2(const Vector2& _copy); 
#pragma endregion constructor
#pragma region methods 
public:
	int X() const;
	int Y() const;
	void Set(const int _newX, const int _newY); 
	void Set(const Vector2& _other);
	bool Equals(const Vector2* _other) const; 
#pragma endregion methods
#pragma region operator
public: 
	Vector2 operator+=(const Vector2& _other);
	Vector2 operator-=(const Vector2& _other);
#pragma endregion operator
};

