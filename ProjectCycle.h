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
	Project project;
	//date
	int projEmployees;
	SmartPtr<Employee> currentProjEmployees;

public:
	ProjectCycle();
	virtual ~ProjectCycle();
};



#endif /* PROJECTCYCLE_H_ */
