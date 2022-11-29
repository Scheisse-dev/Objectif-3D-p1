#pragma once
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "O3DLibrary.h"

#pragma warning(disable : 4251) 


#define REGISTER_FIELD(X,Y,Z) RegisterField(X,Y,Z)


namespace Core
{

    namespace PrimitiveType
    {
        class FString;
        class Boolean;

    }
    enum class BindingFlags; 
    class MethodsInfo;
    class FieldInfo;
    class O3DLIBRARY_API Object
    {
#pragma region f/p
    private: 
        std::map<const char*, FieldInfo*> fields = std::map<const char*, FieldInfo*>(); 
        std::map<const char*, MethodsInfo*> methods = std::map<const char*, MethodsInfo*>();
#pragma endregion f/p 
#pragma region constructor/destructor
    public:
        Object() = default;
        virtual ~Object() = default;
#pragma endregion constructor/destructor
#pragma region methods
    protected: 
        int RegisterFunction(const char* name, Object* _obj, int _mask);
        int RegisterField(const char* _name, Object* _obj, int _mask);
    public:
        virtual Core::PrimitiveType::Boolean Equals(const Object* _obj) const;
        virtual Core::PrimitiveType::FString ToString() const;
        std::vector<FieldInfo*> GetFields() const;
        std::vector<FieldInfo*> GetFields(BindingFlags _flags) const;
        FieldInfo* GetField(const char* _name) ; 
        template<typename T>
        void SetValue(Object* obj);
        template<typename T>
        void SetFieldValue(const char* _name, T* _value);
#pragma endregion methods 
#pragma region operator
    public: 
        virtual Object& operator=(const Object* obj);
        virtual Object& operator[](const Object* obj); 
#pragma endregion operator
    };
    typedef Object* object;


    template<typename T>
    void Object::SetValue(Object* obj)
    {
        *((T)this) = obj;
    }

    template<typename T>
    inline void Object::SetFieldValue(const char* _name, T* _value)
    {
        if (!fields.contains(_name)) return;
        *fields[_name]= _value; 
    }

}