/*
 * ProjectCycle.cpp
 *
 *  Created on: May 24, 2015
 *      Author: Benda
 */

#include "ProjectCycle.h"



ProjectCycle::ProjectCycle(SmartPtr<Project>& project, string& date) : project(project), date(date) {
    
}


ProjectCycle::~ProjectCycle() {
	// TODO Auto-generated destructor stub
}


void ProjectCycle::speedUp(){
    //for loop on the project map and call eah project's "speedUp() method
}
