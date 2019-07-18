#include<iostream>
#include<string>
#include "student_converter.hpp"

void student_converter(Student* a, int size)
{	
    int i;
    for (i = 0; i<size; i++)
    {  
        getline(std::cin, a[i].ID, ' ');
        getline(std::cin, a[i].grade_option, ' ');
        getline(std::cin, a[i].name);
    }
}