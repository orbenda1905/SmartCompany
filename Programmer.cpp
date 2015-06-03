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
    knowedLangs.clear();
    fields.clear();
}

void Programmer::setKnowedLangs(vector<string> langs) {
	knowedLangs = langs;
}

void Programmer::setFields(vector<string> field) {
	this->fields = fields;
}

void Programmer::printProgrammer(){
    printEmployee();
    printFields();
}

void Programmer::printFields()
{
    cout << "Languages: ";
    LogFile << "Languages: ";
    for (int i = 0; i < knowedLangs.size(); i++)
    {
        cout << knowedLangs[i] << endl;
        LogFile << knowedLangs[i] << endl;
    }
    cout << "Fields: ";
    LogFile << "Fields: ";
    for (int i = 0; i < fields.size(); i++)
    {
        cout << fields[i] << endl;
        LogFile << fields[i] << endl;
    }
}
