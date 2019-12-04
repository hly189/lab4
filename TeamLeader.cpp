/*
Author: Thanh le
CIS22B - Lab04

Description: This program provide the definition of constructor, destructor, accessor, mutator, function and overload functions of the TeamLeader.h file. The program also ask user for appropriate data input for the team leader (monthly bonus, required training hours, attended training hours), check if the team leader will get the monthly bonus and print those details of that employee.


PSEUDOCODE:
I. Define and initialize cosntructors, destructors, mutators, accessors
II. Prompt user for appropriate input:
 1. Get appropriate input from Production Worker class
 2. Allow user to provide data input for team leader's required training hour & validate input
 3. Allow user to provide data input for team leader's attended training hour & validate input
 4. Allow user to provide data input for team leader's monthly bonus & validate input
 5. Check if the team leader has hit the requirement hours & assign the proper value for team leader's monthly bonus
III. Print out the appropriate message for employee's detail
*/
#include "TeamLeader.hpp"

//I. Define and initialize cosntructors, destructors, mutators, accessors
//Cosntructors & Destructor
TeamLeader::TeamLeader(){}; // function constructor
TeamLeader::TeamLeader(double bonus, int rHour, int attHour) //constructor that take all paramaters
{
    monthlyB = bonus;
    requireTraningHour = rHour;
    attendedTrainingHour = attHour;
}
TeamLeader::~TeamLeader(){}; //default destructor

//Mutators
void TeamLeader::setMontlyBonus(double bonus){monthlyB = bonus;}
void TeamLeader::setRequireTraningHour(double reHour) {requireTraningHour = reHour;};
void TeamLeader::setAttendedTrainingHour(double atHour){attendedTrainingHour = atHour;}

//Accessors
double TeamLeader::getMontlyBonus(){return monthlyB; }
double TeamLeader::getRequireTrainingHour(){return requireTraningHour;}
double TeamLeader::getAttendedTrainingHour(){return attendedTrainingHour;}

//II. Prompt user for appropriate input:
std::istream & operator>>(std::istream &input, TeamLeader &Emp)
{
    double monthBonus;
 //1. Get appropriate input from Production Worker class
    input >> Emp.teamLead;
//2. Allow user to provide data input for team leader's required training hour & validate input
    std::cout << "Enter Require Training hour: ";
    input >> Emp.requireTraningHour;
    Emp.requireTraningHour = Emp.checkPoint (Emp.requireTraningHour);
//3. Allow user to provide data input for team leader's attended training hour & validate input
    std::cout << "Enter Attended Training hour: ";
    input >> Emp.attendedTrainingHour;
    Emp.attendedTrainingHour = Emp.checkPoint (Emp.attendedTrainingHour);
//4. Allow user to provide data input for team leader's monthly bonus & validate input
    std::cout << "Enter monthly bonus: $";
    input >> monthBonus;
    monthBonus = Emp.checkPoint (monthBonus);
 //5. Check if the team leader has hit the requirement hours & assign the proper value for team leader's monthly bonus
    if (Emp.getAttendedTrainingHour() < Emp.getRequireTrainingHour())
    {
        Emp.monthlyB = 0; // no bonus
    }
        else
    {
        Emp.monthlyB = monthBonus; // has bonus
    }
    return input;
}

//III. Print out the appropriate message for employee's detail
void TeamLeader::Output()
{
    std::cout << teamLead.Output(); //print the output in Employee.ccp first
	std::cout << "Employee Required Training Hour " << getRequireTrainingHour() << std::endl;
	std::cout << "Employee Attended Training Hour " << getAttendedTrainingHour() << std::endl;
    //Display appropriate message to employee if they receive the bonus or not and the actual bonus amount
    if (getMontlyBonus()==0)
		std::cout << "Required training hours is not meet this month." << std::endl;
    else
		std::cout << "Congratulation! Required training hours is met this month." << std::endl;
		std::cout << "Employee Monthly Bonus: $" << getMontlyBonus() << std::endl;
}
