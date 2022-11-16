#pragma once
#include "Object.h"
#include <limits>

namespace Core
{
	namespace PrimitiveType
	{
		class Integer : public Object
		{
#pragma region f/p
		private:
			int value = 0;
		public: 
			O3DLIBRARY_API static Integer MinValue();
			O3DLIBRARY_API static Integer MiaxValue();
#pragma endregion f/p
#pragma region constructor
		public: 
			O3DLIBRARY_API Integer() = default;
			O3DLIBRARY_API Integer(const int _value);
			O3DLIBRARY_API Integer(const Integer& _copy);
#pragma endregion constructor
#pragma region methods
			O3DLIBRARY_API Boolean Equals(const Integer& _other) const; 
			O3DLIBRARY_API static Integer Parse(const FString& _str);
			O3DLIBRARY_API static Boolean TryParse(const FString& _str, Integer& _out);
#pragma endregion methods
#pragma region override
		public:
			O3DLIBRARY_API FString ToString() const override;
			O3DLIBRARY_API Boolean Equals(const Object* _obj) const override;
#pragma endregion override
#pragma region operator 
		public: 
			O3DLIBRARY_API operator int() const;
			O3DLIBRARY_API Integer operator+(const Integer& _other) const; 
			O3DLIBRARY_API Integer& operator += (const Integer& _other);
			O3DLIBRARY_API Integer operator-(const Integer& _other) const;
			O3DLIBRARY_API Integer& operator -= (const Integer& _other);
			O3DLIBRARY_API Integer operator*(const Integer& _other) const;
			O3DLIBRARY_API Integer& operator *= (const Integer& _other);
			O3DLIBRARY_API Integer operator/(const Integer& _other) const;
			O3DLIBRARY_API Integer& operator /= (const Integer& _other);
			O3DLIBRARY_API Integer operator% (const Integer& _other) const;
			O3DLIBRARY_API Integer& operator %= (const Integer& _other);
			O3DLIBRARY_API Integer& operator++(int);
			O3DLIBRARY_API Integer& operator--(int);
			O3DLIBRARY_API Integer& operator++();
			O3DLIBRARY_API Integer& operator--();
			O3DLIBRARY_API Integer operator-(int);



			O3DLIBRARY_API Boolean operator < (const Integer& _other) const;
			O3DLIBRARY_API Boolean operator <= (const Integer& _other) const;
			O3DLIBRARY_API Boolean operator > (const Integer& _other) const;
			O3DLIBRARY_API Boolean operator >= (const Integer& _other) const;
			O3DLIBRARY_API Boolean operator == (const Integer& _other) const;
			O3DLIBRARY_API Boolean operator != (const Integer& _other) const;

#pragma endregion operator
		};
	}
}