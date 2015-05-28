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
    if (checkIfEmployeeExist(newWorker->getId()))
    {
        cout << "employee already exist" << endl;
        delete newWorker;
        return;
    }
    else
    {
        employees.emplace(newWorker, newWorker->getId());
    }
    return;
}

void Company::speedUp()
{

    for (map<string, SmartPtr<ProjectCycle>>::iterator it = cycles.begin(); it != cycles.end(); ++it)
    {
        it->second->speedUp();
    }
}

void Company::addProjCycle(string& projId, string& date){
    if (checkifCycleExist(projId)){
        cout << "project cycle already exist" << endl;
        return;
    }
    if (projects.count(projId) == 1)
    {
        SmartPtr<ProjectCycle> cycle = new ProjectCycle(projects.at(projId), date);
        cycles.emplace(projId, cycle);
    }
}

void Company::addProject(SmartPtr<Project>& newProject)
{
    if (checkIfProjectExist(newProject->getProjId()))
    {
        cout << "Project already exist" << endl;
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
    if (checkIfClientExist(newClient->getId()))
    {
        cout << "Client already exist" << endl;
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

}
void Company::ForceQuit(string ProjectName){
    
    if (cycles.count(ProjectName)==1) {
        
    }
}
/*
void Company::startArrange(){
    //for loop on all the employees and spread them to their projects if needed
    //and then do this:
    //string *temp = newWorker->getCurrentProjectId();
    //if (projects.count(*temp) == 0)
    //{
    //  cout << "employee's project not exist" << endl;
    //  temp = NULL;
    //}
    //else if (projects.count(*temp) == 1)
    //{
    //  projects.at(*temp)->addEmployee(newWorker);
    //}
}*/

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
    if (cycles.count(projId) == 0) return false;
    return true;
}

void Company::PrintCompany(){
    
}


