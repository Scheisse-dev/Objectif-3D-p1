#pragma once
#include "../Object/Object.h"


namespace Engine
{
    namespace PrimaryType
    {
        class String;
    }


    class File : public Object
    {
        DECLARE_CLASS_INFO(File, Object)
#pragma region f.p
    private:
        std::string path = "";
#pragma endregion
#pragma region const
    public:
        File() = delete; 
        File(const std::string& _path);
#pragma endregion
#pragma region meth
    public:
        std::vector<PrimaryType::String> ReadAllLines() const;
#pragma endregion

    };

}
