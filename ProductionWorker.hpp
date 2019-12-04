#ifndef ProductionWorker_hpp
#define ProductionWorker_hpp

#include <stdio.h>
/*
Author: Thanh le
CIS22B - Lab04

Program description: This header file that contain the declaration of Production class (a child of Employee class), its appropriate constructors, destructor, accessors, mutators, function and overload fucntions
*/
#include <iostream>
#include "Employee.hpp"

class ProductionWorker: public Employee
{
private:
    int shift;
    double hourRate;
    Employee employee;
public:
    //Constructor & Destructor
    ProductionWorker();
    ProductionWorker(int, double);
    ~ProductionWorker ();
    //Mutator
    void setShift(int);
    void setH_Rate(double);
    //Accessor
    int getShift ();
    double getH_Rate();
    //functions
    double checkPoint (double);
    friend std::istream & operator>>(std::istream&, ProductionWorker&);
    friend std::ostream & operator<<(std::ostream&, ProductionWorker&);
};


#endif /* ProductionWorker_hpp */
