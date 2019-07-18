#include<iostream>
#include<sstream>
#include "input_converter.hpp"
#include "student_converter.hpp"
#include "double_converter.hpp"

double calculator(int* points, int* weights, int x, int i, int *scores);
double calculator(int* points, int* weights, int x,  int i, int *scores)
{
    double grade = 0;
    unsigned int j;
    for (j=1; j < x; j++)
    {   
        unsigned int k = j-1;
        unsigned int n = scores[i*x + j];
        double final = (n/double(points[k])) * double(weights[k]);
 
        grade += final;
    }
    return grade;
}
int main()
{
       

    unsigned int ga;
    unsigned int i;
    std::cin >> ga;
    int* points  = new int[ga];
    int* weights = new int[ga];
    input_converter(points, ga);
    input_converter(weights, ga);
   
 
    unsigned int st;
    std::cin >> st;
    Student* students = new Student[st];
    student_converter(students, st);
   
   
    unsigned int rs;
    std::cin >> rs;
    unsigned int x = ga + 1;   
    int raw_scores[rs * x];
    unsigned int j;
    
    for (i = 0; i <rs; i++)
        {
    	    for (j=0; j < x; j++)
            {
                
                std::cin >> raw_scores[i*x + j];
            }
        }
   
    std::cout << "TOTAL SCORES" << std::endl;     
    for (i=0; i < rs; i++)
        {
            for (j = 0; j < st ; j++)
            {
            if (std::stoi(students[j].ID) == raw_scores[i * x + 0])
                std::cout << students[j].ID << ' ' << students[j].grade_option << ' ' <<  students[j].name << ' ' << calculator(points, weights, x, i, raw_scores) << std::endl;
            }
        }
    
    unsigned int m;
    unsigned int cp;
    std::cin >> cp;
    for (i=1; i<= cp; i++)
	    {   
        double* cutoff_points = new double[cp];
        double_converter(cutoff_points, cp);
        std::cout << "CUTOFF POINT " << i << std::endl;
	    for (m=0; m < rs; m++)
	    {

	        for (j=0; j < st; j++)
            {    
                  if (std::stoi(students[j].ID) == raw_scores[m * x + 0])
                  {    
                       double letter = calculator(points, weights, x, m, raw_scores);
                       if (students[j].grade_option == "G")
                       {
		                    if (letter >= cutoff_points[0])
			                    std::cout << students[j].ID << ' ' << students[j].grade_option << ' ' << students[j].name << ' ' << "A" << std::endl;
			                else if (letter >= cutoff_points[1])
			                    std::cout << students[j].ID << ' ' << students[j].grade_option << ' ' << students[j].name << ' ' << "B" << std::endl;
			                else if (letter >= cutoff_points[2])
				                std::cout << students[j].ID << ' ' << students[j].grade_option << ' ' << students[j].name << ' ' << "C" << std::endl;
                            else if (letter >= cutoff_points[3])
				                std::cout << students[j].ID << ' ' << students[j].grade_option << ' ' << students[j].name << ' ' << "D" << std::endl;
			                else         
                                 std::cout << students[j].ID << ' ' << students[j].grade_option << ' ' << students[j].name << ' ' << "F" << std::endl;
                       }
                       else
                       {  
                            if (letter >= cutoff_points[3])
				                std::cout << students[j].ID << ' ' << students[j].grade_option << ' ' << students[j].name << ' ' << "P" << std::endl;
		                    else
				                std::cout << students[j].ID << ' ' << students[j].grade_option << ' ' << students[j].name << ' ' << "NP" << std::endl;
                       }
		           }
           }             
	   
       
        }
    delete[] cutoff_points;
    }   

    delete[]points;
    delete[]weights;
    delete[]students;
    return 0;
}

