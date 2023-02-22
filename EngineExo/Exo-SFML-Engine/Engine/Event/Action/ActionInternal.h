#pragma once
#include "../../Object/Object.h"
#include "../Delegate/Delegate.h"
#include <vector>
#include <initializer_list>

namespace Engine::Event
{
    template <typename Res, typename... Params>
    class ActionInternal : public Object
    {
        DECLARE_CLASS_INFO(ActionInternal, Object)
#pragma region var
        std::vector<Delegate<Res, Params...>> delegates = std::vector<Delegate<Res, Params...>>();
#pragma endregion
#pragma region const/dest
    public:
        ActionInternal(nullptr_t)
        {
            delegates.clear();
        }

        template <typename Class>
        ActionInternal(Class _instance, Res(Class::*_ptr)(Params...))
        {
            checkBaseOf(Object, Class)
                delegates.push_back(Delegate<Res, Params...>(_instance, _ptr));
        }
#pragma endregion
#pragma region methods
    public:
        template <typename Class>
        void AddDynamic(Class* _instance, Res(Class::* _ptr)(Params...))
        {
            checkBaseOf(Object, Class)
                delegates.push_back(Delegate<Res, Params...>(_instance, _ptr));
        }

        template <typename Class>
        void RemoveDynamic(Class* _instance, Res(Class::* _ptr)(Params...))
        {
            checkBaseOf(Object, Class);
                //    typename std::vector<Delegate<Res, Params...>>::iterator it = delegates.begin();
                //for (; it < delegates.end(); ++it)
                //{
                //    if (*it.GetAddress() == (void*&)_ptr && *it.Intance() == _instance)
                //    {
                //        delegates.erase(it);
                //        break;
                //    }
                //}
            const size_t _size = delegates.size();
            for (int i = 0; i < _size; i++)
            {
                if(delegates[i].GetAddress() == (void*&)_ptr && delegates[i].Instance() == _instance)
                {
                    delegates.erase(delegates.begin() + i);
                    break;
                }
            }
        }

        Res Invoke(Params... _params)
        {
            if constexpr (std::is_same_v<Res, void>)
            {
                for (Delegate<Res, Params...> _item : delegates)
                    _item.Invoke(_params...);
                return;
            }
            else
            {
                Res _res = Res();
                for (Delegate<Res, Params...> _item : delegates)
                    _res = _item.Invoke(_params...);
                return _res;
            }
        }
#pragma endregion
#pragma region operator
    public:
        ActionInternal& operator=(nullptr_t)
        {
            delegates.clear();
            return *this;
        }
        ActionInternal& operator=(const ActionInternal& _other)
        {
            delegates = _other.delegates;
            return *this;
        }

        Res operator()(Params... _params)
        {
            return Invoke(_params);
        }
#pragma endregion
    };

}

template<typename T, typename... Params>
Engine::Event::ActionInternal<T, Params...>::ActionInternal(const ActionInternal& _copy)
{
    delegates = _copy.delegates;
}

template<typename... Params>
using Action = Engine::Event::ActionInternal<void, Params...>;
template<typename T, typename... Params>
using Func = Engine::Event::ActionInternal<T, Params...>;
template<typename... Params>
using Predicate = Engine::Event::ActionInternal<bool, Params...>;
