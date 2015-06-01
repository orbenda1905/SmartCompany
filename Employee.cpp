/*
 * Employee.cpp
 *
 *  Created on: May 23, 2015
 *      Author: Benda
 */

#include "Employee.h"

Employee::Employee() : Person()
{
    
}

Employee::Employee(const string Name, const string pId, const string phNum, string compId, int THrs, string currProj, int currProjHrs, int exp, int hrsPDay, bool employ) : Person(Name, pId, phNum)
{
	companyId = compId;
	currentProjectId = currProj;
    neededProjectHours = currProjHrs;
	totalHours = THrs;
	experience = exp;
	isEmployed = employ;
	hoursPerDay = hrsPDay;
}


string Employee::getCompanyId() const {
	return companyId;
}

const string& Employee::getCurrentProjectId() const {
	return currentProjectId;
}

void Employee::setProjectId(string& projId){
    currentProjectId = projId;
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

int Employee::getSoFarProjHours() const {
	return soFarProjHours;
}

void Employee::setSoFarProjHours(int soFarProjHours) {
	this->soFarProjHours = soFarProjHours;
}

int Employee::getNeededProjectHours() const{
    return neededProjectHours;
}

const string& Employee::getId() const
{
    return Person::getId();
}

void Employee::setNeededProjectHours(int num)
{
    neededProjectHours = num;
}

void Employee::eraseProjId()
{
    currentProjectId = "";
}

bool Employee::getIsEmployed()
{
    return isEmployed;
}
