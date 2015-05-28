/*
 * Client.cpp
 *
 *  Created on: May 23, 2015
 *      Author: Benda
 */

#include "Client.h"

Client::Client(const string id, const string& Name, const long phNum,
               int tProjects, string curProjId) : Person(id, Name, phNum)
{
	
	totalProjcets = tProjects;
	currentProjectId = curProjId;

}

Client::~Client() {
	// TODO Auto-generated destructor stub
}

void Client::PrintClient(){
    
    cout<<"client total projects:"<<totalProjcets<<endl;
    cout<<"The client current project"<<currentProjectId<<endl;
    
    LogFile<<"client total projects:"<<totalProjcets<<endl;
    LogFile<<"The client current project"<<currentProjectId<<endl;
    
}