#include <iostream>
#include "List.h"



int main()
{
    List<std::string> _list = List<std::string>();
    _list.AddLast("Hello");
    _list.AddLast("Coucou");

    _list.Display(); 

    _list.AddBefore("Hello", "Toto");
    _list.AddAfter("Hello", "Toto");

    _list.Display();

    _list.RemoveFirst();
    _list.RemoveLast(); 

    _list.Display();

    

    _list.Display();

    _list.Remove("Hello"); 
    
    _list.Display();
    _list.Count(); 

    _list.Clear(); 

    _list.Display();




}
