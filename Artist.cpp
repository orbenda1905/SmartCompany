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


Artist::Artist(const string Name, const string pId, const string phNum, string compId, int THrs, string currProj, int currProjHrs, int exp, int hrsPDay, bool employ, vector<string> flds) : Employee(Name, pId, phNum, compId, THrs, currProj, currProjHrs, exp, hrsPDay, employ){

	fields = flds;
}

Artist::~Artist() {
    fields.clear();
}


vector<string>& Artist::getFields() {
	return fields;
}



void Artist::setFields(vector<string> fields) {
	this->fields = fields;
}

void  Artist::printArtist()
{
    printEmployee();
    printFields();

}

void Artist::printFields()
{
    cout<<"Fields:"<<endl;
    LogFile << "Fields: " << endl;
    for (int i=0; i<fields.size();i++){
        cout << fields[i] << endl;
        LogFile << fields[i] << endl;
    }
}

