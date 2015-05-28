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

Person::Person(const string id, const string& Name, const long phNum) {
	this->id = id;
	name = Name;
	phoneNumber = phNum;
}

const string& Person::getName() const {
	return name;
}

void Person::setName(const string& Name) {
	this->name = Name;
}

const string Person::getId() const {
	return id;
}

const long Person::getPhoneNumber() const {
	return phoneNumber;
}

void Person::setPhoneNumber(const long phoneNumber) {
	this->phoneNumber = phoneNumber;
}

Person::~Person() {
	// TODO Auto-generated destructor stub
}

//change check again and again
void Person::PrintPerson()
{
    cout<<"ID:"<<getId()<<endl;
    cout<<"Name:"<<getName()<<endl;
    cout<<"Phone number:"<<getPhoneNumber()<<endl;
    
    WriteTofile();
    LogFile<<"ID:"<<getId()<<endl;
    LogFile<<"Name:"<<getName()<<endl;
    LogFile<<"Phone number:"<<getPhoneNumber()<<endl;
    ~WriteTofile();
}



