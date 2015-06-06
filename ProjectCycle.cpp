/*
 * ProjectCycle.cpp
 *
 *  Created on: May 24, 2015
 *      Author: Benda
 */

#include "ProjectCycle.h"



ProjectCycle::ProjectCycle(SmartPtr<Project>& project, string& date) : WriteToFile(), project(project), date(date) {
    
}


ProjectCycle::~ProjectCycle() {
    currentProjEmployees.clear();
    LogFile << "cycle of project " + project->getProjId() + " deleted" << endl;
}

void ProjectCycle::setStop(bool status)
{
    stop = status;;
}

void ProjectCycle::addEmployee(SmartPtr<Employee> emp){
    string line;
    Manager *temp = dynamic_cast<Manager*>(emp.GetPtr());
    if (temp != NULL)
    {
        if (!project->getManagerOccupied())
        {
            if (project->getManagerId() == "")
            {
                project->setManager(emp);
                project->setManagerOccupied(true);
                line = "manager " + emp->getCompanyId() + " added to project " + emp->getCurrentProjectId();
                cout << line << endl;
                LogFile << line << endl;
                return;
            }
            else if (project->getManagerId() == emp->getCompanyId())
            {
                project->setManager(emp);
                return;
            }
        }
        line = "the manager " + emp->getCompanyId() + " wasn't needed for project " + emp->getCurrentProjectId();
        cout << line << endl;
        LogFile << line << endl;
        return;
        
    }
    Programmer *temp1 = dynamic_cast<Programmer*>(emp.GetPtr());
    if (temp1 != NULL)
    {
        if (project->addProgrammer(emp))
        {
            currentProjEmployees.emplace(emp->getCompanyId(), emp);
            return;
        }
        line = "programmer " + emp->getCompanyId() + "wasn't needed for project " + emp->getCurrentProjectId();
        cout << line << endl;
        LogFile << line << endl;
    }
    else if (temp1 == NULL)
    {
        if (project->addArtist(emp))
        {
            currentProjEmployees.emplace(emp->getCompanyId(), emp);
            return;
        }
        line = "artist " + emp->getCompanyId() + " wasn't needed for peoject " + emp->getCurrentProjectId();
        cout << line << endl;
        LogFile << line << endl;
    }
}

void ProjectCycle::speedUp(){
    string line;
    if (!project->getManagerOccupied())
    {
        line = "project " + project->getProjId() + "can't run beacause there is no manager";
        cout << line << endl;
        LogFile << line << endl;
        return;
    }
    else if (stop)
    {
        line = "project " + project->getProjId() + " can't run because he stoped";
        cout << line << endl;
        LogFile << line << endl;
        return;
    }
    project->speedUp();
    checkFinishedEmployee();
}

void ProjectCycle::checkFinishedEmployee()
{
    int flag = 0;
    string employeeCompanyId;
    for (map<string, SmartPtr<Employee>>::iterator it = currentProjEmployees.begin(); it != currentProjEmployees.end(); it++)
    {
        if (flag == 1)
        {
            currentProjEmployees.erase(employeeCompanyId);
            flag = 0;
        }
        if (!it->second->getIsEmployed()){
            flag = 1;
            employeeCompanyId = it->first;
        }
    }
    if (flag == 1)
    {
        currentProjEmployees.erase(employeeCompanyId);
    }
}

SmartPtr<Project>& ProjectCycle::getProject()
{
    return project;
}

void ProjectCycle::removeEmployee(string empId)
{
    if (project->removeEmployee(empId))
    {
        currentProjEmployees.erase(empId);
    }
}



