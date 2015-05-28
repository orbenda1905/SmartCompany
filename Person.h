/*
 * Person.h
 *
 *  Created on: May 23, 2015
 *      Author: Benda
 */

#ifndef PERSON_H_
#define PERSON_H_
#include "Headers.h"

using namespace std;



class Person : public WriteTofile {
private:
	string id;
protected:
	string name;

	long phoneNumber;
	
public:
    Person();
	Person(const string id, const string& Name, const long phNum);
	virtual ~Person();
	const string& getName() const;
	void setName(const string& Name);
	const string getId() const;
	const long getPhoneNumber() const;
	void setPhoneNumber(const long phoneNumber) ;
    void PrintPerson();
};

#endif /* PERSON_H_ */
