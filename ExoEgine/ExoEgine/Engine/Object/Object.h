#pragma once
#include "../PrimaryType/Enum/Enum.h"
#include "../Reflection/Function/Function.h"
#include "../Reflection/Flags/BindingFlag.h"
#include "../Reflection/Function/MethodInfo/MethodInfo.h"

#include <map>
#include <format>

#pragma warning(disable:4996)


#pragma region define

	

#define UFUNCTION(...)
#define UPROPERTY(...)
#define UCLASS(...)


#define REGISTER_FIELD(name, field, flags) const int field##name = InsertField(#name,(Object*)field, flags);
#define REGISTER_METHOD(name, method, params, flags) const int Method##name = InsertMethod(#name, method, params, flags);

#define DECLARE_CLASS_INFO_FLAGS(current, parent, flags) \
	public:\
		typedef current self;\
		typedef parent super;\
		const int flagsInfo = RegisterClassInfo((int)flags);

#define DECLARE_CLASS_INFO(current, parent) \
	public:\
		typedef current self;\
		typedef parent super;

#pragma endregion define

ENUM(ClassFlags, Class, Type)

namespace Engine
{
	namespace Reflection
	{
		class FieldInfo;
	}
	namespace PrimaryType
	{
		class Boolean;
		class String;
	}
	class Object
	{
#pragma region f/p
	private:
		int flags = 0;
		std::map<std::string, Object*> fields = std::map<std::string, Object*>();
		std::map<std::string, Object*> methods = std::map<std::string, Object*>();
		std::map<std::string, Reflection::Function*> functions = std::map<std::string, Reflection::Function*>();
#pragma endregion f/p
#pragma region constructor/destructor
	public:
		Object() = default; 
		Object(const Object& _copy);
		virtual ~Object() = default; 
#pragma endregion constructor/destructor
#pragma region methods
	public:
		virtual PrimaryType::String ToString() const;
		PrimaryType::Boolean IsClass() const;
		Reflection::FieldInfo* GetField(const PrimaryType::String& _name);
		std::vector<Reflection::FieldInfo*> Fields() const ;
		std::vector<Reflection::FieldInfo*> Fields(const BindingFlags& _flags) const;
		template<typename T>
		void SetValue(const Object* _obj);
		template <typename T>
		void SetFieldValue(const std::string& _name, T* _value);

		template<typename Res, typename... Params>
		Reflection::MethodsInfo<Res, Params...>* GetFunction(const std::string& _name);

		template<typename Res, typename... Params>
		Res Invoke(const std::string& _name, Object* _instance,  Params... _params);

		template<typename Res, typename... Params>
		Res Invoke(const std::string& _name, Params... _params);

	protected:
		int RegisterClassInfo(int _flags);

		template<typename Res, typename Class, typename... Params>
		size_t InsertMethod(const std::string& _name, Res(Class::* ptr)(Params...), const std::vector<Reflection::ParameterInfo*>& _params, const BindingFlags& _flags);


		size_t InsertField(const std::string& _name, Object* _var, const BindingFlags& _flags);
#pragma endregion methods
#pragma region operator
	public:
		virtual Object& operator=(const Object* _obj);
#pragma endregion operator
	};
	template<typename T>
	void Object::SetValue(const Object* _obj)
	{
		*((T*)this) = _obj;
	}
	template <typename T>
	void Object::SetFieldValue(const std::string& _name, T* _value)
	{
		if (!fields.contains(_name)) return;
		fields[_name]->SetValue<T>(_value);
	}

	template<typename Res, typename... Params>
	Reflection::MethodsInfo<Res, Params...>* Engine::Object::GetFunction(const std::string& _name)
	{
		if (!functions.contains(_name)) return nullptr;
		return reinterpret_cast<Reflection::MethodsInfo<Res, Params...>*>(functions[_name]);
	}

	template<typename Res, typename... Params>
	Res Engine::Object::Invoke(const std::string& _name, Object* _instance, Params... _params)
	{
		Reflection::MethodsInfo<Res, Params...>* _method = GetFunction<Res, Params...>(_name);
		if (_method == nullptr)
			throw std::exception(std::format("[Object][Reflection] => function{} doesn't exist", _name).c_str());
		return _method->Invoke(_instance, _params...);
	}

	template<typename Res, typename... Params>
	Res Engine::Object::Invoke(const std::string& _name, Params... _params)
	{
		return Invoke<Res, Params...>(_name, this, _params...);
	}

	template<typename Res, typename Class, typename ...Params>
	inline size_t Engine::Object::InsertMethod(const std::string& _name, Res(Class::* ptr)(Params...), const std::vector<Reflection::ParameterInfo*>& _params, const BindingFlags& _flags)
	{
		if (functions.contains(_name)) return functions.size();
		Reflection::MethodsInfo<Res, Params...>* _function = new Reflection::MethodsInfo<Res, Params...>(_name, ptr, _params, _flags);
		functions.insert(std::pair(_name, _function));
		return functions.size();
	}


}

