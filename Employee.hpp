

#ifndef Employee_hpp
#define Employee_hpp

#include <stdio.h>
/*
Author: Thanh le
CIS22B - Lab04

Program description: This header file that contain the declaration of Employee class, its appropriate constructor, destructor, accessor, mutator, function and overload functions
*/
#include <iostream>
#include "Employee.hpp"

class Employee
{
private:
    std::string firstN, lastN, name;
    std::string EmpID;
    std:: string hiredDate;
    
    //virtual void print();
public:
    //Constructor
    Employee();
    Employee (std::string, std::string, std::string);
    ~Employee();
    
    //Accessor
    std::string getName();
    std::string getEmpID();
    std::string getHiredDay();
    
    //Mutator
    void setName(std::string, std::string);
    void setEmpID(std::string);
    void setHiredDay(std::string);
    
    //Functions
    friend std::istream & operator>>(std::istream&, Employee&);
    virtual void Output(); 
};

#endif /* Employee_hpp */
