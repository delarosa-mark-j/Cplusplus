#include<iostream>
#include "input_converter.hpp"

void input_converter(int* a, int size)
{   
    int i;
    for (i = 0; i < size; i++)
    {
        std::cin >> a[i];
 
    }
}