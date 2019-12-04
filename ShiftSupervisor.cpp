/*
Author: Thanh le
CIS22B - Lab04

Description: This program provide the definition of constructor, destructor, accessor, mutator, function and overload functions of the ShiftSupervisor.h file. The program also ask user for appropriate data input (annualBonus, annualSalary), check if the supervisor will get the bonus and print those details of that employee.


PSEUDOCODE:
I. Define and initialize cosntructors, destructors, mutators, accessors
II. Define checkPoint function for input validation
III. Prompt user for appropriate input:
 1. Get appropriate input from Employee class
 2. Allow user to provide data input for annual bonus & validate input
 3. Allow user to provide data input for annual salary & validate input
 4. Check if the supervisor has hit the production goals & assign the proper value for employee's annual bonus
IV. Print out the appropriate message for employee's detail
*/
#include "ShiftSupervisor.hpp"

//Constructors and destructor
ShiftSupervisor::ShiftSupervisor(){}; //function constructor
ShiftSupervisor::ShiftSupervisor(double bonus, double salary) //constructor w/ all parameters
{
    annualBonus = bonus;
    annualSalary = salary;
}
ShiftSupervisor::~ShiftSupervisor(){}; //default destructor

// Mutator
void ShiftSupervisor::setSalary(double salary) {annualSalary = salary;}
void ShiftSupervisor::setBonus(double bonus) {annualBonus = bonus;}

// Accessor
double ShiftSupervisor::getAnnualBonus() {return annualBonus;};
double ShiftSupervisor::getAnnualSalary(){return annualSalary;};

//Functions
double ShiftSupervisor::checkPoint (double input)
{ //This function is used to validate the input for annual salary and annual pay
    while (input <= 0)
    {
        std::cout << "Invalid entry. Value must be greater or equal 0. Enter again: ";
        std::cin >> input;
    }
    return input;
}

//II. Prompt user for appropriate input:
std::istream & operator>>(std::istream &input, ShiftSupervisor &Emp)
{
//1. Get appropriate input from Employee class
    input >> Emp.supervisor;
//2. Allow user to provide data input for annual salary & validate input
    double salary = 0.0;
    std::cout << "Shift supervisor annual salary: $";
    input >> salary;
    Emp.annualSalary = Emp.checkPoint(salary);//validate input
//3. Allow user to provide data input for annual bonus & validate input
    char option;
    double bonus = 0.0;
    std::cout << "Shift supervisor annual bonus: $";
    input >> bonus;
    bonus = Emp.checkPoint(bonus); //validate input
//4. Check if the supervisor has hit the production goals & assign the proper value for employee's annual bonus
    std::cout << "Is the employee hit the production goals? ";
    input >> option;
    // Condition to assign the proper value for employee's annual bonus
    if (toupper(option) == 'Y')
        Emp.annualBonus = bonus;
    else
        Emp.annualBonus = 0;
    return input;
}

//IV. Print out the appropriate message for employee's detail
void ShiftSupervisor::Output()
{
	std::cout << supervisor.Output();//print the output in Employee.ccp first
	std::cout << "Employee Annual Bonus: $" << getAnnualBonus() << std::endl;
	std::cout << "Employee Annual Salary: $" << getAnnualSalary() << std::endl;
	std::cout << "Employee Annual Total Salary: $" << getAnnualBonus() + Emp.getAnnualSalary() <<std::endl;
}

