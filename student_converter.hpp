#ifndef STUDENT_CONVERTER_HPP
#define STUDENT_CONVERTER_HPP

struct Student
    {
        std::string ID;
        std::string grade_option;
        std::string name;
    };


void student_converter(Student* a, int size);

#endif