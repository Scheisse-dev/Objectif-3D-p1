#include <iostream>
#include "List.h"



int main()
{
    List<int> _list = List<int>();
    _list.AddLast(0);
    _list.AddLast(1); 

    try
    {
       std::cout << _list.At(10) << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl; 
    }
    

    return 0; 
    /*
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
    */
    


}
