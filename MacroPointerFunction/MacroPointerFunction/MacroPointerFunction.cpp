#include <iostream>

void Display(const std::string& _msg)
{
    std::cout << _msg << std::endl; 
}


class A
{
public:
    void HelloKitty()
    {
        std::cout << "Hello kitty" << std::endl;
    }
    int Add(const int _a, const int _b)
    {
        return _a + _b;
    }
};

class B : public A
{
public: 
    void Test()
    {
        std::cout << "TEST" << std::endl; 
    }
};

int main()
{
    //void(*ptr)(const std::string&);
    //ptr  = &Display; 
    //ptr("Hello");
    //void(A::*ptr)();
    //ptr = &A::HelloKitty; 
    //A a;
    //(a.*ptr)();
    //A* a = new A(); 
    //int(A:: * ptr)(const int, const int);
    //ptr = &A::Add; 
    //std::cout << (a->*ptr)(10, 5);

    //B* b = new B();
    //void (A:: * ptr) ();
    //ptr = reinterpret_cast<void(A::*)()>(&B::Test);
    //(b->*ptr)();

    A* a = new A();
    typedef void(A::* Function)();

    Function _function = &A::HelloKitty;
    (a->*_function)();


    return 0;
}

