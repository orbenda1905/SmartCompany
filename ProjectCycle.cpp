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
        project->addManager(emp);
        return;
    }
    if (project->checkEmployee(emp))
    {
        currentProjEmployees.emplace(emp->getId(), emp);
    }
    else
    {
        LogFile << "the employee, id: " << emp->getId() << "is not suitable for this peoject" << endl;
        emp->setProjectId(*(new string(NULL)));
    }
    
}


void ProjectCycle::speedUp(){
    //for loop on the project map and call eah project's "speedUp() method
}
