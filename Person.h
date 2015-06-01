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



class Person : public WriteToFile {
private:
	string id;
protected:
	string name;

	string phoneNumber;
	
public:
    Person();
	Person(const string Name, const string pId, const string phNum);
	virtual ~Person();
	const string& getName() const;
	void setName(const string& Name);
	const string& getId() const;
	const string getPhoneNumber() const;
	void setPhoneNumber(const string phoneNumber) ;
    void PrintPerson();
};

#endif /* PERSON_H_ */
