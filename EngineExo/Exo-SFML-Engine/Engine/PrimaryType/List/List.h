#pragma once
#include "IList.h"
#include "../Integer/Integer.h"
#include "../ValueType/ValueType.h"
#include "../../Utils/DebugMacro.h"
#include "../../Utils/Template/Template.h"
#include "../../Utils/Template/Pointer.h"
#include "../../Utils/CoreDefine.h"
#include "../../Utils/DebugMacro.h"
#include "../../Utils/ObjectMacro.h"
#include <vector>
#include <iostream>

namespace Engine::PrimaryType
{
    template<typename InElementType>
    class List : public ValueType, public IList
    {
        DECLARE_CLASS_INFO(List, ValueType)
#pragma region var
    public:
        typedef typename std::vector<InElementType>::iterator Iterator;
        typedef typename std::vector<InElementType>::const_iterator ConstIterator;
        typedef std::vector<InElementType> ElementType;
        ElementType data = ElementType();
#pragma endregion
#pragma region const
    public:
        List() = default;
        List(List&&) = default;
        List(const std::initializer_list<InElementType>& _tab)
        {
            for (const InElementType& _item : _tab)
                Add(_item);
        }
#pragma endregion
#pragma region methods
    public:
        Iterator begin()
        {
            return data.begin();
        }
        ConstIterator begin() const
        {
            return data.begin();
        }
        Iterator end()
        {
            return data.end();
        }
        ConstIterator end() const
        {
            return data.end();
        }

        void Add(InElementType _item)
        {
            data.push_back(_item);
        }

        void Remove(InElementType _item)
        {
            const size_t _index = Find(_item);
            if (_index == INDEX_NONE)
                return;
            RemoveAt(_index);
        }

        void RemoveAt(size_t _index)
        {
            data.erase(data.begin() + _index);
        }

        size_t Find(const InElementType& _item)
        {
            const size_t _size = data.size();
            for (size_t i = 0; i < _size; i++)
            {
                if (data[i] == _item)
                    return i;
            }
            return INDEX_NONE;
        }

        bool Contains(InElementType _item)
        {
            return Find(_item) != INDEX_NONE;
        }
#pragma endregion
#pragma region override
    public:
        size_t Count() const override
        {
            return data.size();
        }

        PrimaryType::String ToString() const override
        {
            String _res = "";
            const size_t _size = data.size();
            for (size_t i = 0; i < _size; i++)
            {
                _res += ::ToString(data[i]);
                if (i < _size - 1)
                    _res += ", ";
            }
            return _res;
        }

        void SerializeField(std::ostream& _os, const PrimaryType::String& _fieldName, int _index) override
        {
            if (String::IsNullOrEmpty(_fieldName))
                _os << "[\n";
            else
                _os << "\"" + std::string(_fieldName.ToCstr()) + "\" : ";

            /*if constexpr (IsPointer<InElementType>::Value)
                _os << "\"" << data[0]->ClassName().ToCstr() << "\"";
            else
                _os << "\"" << data[0].ClassName().ToCstr() << "\"";*/

            _os << "[\n";

            const size_t _size = data.size();
            for (size_t i = 0; i < _size; i++)
            {
                _os << std::string(_index, '\t') + "\t\t";
                if constexpr (IsPointer<InElementType>::Value)
                {
                    if (data[i]->IsClass())
                        data[i]->Serialize(_os, 2);
                    else
                        data[i]->SerializeField(_os, "", _index);
                }
                else
                {
                    if (data[i].IsClass())
                        data[i].Serialize(_os, 2);
                    else
                        data[i].SerializeField(_os, "", _index);
                }
                if (i < _size - 1)
                    _os << ",";
                _os << "\n";
            }
            _os << std::string(_index, '\t') + "]";
        }

        void DeSerializeField(std::istream& _is, const PrimaryType::String& _fieldName) override
        {
            if constexpr (!std::is_base_of_v<Object, typename RemovePointer<InElementType>::Type>)
                throw std::exception(std::format("[List] => {} must inherited of Object", typeid(InElementType).name()).c_str());

            std::string _line = "";
            bool _isList = false;
            size_t _index = -1;
            std::vector<InElementType> _res = std::vector<InElementType>();

            typedef typename RemovePointer<InElementType>::Type TypeNoPointer;
            TypeNoPointer _el = TypeNoPointer();

            while (std::getline(_is, _line))
            {
                if (_line.find(std::string("\"") + _fieldName.ToCstr() + "\"") != std::string::npos)
                {
                    _isList = true;
                }
                else if (_line.find("],") != std::string::npos)
                    break;

                else if (_isList && _line.find("}") == std::string::npos)
                {
                    if (_index != -1)
                        _is.seekg(_index);
                    String _className = _line.c_str();
                    _className = _className.SubString(_className.FindFirstOf('\"'), _className.FindFirstOf(':'));
                    _className = _className.Replace("\"", "").Trim();
                    Object* _classType = TypeOfData::Types[_className.ToCstr()];
                    Object* _data = _classType ? _classType->Clone() : new TypeNoPointer();

                    if (_data->IsClass())
                        _data->DeSerialize(_is);
                    else
                        _data->DeSerializeField(_is, "");

                    if constexpr (IsPointer<InElementType>::Value)
                        _res.push_back(dynamic_cast<InElementType>(_data));
                    else
                        _res.push_back(*dynamic_cast<InElementType*>(_data));
                    _index = _is.tellg();
                }
            }
            /*std::vector<InElementType> _res = std::vector<InElementType>();
            if constexpr (IsPointer<InElementType>::Value)
            {
                for (TypeNoPointer* _el : _vector)
                    _res.push_back(_el);
            }
            else
            {
                for (TypeNoPointer* _el : _vector)
                    _res.push_back(*_el);
            }*/
            * this = _res;
        }
#pragma endregion
#pragma region operator
    public:
        List& operator=(const std::vector<InElementType>& _other)
        {
            data = _other;
            return *this;
        }

        InElementType& operator[](size_t _index)
        {
            return data[_index];
        }
        InElementType& operator[](size_t _index) const
        {
            return data[_index];
        }

        Object& operator=(const Object* _obj) override
        {
            const List* _other = dynamic_cast<const List*>(_obj);
            check((_other != nullptr), "[List] => operator= obj is not List", *this)
                data = _other->data;
            return *this;
        }

        List& operator=(const List&) = default;
        List& operator=(List&&) = default;
#pragma endregion

    };
}

template <typename InElementType>
Engine::PrimaryType::List< InElementType>::List(const List& _copy)
{
    data = _copy.data;
}
