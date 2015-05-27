/*
 * ProjectCycle.h
 *
 *  Created on: May 24, 2015
 *      Author: Benda
 */

#ifndef PROJECTCYCLE_H_
#define PROJECTCYCLE_H_
#include "Headers.h"
#include "Project.h"
#include "Employee.h"

class ProjectCycle {
private:
	SmartPtr<Project>& project;
	//date
	int projEmployees;
    String& date;
	map<SmartPtr<Employee>, string> currentProjEmployees;

public:
	ProjectCycle(SmartPtr<Project>& project, string& data);
	virtual ~ProjectCycle();
    void speedUp();
};



#endif /* PROJECTCYCLE_H_ */
