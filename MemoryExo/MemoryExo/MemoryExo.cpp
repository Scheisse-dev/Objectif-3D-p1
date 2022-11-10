#include <iostream>


template<typename T>
struct IsPointer { enum { Value = true }; };

template<typename T>
struct IsPointer<T*> { enum { Value = true }; };

template<typename T>
struct IsPointer<const T> { enum { Value = IsPointer<T>::Value }; };

//template<typename T>
//struct RemoveConst {
//    enum { T };
//};

template<typename T>
struct RemoveConst { typedef T Type };
template<typename T>
struct RemoveConst<const T> { typedef T Type };

template<typename T>
struct RemovePointer { typedef T Type };
template<typename T>
struct RemovePointer<T*> { typedef T Type };

template<typename T>
struct RemoveReference { typedef T Type };
template<typename T>
struct RemoveReference<T&> { typedef T Type };
template<typename T>
struct RemoveReference<T&&> { typedef T Type };



template<typename T>
typename RemoveReference<T>::Type&& MoveTemp(T&& obj)
{
    typedef typename RemoveReference<T>::Type CastType;
    return (CastType&&)obj;
}

template<typename T>
void Swap(T& a, T& b)
{
    T _temp = Movetemp(a);
    a = MoveTemp(b);
    b = MoveTemp(_temp) 
}

template<typename T, size_t N> size_t GetCount(T(&container)[N]) { return N; }
template<typename T, size_t N> size_t GetCount(T(&&container)[N]) { return N; }
template<typename T, size_t N> size_t GetCount(const T(&container)[N]) { return N; }
template<typename T, size_t N> size_t GetCount(const T(&&container)[N]) { return N; }
template<typename T> size_t GetCount(std::initializer_list<T> list) {return list.size();}
template<typename T> auto GetCount(T&& container) -> decltype(container.Count())
{
    return container.Count();
}

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef unsigned long long uint64;
typedef signed char int8;
typedef short int16;
typedef int int32;
typedef long long int64;
typedef unsigned char byte;

#define DEPRECATED(Message) [[deprecated(Message " , Please update your code! ") ]]

template<typename T, typename SizeType = int32>
class Array
{
private: 
    T* _tab = new T[0];
    SizeType size = 0;
public:
    DEPRECATED("Test is deprecated use Test1")
    void Test()
    {

    }
    void Test1()
    {

    }

    size_t Count()
    {
        return 20;
    }
};



int main()
{
    //int a[50];
    //size_t _size = GetCount(a);
    //std::cout << _size << std::endl;
    //std::cout << IsPointer<int>::Value << std::endl;
    //std::cout << IsPointer<int*>::Value << std::endl;
    //std::cout << IsPointer<const int*>::Value << std::endl;
    //std::cout << IsPointer<const int>::Value << std::endl;

    //std::cout << RemoveConst<int> = > int << std::endl;
    //RemoveConst<const int = > int;

    //Array<int> arr;
    //GetCount(arr);
    //return 0;

    Array<int> arr;

    return 0;
}

