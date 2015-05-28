/*
 * Artist.cpp
 *
 *  Created on: May 23, 2015
 *      Author: Benda
 */

#include "Artist.h"

Artist::Artist() : Employee()
{
    
}


Artist::Artist(const string id, const string& Name, const long phNum, string compId, string *currProj, int TProjH, int THrs, int exp, bool employ, int hrsPDay, vector<string>& flds) : Employee(id, Name, phNum, compId, currProj, TProjH, THrs, exp, employ, hrsPDay){

	fields = flds;
}

Artist::~Artist() {
	// TODO Auto-generated destructor stub
}


vector<string>& Artist::getFields() {
	return fields;
}



void Artist::setFields(vector<string>& fields) {
	this->fields = fields;
}

void Artist::PrintArtist(){
    cout<<"The artist fieldes are:"<<endl;
    for (int i=0; i<fields.size();i++){
        cout << fields[i] << endl;
    }
    
}
void  Artist::Print(){

    
    PrintPerson();
    cout<<getCompanyId()<<endl;
    cout<<"Total Hours:"<<getTotalHours()<<endl;
    cout<<"Experience:"<<getExperience()<<endl;
    cout<<"Total project hours"<<getTotalProjHours()<<endl;
    cout<<"Hours per day"<<getHoursPerDay()<<endl;
    cout<<"Current project ID"<<getCurrentProjectId()<<endl;
    cout<<"Total project work"<<getTotalprojwork()<<endl;
    cout<<"The artist fieldes are:"<<endl;
    for (int i=0; i<fields.size();i++){
        cout << fields[i] << endl;
    }

    
    LogFile<<getCompanyId()<<endl;
    LogFile<<"Total Hours:"<<getTotalHours()<<endl;
    LogFile<<"Experience:"<<getExperience()<<endl;
    LogFile<<"Total project hours"<<getTotalProjHours()<<endl;
    LogFile<<"Hours per day"<<getHoursPerDay()<<endl;
    LogFile<<"Current project ID"<<getCurrentProjectId()<<endl;
    LogFile<<"Total project work"<<getTotalprojwork()<<endl;
    LogFile<<"The artist fieldes are:"<<endl;
    for (int i=0; i<fields.size();i++){
        LogFile << fields[i] << endl;
    }
 
}


