/*
 * ProjectCycle.cpp
 *
 *  Created on: May 24, 2015
 *      Author: Benda
 */

#include "ProjectCycle.h"



ProjectCycle::ProjectCycle(SmartPtr<Project> project, string& date) : WriteToFile(), project(project), date(date) {
    
}


ProjectCycle::~ProjectCycle() {
	// TODO Auto-generated destructor stub
}

void ProjectCycle::addEmployee(SmartPtr<Employee>& emp){
    Manager *temp = dynamic_cast<Manager*>(&emp);
    if (temp != NULL)
    {
        if (!project->getManagerOccupied())
        {
            project->setManager(emp);
            return;
        }
        return;
        
    }
    Programmer *temp1 = dynamic_cast<Programmer*>(&emp);
    if (temp1 != NULL)
    {
        if (project->addProgrammer(emp))
        {
            currentProjEmployees.emplace(emp->getId(), emp);
            return;
        }
    }
    else if (temp1 == NULL)
    {
        if (project->addArtist(emp))
        {
            currentProjEmployees.emplace(emp->getId(), emp);
        }
    }
//    }
//    else if (project->checkEmployee(emp))
//    {
//        currentProjEmployees.emplace(emp->getId(), emp);
//    }
//    else
//    {
//        LogFile << "the employee, id: " << emp->getId() << "is not suitable for this peoject" << endl;
//        emp->setProjectId(*(new string(NULL)));
//    }
    
}

void ProjectCycle::start()
{
    
}


void ProjectCycle::speedUp(){
    project->speedUp();
    if (project->getNeedToRemove())
    {
        delete project;
        currentProjEmployees.clear();
    }

}

void ProjectCycle::checkFinishedEmployee()
{
    for (map<string, SmartPtr<Employee>>::iterator it = currentProjEmployees.begin(); it != currentProjEmployees.end(); it++)
    {
        if (it->second->getIsEmployed())
            currentProjEmployees.erase(it->second->getId());
    }
}
