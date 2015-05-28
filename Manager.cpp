/*
 * Manager.cpp
 *
 *  Created on: May 23, 2015
 *      Author: Benda
 */

#include "Manager.h"


Manager::Manager(const string id, const string& Name, const long phNum, string compId, SmartPtr<Project>& currProj, int TProjH, int THrs, int exp, bool employ, int hrsPDay, vector<string>& knwdP, vector<string>& fieldP, vector<string>& fieldA) : Employee(id, Name, phNum, compId, currProj, TProjH, THrs, exp, employ, hrsPDay)
    {
        Programmer::setKnowedLangs(knwdP);
        Programmer::setFields(fieldP);
        Artist::setFields(fieldA);
    
}

Manager::~Manager() {
	// TODO Auto-generated destructor stub
}

void Manager::Printmanger(){
    
}

