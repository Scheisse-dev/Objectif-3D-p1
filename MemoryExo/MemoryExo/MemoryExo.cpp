#include <iostream>


template<typename T>
struct IsPointer { enum { Value = true }; };

template<typename T>
struct IsPointer<T*> { enum { Value = true }; };

template<typename T>
struct IsPointer<const T> { enum { Value = IsPointer<T>::Value }; };


int main()
{
    std::cout << IsPointer<int>::Value << std::endl;
    std::cout << IsPointer<int*>::Value << std::endl;
    std::cout << IsPointer<const int*>::Value << std::endl;
    std::cout << IsPointer<const int>::Value << std::endl;

    RemoveConst<int> = > int;
    RemoveConst<const int = > int;
}

