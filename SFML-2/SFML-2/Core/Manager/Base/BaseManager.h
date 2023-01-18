#pragma once
#include <map>
#include <format>
#include <ranges>

#include "../../Utils/Debug/Debug.h"

#include "../../Utils/Singleton/Singleton.h"
namespace Core
{
	template<typename Class, typename Item>
	class BaseManager : public Utils::Singleton<Class>
	{
		DECLARE_CLASS_INFO(BaseManager, Utils::Singleton<Class>)
#pragma region f/p
	protected:
		std::map<std::string, Item*> items = std::map < std::string, Item*>();
#pragma endregion f/p
#pragma region methods
	public:
		virtual void Init() = 0;
		virtual Item* Load(const char* _name);
#pragma endregion methods
#pragma region override
	protected:
		void OnDestroy() override;
#pragma endregion override
	};

	template <typename Class, typename Item>
	Item* BaseManager<Class, Item>::Load(const char* _name)
	{
		check(items.contains(_name), std::format("[BaseManager] => doesn't found key : {}", _name), nullptr)
		return items[_name];
	}

	template<typename Class, typename Item>
	inline void BaseManager<Class, Item>::OnDestroy()
	{
		for (Item*& _item : items | std::ranges::views::values)
		{
			delete _item;
			_item = nullptr;
		}
		items.clear();
	}

}