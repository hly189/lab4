

#ifndef TeamLeader_hpp
#define TeamLeader_hpp

#include <stdio.h>
/*
Author: Thanh le
CIS22B - Lab04

Program description: This header file that contain the declaration of Production class (a child of ProductionWorker class), its appropriate constructors, destructor, accessors, mutators, function and overload functions
*/
#include "ProductionWorker.hpp"

class TeamLeader : public ProductionWorker
{
private:
    double monthlyB;
    double requireTraningHour, attendedTrainingHour;
    ProductionWorker teamLead;
public:
    TeamLeader();
    TeamLeader(double, int, int);
    ~TeamLeader();
    
// Mutator
    void setMontlyBonus(double);
    void setRequireTraningHour(double hour);
    void setAttendedTrainingHour(double hour);
    
  // Accessor
    double getMontlyBonus();
    double getRequireTrainingHour();
    double getAttendedTrainingHour();
    
   
    
    //overload
    friend std::istream & operator>>(std::istream&, TeamLeader&);
	void Output();
};
#endif /* TeamLeader_hpp */


