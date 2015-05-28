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


Artist::Artist(const string id, const string& Name, const long phNum, string compId, Project& currProj, int TProjH, int THrs, int exp, bool employ, int hrsPDay, vector<string>& flds){
	Employee(id, Name, phNum, compId, currProj, TProjH, THrs, exp, employ, hrsPDay);
	fields = flds;
}

Artist::~Artist() {
	// TODO Auto-generated destructor stub
}


vector<string>& Artist::getFields() const {
	return fields;
}

void Artist::setFields(vector<string>& fields) {
	this->fields = fields;
}


void Artist::setFields(vector<string>& fields) {
	this->fields = fields;
}
