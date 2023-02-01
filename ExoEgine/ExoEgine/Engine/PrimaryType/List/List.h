#pragma once
#include "IList.h"
#include "../ValueType/ValueType.h"
#include "../../Utils/Template/Pointer.h"
#include "../Integer/Integer.h"
#include "../../Utils/DebugMacro.h"
#include "../../Utils/CoreDefine.h"


namespace Engine::PrimaryType
{
	template<typename InElementType, typename InSizeType = size_t>
	class List : public ValueType, public IList
	{
		DECLARE_CLASS_INFO(List, ValueType); 
#pragma region f/p
		typedef std::vector<InElementType>::iterator Iterator;
		typedef std::vector<InElementType>::const_iterator ConstIterator;
		typedef std::vector<InElementType> ElementType;
		ElementType data = ElementType();
#pragma endregion f/p
#pragma region constructor/destructor
	public:
		List() = default;
		List(List&&) = default;
		List(const List&) = default;
		List(const std::initializer_list<InElementType>& _tab)
		{
			for(const InElementType & _item : _tab)
				Add(_item);
		}
#pragma endregion constructor/destructor 
#pragma region methods
	public:
		void Add(InElementType _item)
		{
			data.push_back(_item);
		}
		void Remove(InElementType _item)
		{
			const size_t _index = Find(_item);
			if (_index == INDEX_NONE) return;
			RemoveAt(_index);
		}
		void RemoveAt(size_t _index)
		{
			data.erase(data.begin() + _index);
		}
		size_t Find(InElementType _item)
		{
			const size_t _size = data.size();
			for(size_t i = 0; i < _size; ++i)
			{
				if (data[i] == _item) return i;
			}
			return INDEX_NONE;
		}
		bool Contains(InElementType _item)
		{
			return Find(_item) != INDEX_NONE;
		}
		Iterator begin() {
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
		size_t Count() const override {
			return data.size();
		}
#pragma endregion methods
#pragma region override
	public:
		void SerializeField(std::ostream& _os, const PrimaryType::String& _fieldName) override
		{

		}
		void DeSerializeField(std::istream& _is, const PrimaryType::String& _fieldName) override
		{

		}
#pragma endregion override
	};

}