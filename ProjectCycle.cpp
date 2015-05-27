/*
 * ProjectCycle.cpp
 *
 *  Created on: May 24, 2015
 *      Author: Benda
 */

#include "ProjectCycle.h"



ProjectCycle::ProjectCycle(SmartPtr<Project>& project, string& date) : project(project) {
    this->date = date;
}


ProjectCycle::~ProjectCycle() {
	// TODO Auto-generated destructor stub
}


void ProjectCycle::speedUp(){
    
}
