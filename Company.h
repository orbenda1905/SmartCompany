/*
 * Company.h
 *
 *  Created on: May 23, 2015
 *      Author: Benda
 */

#ifndef COMPANY_H_
#define COMPANY_H_
#include "Headers.h"
#include "Client.h"
#include "Employee.h"
#include "ProjectCycle.h"

class Company {
private:
	string name;
	map<SmartPtr<Client>, string> clients;
	map<SmartPtr<Employee>, string> employees;
	map<SmartPtr<ProjectCycle>, string> projects;

public:
	Company(string name);
//	Company(string name, Client& cList[], Employee& eList[]);
	void addEmployee();
	~Company();

};



#endif /* COMPANY_H_ */
