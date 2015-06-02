/*
 * Client.cpp
 *
 *  Created on: May 23, 2015
 *      Author: Benda
 */

#include "Client.h"

Client::Client(const string Name, const string pId, const string phNum, int tProjects, string curProjId) : Person(Name, pId, phNum)
{
	
	totalProjects = tProjects;
	currentProjectId = curProjId;

}

Client::~Client() {
	// TODO Auto-generated destructor stub
}

void Client::PrintClient(){
    PrintPerson();
    
    cout<<"\nclient total projects:"<<totalProjects<<endl;
    cout<<"The client current project"<<currentProjectId<<endl;
    
    LogFile<<"\nclient total projects:"<<totalProjects<<endl;
    LogFile<<"The client current project"<<currentProjectId<<endl;
}

bool Client::getProjFinished()
{
    return projFinished;
}

void Client::setProjFinished(bool status)
{
    projFinished = true;
}