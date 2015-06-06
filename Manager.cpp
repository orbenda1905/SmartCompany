/*
 * Manager.cpp
 *
 *  Created on: May 23, 2015
 *      Author: Benda
 */

#include "Manager.h"


Manager::Manager(const string Name, const string pId, const string phNum, string compId, int THrs, string currProj, int currProjHrs, int exp, int hrsPDay, bool employ, vector<string> knwdP, vector<string> fieldP, vector<string> fieldA) : Employee(Name, pId, phNum, compId, THrs, currProj, currProjHrs, exp, hrsPDay, employ), Artist(), Programmer()
    {
        knowedLangs = knwdP;
        Programmer::fields = fieldP;
        Artist::fields = fieldA;
        
    
}

Manager::~Manager() {
    LogFile << "manager " + getCompanyId() + " destroyed" << endl;
}

void Manager::Printmanger(){
    printEmployee();
    Programmer::printFields();
    Artist::printFields();
    cout << "Projects amount: " << projCount << endl;
    LogFile << "Projects amount: " << projCount << endl;
}

