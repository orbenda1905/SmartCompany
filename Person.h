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



class Person {
private:
	string id;
protected:
	string name;

	long phoneNumber;
	
public:
	Person(const string id, const string& Name, const long phNum);
	virtual ~Person();
	const string& getName() const;
	void setName(const string& Name);
	string getId() const;
	long getPhoneNumber() const;
	void setPhoneNumber(long phoneNumber);
};

#endif /* PERSON_H_ */
