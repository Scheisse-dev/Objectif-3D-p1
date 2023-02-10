#include "ReflexionTest.h"
#include "../../Engine/Utils/DebugMacro.h"
#include "../../Engine/Reflection/Fields/FieldsInfo.h"
#include <format>

void Test::ReflexionTest::Update()
{
    LOG("Update call")
}

void Test::ReflexionTest::Display(const std::string& _msg)
{
    LOG(_msg)
}

void Test::ReflexionTest::Test()
{
    ReflexionTest test = ReflexionTest();
    test.Invoke<void>("Update");

    Engine::Reflection::MethodsInfo<void, std::string>* _method = test.GetFunction<void, std::string>("Display");
    for (Engine::Reflection::ParameterInfo* _param : _method->Parameters())
    {
        
    }
    _method->Invoke(&test, "Salut");

    /*ReflexionTest test = ReflexionTest();
    Engine::Reflection::FieldsInfo* _field = test.GetField("name");
    LOG("[Reflection][test] => GetField(name)")
    checkLow((_field != nullptr), "[Reflection][test] => field is nullptr")
        LOG(std::format("{}: {}", _field->Name(), _field->ToString().ToCstr()))

    std::vector<Engine::Reflection::FieldsInfo*> _fields = test.Fields(BindingFlags::Public);
    LOG("[Reflection][Test] => fields with Public flags")
    for (const Engine::Reflection::FieldsInfo* _fieldInfo : _fields)
        LOG(std::format("{}: {}", _fieldInfo->Name(), _fieldInfo->ToString().ToCstr()))

    _fields = test.Fields(BindingFlags::Static);
    LOG("[Reflection][Test] => fields with Static flags")
    for (const Engine::Reflection::FieldsInfo* _fieldInfo : _fields)
        LOG(std::format("{}: {}", _fieldInfo->Name(), _fieldInfo->ToString().ToCstr()))

    _field->SetValue<Engine::PrimaryType::String>(new Engine::PrimaryType::String("Thomas"));

    LOG(std::format("{}: {}", _field->Name(), _field->ToString().ToCstr()))
    LOG(test.name)*/
}
