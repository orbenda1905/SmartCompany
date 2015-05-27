/*
 * Employee.cpp
 *
 *  Created on: May 23, 2015
 *      Author: Benda
 */

#include "Employee.h"

Employee::Employee(const string id, const string& Name, const long phNum, string compId, SmartPtr<Project>& currProj, int TProjH, int THrs, int exp, bool employ, int hrsPDay) : Person(id, Name, phNum)
{
	companyId = compId;
	currentProject = currProj;
	totalProjHours = TProjH;
	totalHours = THrs;
	experience = exp;
	isEmployed = employ;
	hoursPerDay = hrsPDay;
}


string Employee::getCompanyId() const {
	return companyId;
}

const SmartPtr<Project>& Employee::getCurrentProject() const {
	return currentProject;
}

int Employee::getExperience() const {
	return experience;
}

void Employee::setExperience(int experience) {
	this->experience = experience;
}

int Employee::getHoursPerDay() const {
	return hoursPerDay;
}

void Employee::setHoursPerDay(int hoursPerDay) {
	this->hoursPerDay = hoursPerDay;
}

bool Employee::isIsEmployed() const {
	return isEmployed;
}

void Employee::setIsEmployed(bool isEmployed) {
	this->isEmployed = isEmployed;
}

int Employee::getTotalHours() const {
	return totalHours;
}

void Employee::setTotalHours(int totalHours) {
	this->totalHours = totalHours;
}

int Employee::getTotalProjHours() const {
	return totalProjHours;
}

void Employee::setTotalProjHours(int totalProjHours) {
	this->totalProjHours = totalProjHours;
}

void Employee::speedUp(){
    
}

