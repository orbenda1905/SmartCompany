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


