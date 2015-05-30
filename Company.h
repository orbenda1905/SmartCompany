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
	map<string, SmartPtr<Client>> clients;
	map<string, SmartPtr<Employee>> employees;
	map<string, SmartPtr<Project>> projects;
    map<string, SmartPtr<ProjectCycle>> cycles;

public:
	Company(string name);
	void addEmployee(SmartPtr<Employee>& newWorker);
    void addProject(SmartPtr<Project>& newProject);
    void addProjCycle(string& projId, string& date);
    void addClient(SmartPtr<Client>& newClient);
    bool checkIfProjectExist(const string& projId);
    bool checkIfClientExist(const string& clientId);
    bool checkIfEmployeeExist(const string& empId);
    bool checkifCycleExist(const string& projId);
    void speedUp();
    void startArrange();
	~Company();
    void ForceQuit(string ProjectName);
    void PrintCompany();
    void startCycle(SmartPtr<ProjectCycle>& cylce, string& projId);
};



#endif /* COMPANY_H_ */
//itay
//noam roiz
//or the maniak