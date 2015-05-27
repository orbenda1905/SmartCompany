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
	map<SmartPtr<Project>, string> projects;
    map<SmartPtr<ProjectCycle>, string> cycles;

public:
	Company(string name);
	void addEmployee(SmartPtr<Employee>& worker);
    void addProject();
    void addProjCicle(string& projId, string& date);
    void speedUp();
	~Company();

};



#endif /* COMPANY_H_ */
