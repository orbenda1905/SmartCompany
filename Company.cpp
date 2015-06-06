/*
 * Company.cpp
 *
 *  Created on: May 23, 2015
 *      Author: Benda
 */

#include "Company.h"


Company::Company(string name) {
	this->name = name;
}

void Company::addEmployee(SmartPtr<Employee>& newWorker)
{
    string line;
    if (checkIfEmployeeExist(newWorker->getCompanyId()))
    {
        line = "employee " + newWorker->getCompanyId() + " already exist";
        cout << line << endl;
        LogFile << line << endl;
        delete newWorker;
        return;
    }
    else
    {
        employees.emplace(newWorker->getCompanyId(), newWorker);
    }
    return;
}

void Company::speedUp()
{
    string line;
    for (map<string, SmartPtr<ProjectCycle>>::iterator it = cycles.begin(); it != cycles.end(); ++it)
    {
        it->second->speedUp();
    }
    checkFinished();
}

void Company::checkFinished()
{
    string projId;
    int flag = 0;
    for (map<string, SmartPtr<ProjectCycle>>::iterator it = cycles.begin(); it != cycles.end(); it++)
    {
        if (it->second->getProject()->getNeedToRemove())
        {
            if (flag == 1)
            {
                cycles.erase(projId);
                flag = 0;
            }
            flag = 1;
            projId = it->first;
            projects.erase(projId);
            string temp = "project " + projId + " and his cycle has been destronyed";
            cout << temp << endl;
            LogFile << temp << endl;
        }
    }
    if (flag == 1)
    {
        cycles.erase(projId);
        cout << "project cycle " + projId + " destroyed" << endl;
    }
}

void Company::addProjCycle(string projId, string date){
    if (checkifCycleExist(projId)){
        string temp = "project cycle" + projId + "already exist";
        cout << temp << endl;
        LogFile << temp << endl;
        return;
    }
    else
    {
        SmartPtr<ProjectCycle> cycle = new ProjectCycle(projects.at(projId), date);
        cycles.emplace(projId, cycle);
    }
    return;
}

void Company::addProject(SmartPtr<Project>& newProject)
{
    string line;
    if (checkIfProjectExist(newProject->getProjId()))
    {
        line = "project " + newProject->getProjId() + "already exist";
        cout << line << endl;
        LogFile << line << endl;
        delete newProject;
        return;
    }
    else
    {
        projects.emplace(newProject->getProjId(), newProject);
    }
    return;
}

void Company::addClient(SmartPtr<Client>& newClient)
{
    string line;
    if (checkIfClientExist(newClient->getId()))
    {
        line = "clinet " + newClient->getId() + " already exist";
        cout << line << endl;
        LogFile << line << endl;
        delete newClient;
        return;
    }
    else
    {
        clients.emplace(newClient->getId(), newClient);
    }
    return;
}

Company::~Company() {
    cycles.clear();
    clients.clear();
    employees.clear();
    projects.clear();
    string line = "company " + name + " deleted";
    cout << line << endl;
    LogFile << line << endl;
}


void Company::startArrange(){
    for (map<string, SmartPtr<Client>>::iterator it = clients.begin(); it != clients.end(); it++)
    {
        if (projects.count(it->second->getProjectId()) == 1)
        {
            projects.at(it->second->getProjectId())->setClient(it->second);
        }
    }
    for (map<string, SmartPtr<ProjectCycle>>::iterator it = cycles.begin(); it != cycles.end(); it++)
    {
        startCycle(it->second, it->second->getProject()->getProjId());
    }
}

bool Company::checkIfProjectExist(const string& projId){
    if (projects.count(projId) == 0) return false;
    return true;
    
}

bool Company::checkIfClientExist(const string& clientId){
    if (clients.count(clientId) == 0) return false;
    return true;
}

bool Company::checkIfEmployeeExist(const string& empId){
    if (employees.count(empId) == 0) return false;
    return true;
}

bool Company::checkifCycleExist(const string& projId){
    if (cycles.count(projId) == 1) return true;
    else return false;
}

void Company::PrintCompany(){
    LogFile << "----printing company " + name + "-------" << endl;
    printEmployees();
    LogFile << endl;
    printProjects();
    LogFile << endl;
    printCycles();
    LogFile << endl;
    printClients();
    LogFile << endl;
}

