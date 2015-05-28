/*
 * Programmer.cpp
 *
 *  Created on: May 23, 2015
 *      Author: Benda
 */

#include "Programmer.h"

Programmer::Programmer() : Employee()
{
    
}


Programmer::Programmer(const string id, const string& Name, const long phNum, string compId, SmartPtr<Project>& currProj, int TProjH, int THrs, int exp, bool employ, int hrsPDay, vector<string>& langs, vector<string>& flds){
	Employee(id, Name, phNum, compId, currProj, TProjH, THrs, exp, employ, hrsPDay);
	knowedLangs = langs;
	fields = flds;

}

const vector<string>& Programmer::getFields() const {
	return fields;
}

const vector<string>& Programmer::getKnowedLangs() const {
	return knowedLangs;
}

Programmer::~Programmer() {
	// TODO Auto-generated destructor stub
}

void Programmer::setKnowedLangs(vector<string>& langs) {
	knowedLangs = langs;
}

void Programmer::setFields(vector<string>& field) {
	this->fields = fields;
}

void Programmer::Print(){

PrintPerson();
cout<<getCompanyId()<<endl;
cout<<"Total Hours:"<<getTotalHours()<<endl;
cout<<"Experience:"<<getExperience()<<endl;
cout<<"Total project hours"<<getTotalProjHours()<<endl;
cout<<"Hours per day"<<getHoursPerDay()<<endl;
cout<<"Current project ID"<<getCurrentProjectId()<<endl;
cout<<"Total project work"<<getTotalprojwork()<<endl;
cout<<"The Programmer field:"<<endl;
    for (int i=0; i<fields.size();i++){
        cout << fields[i] <<",";
    }
cout<<"The programmer knowd languges:"<<endl;
    for (int i=0; i<knowedLangs.size();i++){
        cout << knowedLangs[i] <<",";
    }

}