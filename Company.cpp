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


void Company::addEmployee(SmartPtr<Employee>& worker)
{
    
}

void Company::speedUp()
{

    for (map<SmartPtr<ProjectCycle>, string>::iterator it = projects.begin(); it != projects.end(); ++it)
    {
//        it->first->speedUp();
    }
}

void Company::addProjCicle(string& projId, string& date){
    if (projects.count(projId) == 1)
    {
        SmartPtr<ProjectCycle> cycle = new ProjectCycle(projects.at(projId), date);
        cycles.emplace(cycles, projId);
    }
}

void Company::addProject(SmartPtr<Project>& newProject)
{
    if (projects.count(newProject->getProjId()) == 1)
    {
        cout << "Project already exist" << endl;
        delete newProject;
        return;
    }
    else if (projects.count(newProject->getProjId()) == 0)
    {
        projects.emplace(newProject, newProject->getProjId());
    }
    return;
}

void Company::addClient(SmartPtr<Client>& newClient)
{
    if (clients.count(newClient->getId()) == 0)
    {
        cout << "Client already exist" << endl;
        delete newClient;
        return;
    }
    else if (clients.count(newClient->getId()) == 1)
    {
        clients.emplace(newClient, newClient->getId());
    }
    return;
}

Company::~Company() {

}


