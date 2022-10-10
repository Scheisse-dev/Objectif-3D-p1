#include <iostream>


int main()
{
    std::string _t = "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++.+++++++++++++++++++++++++++++.+++++++..+++.";
    int ascii = 0;
    for (char c : _t)
    {
        ascii = c == '+' ? ascii + 1 : c == '-' ? ascii - 1 : ascii; 
        if (c == '.')std::cout << (char)ascii; 
    }
}

