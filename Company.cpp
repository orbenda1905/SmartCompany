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
    if (CheckIfEmployeeExist(newWorker->getId()))
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

    for (map<SmartPtr<ProjectCycle>, string>::iterator it = projects.begin(); it != projects.end(); ++it)
    {
        it->first->speedUp();
    }
}

void Company::addProjCicle(string& projId, string& date){
    if (checkifCycleExist(projId)){
        cout << "project cycle already exist" << endl;
        return;
    }
    if (projects.count(projId) == 1)
    {
        SmartPtr<ProjectCycle> cycle = new ProjectCycle(projects.count(projId), date);
        cycles.a
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
        projects.emplace(newProject, newProject->getProjId());
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
        clients.emplace(newClient, newClient->getId());
    }
    return;
}

Company::~Company() {

}
void Company::ForceQuit(string ProjectName){
    
    if (cycles.count(ProjectName)==1) {
        cycles.count(ProjectName)->remove()
    }
    
    
    
}

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
}

bool Company::checkIfProjectExist(string& projId){
    if (projects.count(projId) == 0) return false;
    if (projects.count(projId) == 1) return true;
}

bool Company::checkIfClientExist(string& clientId){
    if (clients.count(clientId) == 0) return false;
    if (clients.count(clientId) == 1) return true;
}

bool Company::CheckIfEmployeeExist(string& empId){
    if (employees.count(empId) == 0) return false;
    if (employees.count(empId) == 1) return true;
}

bool Company::checkIfCycleExist(string& projId){
    if (cycles.count(projId) == 0) return false;
    if (cycles.count(projId) == 1) return true;
}




