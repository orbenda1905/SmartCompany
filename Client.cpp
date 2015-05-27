/*
 * Client.cpp
 *
 *  Created on: May 23, 2015
 *      Author: Benda
 */

#include "Client.h"

Client::Client(const string id, const string& Name, const long phNum, int tProjects, string curProjId) : Person(id, Name, phNum)
{
	
	totalProjcets = tProjects;
	currentProjectId = curProjId;

}

Client::~Client() {
	// TODO Auto-generated destructor stub
}

//gever this is working