/*
Author: Thanh le
CIS22B - Lab04

Description: This program provide the definition of constructor, destructor, accessor, mutator, function and overload functions of the ProductionWorker.h file. The program also ask user for appropriate data input (shift, hour rate) and print those details of that employee.


PSEUDOCODE:
I. Define and initialize cosntructors, destructors, mutators, accessors
II. Define checkPoint function for input validation
III. Prompt user for appropriate input:
 1. Get appropriate input from Employee class
 2. Allow user to provide data input for employee's shift & validate input
 3. Allow user to input employee's hour rate & validate input
 4. Populate the employee's hour rate and shift of employee object
IV. Print out the appropriate message for employee's detail
*/
#include "ProductionWorker.hpp"
#include "Employee.hpp"

//I. Define and initialize cosntructors, destructors, mutators, accessors
//Constructors & Destructors
ProductionWorker::ProductionWorker() {}; //function constructor
ProductionWorker::ProductionWorker(int s, double h_rate) //constructor takes all parameter
{
    shift = s;
    hourRate = h_rate;
}
ProductionWorker::~ProductionWorker (){}; // default destructor
//Mutators
void ProductionWorker::setShift(int s) {shift = s;}
void ProductionWorker::setH_Rate(double h_rate) {hourRate = h_rate;}
//Accessors
int ProductionWorker::getShift () {return shift;}
double ProductionWorker::getH_Rate() {return hourRate;}

//Functions
//II. Define checkPoint function for input validation
double ProductionWorker::checkPoint (double input)
{ //this function is used to validate the double input
    while (input <= 0)
    {
        std::cout << "Invalid entry. Value must be greater or equal 0. Enter again: ";
        std::cin >> input;
    }
    return input;
}
//III. Prompt user for appropriate input:
std::istream & operator>>(std::istream &input, ProductionWorker &Emp)
{
    //1. Get appropriate input from Employee class
    input >> Emp.employee;
    int shift;
    double hourRate;
    //2. Allow user to provide data input for shift & validate input
    std::cout << "Employee's shift 1-Day  2-Night. Your choice: ";
    input >> shift;
    while (shift < 1 || shift > 2) //Input validation
    {
        std::cout << "Invalid entry. Enter employee's shift: 1/Day shift 2/Night shift. Your choice: ";
              input >> shift;
    }
     //3. Allow user to input hour rate & validate input
    std::cout << "Enter employee's hour pay rate: $ ";
    input >> hourRate;
    hourRate = Emp.checkPoint(hourRate); //input validation
    //4. Populate the employee's hour rate and shift of employee object
    Emp.hourRate = hourRate;
    Emp.shift = shift; 
    return input;
}
//IV. Print out the appropriate message for employee's detail
std::ostream & operator<<(std::ostream &output, ProductionWorker &Emp)
{
	Employee emloyee = Emp.employee; 
	emloyee.Output(); //print the output in Employee.ccp first
    output << "Employee Hour Rate: $" << Emp.getH_Rate() << std::endl;
    output << "Employee Shift: " ;
    if (Emp.getShift() == 1) //output for each shift of choice
        output<< "1 - day" << std::endl;
    else
        output << "2 - night" << std::endl;
    return output;
}
