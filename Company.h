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
	void addEmployee(SmartPtr<Employee>& newWorker);
    void addProject(SmartPtr<Project>& newProject);
    void addProjCicle(string& projId, string& date);
    void addClient(SmartPtr<Client>& newClient);
    bool checkIfProjectExist(string& projId);
    bool checkIfClientExist(string& clientId);
    bool CheckIfEmployeeExist(string& empId);
    bool checkifCycleExist(string& projId);
    void speedUp();
    void startArrange();
	~Company();
    void ForceQuit(string ProjectName);
    void PrintCompany();
};



#endif /* COMPANY_H_ */
//itay