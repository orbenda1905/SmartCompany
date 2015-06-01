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


Programmer::Programmer(const string Name, const string pId, const string phNum, string compId, int THrs, string currProj, int currProjHrs, int exp, int hrsPDay, bool employ, vector<string> langs, vector<string> flds) : Employee(Name, pId, phNum, compId, THrs, currProj, currProjHrs, exp, hrsPDay, employ){
	
	
    knowedLangs = langs;
	fields = flds;

}

vector<string>& Programmer::getFields() {
	return fields;
}

vector<string>& Programmer::getKnowedLangs() {
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

void Programmer::PrintProg(){
    cout<<"The Programmer field:"<<endl;
    for (int i=0; i<fields.size();i++){
        cout << fields[i] <<",";
    }
    cout<<"The programmer knowd languges:"<<endl;
    for (int i=0; i<knowedLangs.size();i++){
        cout << knowedLangs[i] <<",";
    }
}


void Programmer::Print(){

PrintPerson();
cout<<getCompanyId()<<endl;
cout<<"Total Hours:"<<getTotalHours()<<endl;
cout<<"Experience:"<<getExperience()<<endl;
cout<<"Total project hours"<<getTotalProjHours()<<endl;
cout<<"Hours per day"<<getHoursPerDay()<<endl;
cout<<"Current project ID"<<getCurrentProjectId()<<endl;
cout<<"Total project work"<<getTotalProjHours()<<endl;
cout<<"The Programmer field:"<<endl;
    for (int i=0; i<fields.size();i++){
        cout << fields[i] <<",";
    }
cout<<"The programmer knowd languges:"<<endl;
    for (int i=0; i<knowedLangs.size();i++){
        cout << knowedLangs[i] <<",";
    }

    
    PrintPerson();
    LogFile<<getCompanyId()<<endl;
    LogFile<<"Total Hours:"<<getTotalHours()<<endl;
    LogFile<<"Experience:"<<getExperience()<<endl;
    LogFile<<"Total project hours"<<getTotalProjHours()<<endl;
    LogFile<<"Hours per day"<<getHoursPerDay()<<endl;
    LogFile<<"Current project ID"<<getCurrentProjectId()<<endl;
    LogFile<<"Total project work"<<getTotalProjHours()<<endl;
    LogFile<<"The Programmer field:"<<endl;
    for (int i=0; i<fields.size();i++){
        LogFile << fields[i] <<",";
    }
    LogFile<<"The programmer knowd languges:"<<endl;
    for (int i=0; i<knowedLangs.size();i++){
        LogFile << knowedLangs[i] <<",";
    }
}