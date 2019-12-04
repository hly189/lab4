
#ifndef ShiftSupervisor_hpp
#define ShiftSupervisor_hpp

#include <stdio.h>
/*
Author: Thanh le
CIS22B - Lab04

Program description: This header file that contain the declaration of ShiftSupervisor class (a child of Employee class), its appropriate constructors, destructor, accessors, mutators, function and overload fucntions
*/
#include "Employee.hpp"

class ShiftSupervisor : public Employee {
private:
    double annualBonus;
    double annualSalary;
    Employee supervisor;
public:
    ShiftSupervisor();
    ShiftSupervisor(double, double);
    ~ShiftSupervisor();
    
    // Mutator
       void setBonus(double);
       void setSalary(double);
    
    // Accessor
    double getAnnualBonus();
    double getAnnualSalary();
    
    //function
    double checkPoint (double);
    
    //overload
    friend std::istream & operator>>(std::istream&, ShiftSupervisor&);
    friend std::ostream & operator<<(std::ostream&, ShiftSupervisor&);
};


#endif /* ShiftSupervisor_hpp */
