/*
 Author: Thanh le
 CIS22B - Lab04
 
 Program description: This program allows user to provide data input for different type of Employee and print the details of that Employee. The user can run the program multiple times until they decide to end.
 
 UML: Please refer to Lab04-UML-ThanhLe file
 
 PSEUDOCODE: For detail description of each class, please refer to each class .cpp file
 I. Prompt user for appropriate action
 1. Production Worker: Create an ProductionWorker object, get data and print data
 2. Shift Supervisor: Create an ShiftSupervisor object, get data and print data
 3. Team Leader: Create an TeamLeader object, get data and print data
 II. Prompt user for a continue or quit action
 */

#include <iostream>
#include <string>
#include <iomanip>
#include "ProductionWorker.hpp"
#include "ShiftSupervisor.hpp"
#include "ShiftSupervisor.hpp"
#include "TeamLeader.hpp"

using namespace std;

int main()
{
    int selection = 0;
    do{
//I. Prompt user for appropriate action
        cout << "What do you want to do ?" << endl;
        cout << "1. Production Worker. " << endl;
        cout << "2. Shift Supervisor. " << endl;
        cout << "3. Team Leader. " << endl;
        cout << "4. Exit. " << endl;
        cout << "Please Choose 1 - 4:  ";
        cin >> selection;
        cout <<endl;
        switch (selection)
        {
            case 1:
//Production Worker: Create an ProductionWorker object, get data and print data
            {
                cout << "-------------PRODUCTION WORKER INFO-------------" <<endl;
                ProductionWorker production; //create object
                cin >> production;//get data
                cout << endl;
                cout << production;//print data
                break;
            }
            case 2:
//Shift Supervisor: Create an ShiftSupervisor object, get data and print data
            {
                cout << "-------------SHIFT SUPERVISOR INFO-------------" <<endl;
                ShiftSupervisor shiftSupervisor; //create object
                cin >> shiftSupervisor; //get data
                cout << endl;
                shiftSupervisor.Output(); //print data
                break;
            }
            case 3:
//Shift Supervisor: Create an ShiftSupervisor object, get data and print data
            {
                cout << "---------------TEAM LEADER INFO---------------" <<endl;
                TeamLeader teamLeader; //create object
                cin >> teamLeader;//get data
                cout << endl;
                teamLeader.Output();//print data
                break;
            }
            default:
                break;
        }
        cout << endl;
//II. Prompt user for a continue or quit action
    }while (selection != 4);
    cout << "Programmed by Thanh Le \n";
    //system("pause");
    return 0;
}
