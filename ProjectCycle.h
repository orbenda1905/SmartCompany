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
#include "Project.h"
#include "Manager.h"

class ProjectCycle : public WriteToFile {
private:
	SmartPtr<Project> project;
	int projEmployees;
    string& date;
	map<string, SmartPtr<Employee>> currentProjEmployees;
    bool stop = false;

public:
	ProjectCycle(SmartPtr<Project>& project, string& data);
    void addEmployee(SmartPtr<Employee> emp);
    virtual ~ProjectCycle();
    SmartPtr<Project>& getProject();
    void checkFinishedEmployee();
    void speedUp();
    void setStop(bool status);
    void removeEmployee(string empId);
};



#endif /* PROJECTCYCLE_H_ */
