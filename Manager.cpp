/*
 * Manager.cpp
 *
 *  Created on: May 23, 2015
 *      Author: Benda
 */

#include "Manager.h"


Manager::Manager(const string id, const string& Name, const string phNum, string compId, string& currProj, int THrs, int exp, bool employ, int hrsPDay, vector<string>& knwdP, vector<string>& fieldP, vector<string>& fieldA) : Employee(id, Name, phNum, compId, currProj, THrs, exp, employ, hrsPDay)
    {
        knowedLangs = knwdP;
        Programmer::fields = fieldP;
        Artist::fields = fieldA;
        
    
}

Manager::~Manager() {
	// TODO Auto-generated destructor stub
}

void Manager::Printmanger(){
    LogFile<<"The project count:"<<projCount<<endl;
    LogFile<<"Total Projects:"<<totalProjects<<endl;
    
    cout<<"The project count:"<<projCount<<endl;
    cout<<"Total Projects:"<<totalProjects<<endl;
    PrintPerson();
    Artist::Print();
    Programmer::Print();
    
    
    
}//sometjing

