/*
Author: Thanh le
CIS22B - Lab04

Description: This program provide the definition of constructor, destructor, accessor, mutator, function and overload functions of the Employee.h file. The program also ask user for appropriate data input (name, ID, date hired) and print those details of that employee.


PSEUDOCODE:
I. Define and initialize cosntructors, destructors, mutators, accessors
II. Prompt user for appropriate input:
 1. Allow user to provide data input for Employee's first name, last name. With the data given, the program will populate the employee's full name
 2. Allow user to input employee's ID
 3. Allow user to input employee's hired day
III. Print out the appropriate message for employee's detail
*/

#include "Employee.hpp"

//I. Define and initialize cosntructors, destructors, mutators, accessors
Employee::Employee() {}; //function constructor
Employee::Employee (std::string n, std::string ID, std::string hired_D)
{
    name = n;
    EmpID = ID;
    hiredDate = hired_D;
}
Employee::~Employee() {}; //defualt destructor

//Mutator
void Employee::setName(std::string ln, std::string fn)
{   lastN = ln;
    firstN = fn;
    name = lastN + firstN;
}
void Employee::setEmpID(std::string ID) {EmpID = ID;}
void Employee::setHiredDay(std::string hired_day) {hiredDate = hired_day;}
//Accessor
std::string Employee::getName() {return name;}
std::string Employee::getEmpID() {return EmpID;}
std::string Employee::getHiredDay(){return hiredDate;}
   
//II. Prompt user for appropriate input:
std::istream & operator>>(std::istream &input, Employee &Emp)
{
    std::string name, Emp_ID, hired_Date;
    int day, month, year;
//1. Allow user to provide data input for Employee's first name, last name.
    std::cout << "Enter employee first name: ";
    input >> Emp.firstN;
    std::cout << "Enter employee last name: ";
    input >> Emp.lastN;
// populate the employee's full name
    Emp.name = Emp.firstN + " " + Emp.lastN;
//2. Allow user to input employee's ID
    std::cout << "Enter employee ID: ";
    input >> Emp.EmpID;
//3. Allow user to input employee's hired day
    //Get and validate date
    std::cout << "Enter day hired (dd): ";
    input >> day;
    while (day < 1 || day > 31)
    {
        std::cout << "Invalid entry. Re-enter day hired (01-31): ";
        input >> day;
    }
    //Get and validate month
    std::cout << "Enter month hired (mm): ";
    input >> month;
    while (month < 1 || month > 12)
    {
        std::cout << "Invalid entry. Re-enter month hired (01-12): ";
        input >> month;
    }
    //Get and validate year
    std::cout << "Enter year hired (yyyy): ";
    input >> year;
    while (year < 1930)
    {
        std::cout << "Invalid entry. Re-enter year hired (yyyy): ";
        input >> year;
    }
    //Populate the hiredDay as string
    Emp.hiredDate = std::to_string(month) + "/" + std::to_string(day) + "/" + std::to_string(year);
    return input;
}

//III. Print out the appropriate message for employee's detail
void Employee::Output()
{
    std::cout << "----------------EMPLOYEE DETAILS----------------" <<std::endl;
	std::cout << "Employee Name: " << getName() << std::endl; // print employee's name
	std::cout << "Empoyee ID: " << getEmpID() << std::endl; // print employee's ID
	std::cout << "Employee Hired Day: " << getHiredDay() << std::endl; // print employee's hired day
 
}

