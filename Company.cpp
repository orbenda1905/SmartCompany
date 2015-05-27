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
        SmartPtr<ProjectCycle> cycle = new ProjectCycle(projects.count(projId), date);
        cycles.a
    }
}


Company::~Company() {

}
void Company::ForceQuit(string ProjectName){
    
    if (cycles.count(ProjectName)==1) {
        cycles.count(ProjectName)->remove()
    }
    
    
    
}


