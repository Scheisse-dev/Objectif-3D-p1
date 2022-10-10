#include <iostream>
#include "List.h"

template <typename T>
void Display(List<T> _list)
{
    for (int i = 0; i < _list.Count(); i++)
        std::cout << _list[i] << " ";
    std::cout << std::endl;
}
int main()
{
    List<int> _list = List<int>(); 
    for (int i = 0; i < 10; i++)
        _list.Add(i * 2); 

    _list.Remove(3);

    Display(_list); 

    //for (int i = 0; i < _list.Count(); i++)
        //std::cout << _list[i] << " ";  
}
