/*
 * ProjectCycle.h
 *
 *  Created on: May 24, 2015
 *      Author: Benda
 */

#ifndef PROJECTCYCLE_H_
#define PROJECTCYCLE_H_
#include "Headers.h"
#include "Employee.h"
#include "WriteToFile.h"

class ProjectCycle : public WriteToFile {
private:
	SmartPtr<Project> project;
	int projEmployees;
    string& date;
	map<string, SmartPtr<Employee>> currentProjEmployees;

public:
	ProjectCycle(SmartPtr<Project> project, string& data);
    void addEmployee(SmartPtr<Employee>& emp);
	virtual ~ProjectCycle();
    void start();
    void speedUp();
};



#endif /* PROJECTCYCLE_H_ */
