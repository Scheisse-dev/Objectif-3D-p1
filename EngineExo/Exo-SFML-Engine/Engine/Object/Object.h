#pragma once
#include "../PrimaryType/Enum/Enum.h"
#include "../Utils/Interface/Log/ILogger.h"
#include "../Reflection/Flags/BindingFlags.h"
#include "../Reflection/Function/Methods/MethodsInfo.h"
#include "../Reflection/Function/ParameterInfo/ParameterInfo.h"
#include <map>
#include <format>

#pragma warning(disable: 4996)

#pragma region define

#define UFUNCTION(...)

#define UPROPERTY(...)

#define UCLASS(...)

#define REGISTER_FIELD(name, field, flags) const size_t field##name = InsertField(#name, (Object*)field, flags);

#define REGISTER_METHOD(name, method, params, flags) const size_t Method##name = InsertMethod(#name, method, params, flags);

#define DECLARE_COPY(Class) \
    public:\
        Class(const Class& _copy);\
        Object* Clone() override \
        {\
            return new Class(*this);\
        }

#define DECLARE_CLASS_INFO_FLAGS(current, parent, flags) \
    public:\
        typedef current self;\
        typedef parent super;\
        const int flagsInfo = RegisterClassInfo((int)flags);\
        DECLARE_COPY(current)

#define REGISTER_CLASS(type) const size_t Class##type = Engine::Object::InsertClass(#type, new type());

#define DECLARE_CLASS_INFO(current, parent) \
    public:\
        typedef current self;\
        typedef parent super;\
        DECLARE_COPY(current)

#pragma endregion define

ENUM(ClassFlags, Class, Type)

namespace Engine
{
    namespace PrimaryType
    {
        class String;
        class Boolean;
    }

    namespace Reflection
    {
        class FieldsInfo;
    }

    class Object : public Interface::ILogger
    {
#pragma region f/p
    private:
        int flags = 0;
        std::map <std::string, Object*> fields = std::map <std::string, Object*>();
        std::map <std::string, Reflection::Function*> functions = std::map <std::string, Reflection::Function*>();
    public:
        static inline std::map <std::string, Object*> types = std::map <std::string, Object*>();
#pragma endregion f/p
#pragma region constructor/destructor
    public:
        Object() = default;
        Object(const Object& _copy);
        virtual ~Object() = default;
#pragma endregion constructor/destructor
#pragma region methods
    public:
        virtual PrimaryType::String ToString() const override;
        PrimaryType::String ClassName() const;
        PrimaryType::Boolean IsClass() const;
        Reflection::FieldsInfo* GetField(const PrimaryType::String& _str);
        std::vector<Reflection::FieldsInfo*> Fields() const;
        std::vector<Reflection::FieldsInfo*> Fields(const BindingFlags& _flags);

        template <typename T>
        void SetValue(Object* _obj);

        template <typename T>
        void SetFieldValue(const std::string& _name, T* _value);

        virtual void Serialize(std::ostream& _os, int _index = 1);
        virtual void DeSerialize(std::istream& _is);
        virtual void SerializeField(std::ostream& _os, const PrimaryType::String& _fieldname, int _index);
        virtual void DeSerializeField(std::istream& _is, const PrimaryType::String& _fieldname);
        virtual void OnDeSerialiseFinish() {}

        template <typename Res, typename... Params>
        Reflection::MethodsInfo<Res, Params...>* GetFunction(const std::string& _name)
        {
            if (!functions.contains(_name))
                return nullptr;
            return reinterpret_cast<Reflection::MethodsInfo<Res, Params...>*>(functions[_name]);
        }

        template <typename Res, typename... Params>
        Res Invoke(const std::string& _name, Object* _instance, Params... _params)
        {
            Reflection::MethodsInfo<Res, Params...>* _method = GetFunction<Res, Params...>(_name);
            if (_method == nullptr)
                throw std::exception(std::format("[Object][Reflection] => function {} doesn't exist", _name).c_str());
            return _method->Invoke(_instance, _params...);
        }

        template <typename Res, typename... Params>
        Res Invoke(const std::string& _name, Params... _params)
        {
            return Invoke<Res, Params...>(_name, this, _params...);
        }
    protected:
        int RegisterClassInfo(int _flags);
        size_t InsertField(const std::string& _name, Object* _var, const BindingFlags& _flags);

        template <typename Res, typename Class, typename... Params>
        size_t InsertMethod(const std::string& _name, Res(Class::*_ptr)(Params...), const std::vector<Reflection::ParameterInfo*>& _params, const BindingFlags& _flags)
        {
            if (functions.contains(_name))
                return functions.size();
            Reflection::MethodsInfo<Res, Params...>* _function = new Reflection::MethodsInfo<Res, Params...>(_name, _ptr, _params, _flags);
            functions.insert(std::pair(_name, _function));
            return functions.size();
        }

        template <typename Res, typename... Params>
        size_t InsertMethod(const std::string& _name, Res(*_ptr)(Params...), const std::vector<Reflection::ParameterInfo*>& _params, const BindingFlags& _flags)
        {
            if (functions.contains(_name))
                return functions.size();
            Reflection::MethodsInfo<Res, Params...>* _function = new Reflection::MethodsInfo<Res, Params...>(_name, _ptr, _params, _flags);
            functions.insert(std::pair(_name, _function));
            return functions.size();
        }
    public:
        static size_t InsertClass(const std::string& _name, Object* _obj)
        {
            if (types.contains(_name))
                return types.size();
            types.insert(std::pair(_name, _obj));
            return types.size();
        }

        virtual Object* Clone()
        {
            return new Object(*this);
        }
#pragma endregion methods
#pragma region operator
    public:
        virtual Object& operator=(const Object* _obj);
#pragma endregion
    };

    template<typename T>
    void Engine::Object::SetValue(Object* _obj)
    {
        *((T*)this) = _obj;
    }

    template<typename T>
    void Object::SetFieldValue(const std::string& _name, T* _value)
    {
        if (!fields.contains(_name))
            return;
        fields[_name]->SetValue<T>(_value);
    }
}
