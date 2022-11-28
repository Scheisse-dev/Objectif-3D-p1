#pragma once
#include "Object.h"
#include <limits>

namespace Core
{
	namespace PrimitiveType
	{
		class O3DLIBRARY_API Integer : public Object
		{
#pragma region f/p
		private:
			int value = 0;
		public: 
			 static Integer MinValue();
			 static Integer MiaxValue();
#pragma endregion f/p
#pragma region constructor
		public: 
			 Integer() = default;
			 Integer(const int _value);
			 Integer(const Integer& _copy);
#pragma endregion constructor
#pragma region methods
			 Boolean Equals(const Integer& _other) const; 
			 static Integer Parse(const FString& _str);
			 static Boolean TryParse(const FString& _str, Integer& _out);
#pragma endregion methods
#pragma region override
		public:
			 FString ToString() const override;
			 Boolean Equals(const Object* _obj) const override;
#pragma endregion override
#pragma region operator 
		public: 
			 operator int() const;
			 Object& operator=(const Object* _obj);
			 Integer operator+(const Integer& _other) const; 
			 Integer& operator += (const Integer& _other);
			 Integer operator-(const Integer& _other) const;
			 Integer& operator -= (const Integer& _other);
			 Integer operator*(const Integer& _other) const;
			 Integer& operator *= (const Integer& _other);
			 Integer operator/(const Integer& _other) const;
			 Integer& operator /= (const Integer& _other);
			 Integer operator% (const Integer& _other) const;
			 Integer& operator %= (const Integer& _other);
			 Integer& operator++(int);
			 Integer& operator--(int);
			 Integer& operator++();
			 Integer& operator--();
			 Integer operator-(int);



			 Boolean operator < (const Integer& _other) const;
			 Boolean operator <= (const Integer& _other) const;
			 Boolean operator > (const Integer& _other) const;
			 Boolean operator >= (const Integer& _other) const;
			 Boolean operator == (const Integer& _other) const;
			 Boolean operator != (const Integer& _other) const;

#pragma endregion operator
		};
	}
}