void Company::startCycle(SmartPtr<ProjectCycle>& cycle, string& projId)
{
    for (map<string, SmartPtr<Employee>>::iterator it = employees.begin(); it != employees.end(); ++it)
    {
        if (it->second->getCurrentProjectId() == projId)
        {
            cycle->addEmployee(it->second);
        }
    }
    cycle->getProject()->beginTheProject();
}

void Company::printCycles()
{
    LogFile << "---Company Project Cycles:---" << endl;
    for (map<string, SmartPtr<ProjectCycle>>::iterator it = cycles.begin(); it != cycles.end(); it++)
    {
        LogFile << it->first << endl;
        LogFile << endl;
    }
}

void Company::printProjects()
{
    LogFile << "---Company Projects:---" << endl;
    for (map<string, SmartPtr<Project>>::iterator it = projects.begin(); it != projects.end(); it++)
    {
        it->second->print();
        LogFile << endl;
    }
}

void Company::printClients()
{
    LogFile << "---Company Clients:---" << endl;
    for (map<string, SmartPtr<Client>>::iterator it = clients.begin(); it != clients.end(); it++)
    {
        it->second->PrintClient();
        LogFile << endl;
    }
}

void Company::printClient(string pId)
{
    LogFile << "--Cilent:--" << endl;
    if (clients.count(pId) == 0)
    {
        LogFile << "can't print client " + pId + " because doesn't exist" << endl;
        return;
    }
    clients[pId]->PrintClient();
    LogFile << endl;
}

void Company::printEmployees()
{
    LogFile << "--Company Employees:--" << endl;
    for (map<string, SmartPtr<Employee>>::iterator it = employees.begin(); it != employees.end(); it++)
    {
        Programmer *temp = dynamic_cast<Programmer*>(it->second.GetPtr());
        if (temp != NULL){
            temp->printProgrammer();
            LogFile << endl;
            continue;
        }
        Artist *temp1 = dynamic_cast<Artist*>(it->second.GetPtr());
        if (temp1 != NULL) {
            temp1->printArtist();
            LogFile << endl;
            continue;
        }
        Manager *temp2 = dynamic_cast<Manager*>(it->second.GetPtr());
        if (temp2 != NULL) {
            temp2->Printmanger();
            LogFile << endl;
        }
    }
}

void Company::addEmployeeToProject(string empId, string projId, string position)
{
    if (!checkIfEmployeeExist(empId))
    {
        LogFile << "can't add employee " + empId + " because doesn't exist" << endl;
        return;
    }
    if (!checkIfProjectExist(projId))
    {
        LogFile << "can't add employee " + empId + ", project " + projId + " doesn't exist" << endl;
        employees[empId]->setProjectId(projId);
        return;
    }
    if (checkifCycleExist(projId))
    {
        cycles[projId]->addEmployee(employees[empId]);
        employees[empId]->setProjectId(projId);
        return;
    }
    employees[empId]->setProjectId(projId);
}

void Company::removeEmpFromProject(string empId, string projId)
{
    if (!checkIfEmployeeExist(empId))
    {
        LogFile << "can't remove empoyee " + empId + " from project " + projId + " because doesn't exist" << endl;
        return;
    }
    if (!checkIfProjectExist(projId))
    {
        LogFile << "can't remove employee " + empId + " from project " + projId + "because project deosn't exist" << endl;
        return;
    }
    if (employees.at(empId)->getCurrentProjectId() != projId)
    {
        LogFile << "cant't remove employee " + empId + " from project " + projId + " because doesn't belongs to the project" << endl;
        return;
    }
    cycles.at(projId)->removeEmployee(empId);
}

void Company::printProject(string projId)
{
    if (projects.count(projId) == 1)
    {
        projects[projId]->print();
        LogFile << endl;
        return;
    }
    else LogFile << "can't print project " + projId + " because doesn't exist" << endl;
}

void Company::stopCycle(string projId)
{
    if (checkifCycleExist(projId))
    {
        cycles[projId]->setStop(true);
        LogFile << "project " + projId + " stopped" << endl;
        return;
    }
    else LogFile << "project " + projId + " wasn't running already" << endl;
}
