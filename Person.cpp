/*
 * Person.cpp
 *
 *  Created on: May 23, 2015
 *      Author: Benda
 */

#include "Person.h"

Person::Person()
{
    
}

Person::Person(const string Name, const string pId, const string phNum) {
	this->id = pId;
	name = Name;
	phoneNumber = phNum;
}

const string& Person::getName() const {
	return name;
}

void Person::setName(const string& Name) {
	this->name = Name;
}

const string& Person::getId() const {
	return id;
}

const string Person::getPhoneNumber() const {
	return phoneNumber;
}

void Person::setPhoneNumber(const string phoneNumber) {
	this->phoneNumber = phoneNumber;
}

Person::~Person() {
	// TODO Auto-generated destructor stub
}


void Person::PrintPerson()
{
    string temp = "ID: " + id + "\nName: " + name + "\nPhone: " + phoneNumber;
    cout << temp << endl;
    LogFile << temp << endl;
}



