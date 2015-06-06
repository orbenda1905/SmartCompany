/*
 * Client.cpp
 *
 *  Created on: May 23, 2015
 *      Author: Benda
 */

#include "Client.h"

Client::Client(const string Name, const string pId, const string phNum,string curProjId, int tProjects) : Person(Name, pId, phNum)
{
	
	totalProjects = tProjects;
	currentProjectId = curProjId;

}

Client::~Client() {
    LogFile << "client " + getId() + " destroyed" << endl;
}

void Client::PrintClient(){
    PrintPerson();
    
    cout<<"client total projects: "<<totalProjects<<endl;
    cout<<"The client current project "<<currentProjectId<<endl;
    
    LogFile<<"client total projects: "<<totalProjects<<endl;
    LogFile<<"The client current project "<<currentProjectId<<endl;
}

bool Client::getProjFinished()
{
    return projFinished;
}

string& Client::getProjectId()
{
    return currentProjectId;
}

void Client::setProjFinished(bool status)
{
    projFinished = status;
}

void Client::incTotalProjects()
{
    totalProjects++;
}