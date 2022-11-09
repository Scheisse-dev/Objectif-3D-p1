#include <iostream>


template<typename T>
struct IsPointer { enum { Value = true }; };

template<typename T>
struct IsPointer<T*> { enum { Value = true }; };

template<typename T>
struct IsPointer<const T> { enum { Value = IsPointer<T>::Value }; };

template<typename T>
struct RemoveConst {
    enum { T };
};
template<typename T>
struct RemoveConst<const T> { enum {T = RemoveConst::T}; };

template<typename T>


int main()
{
    std::cout << IsPointer<int>::Value << std::endl;
    std::cout << IsPointer<int*>::Value << std::endl;
    std::cout << IsPointer<const int*>::Value << std::endl;
    std::cout << IsPointer<const int>::Value << std::endl;

    std::cout << RemoveConst<int> = > int << std::endl;
    RemoveConst<const int = > int;
}

