/*
 * Project.cpp
 *
 *  Created on: May 23, 2015
 *      Author: Benda
 */

#include "Project.h"


Project::Project(string name, string id, int ttlHrs, int hrsLft, int progCnt, int artCnt, vector<string>& pFld,vector<string>& aFld)
{
	projectName = name;
	projId = id;
	totalHours = ttlHrs;
	hoursLeft = hrsLft;
	programmersNumber = progCnt;
	artistsNumber = artCnt;
	progWorkField = pFld;
	artWorkField = aFld;
	this->client = client;

}

int Project::getArtistsNumber() const {
	return artistsNumber;
}

void Project::setArtistsNumber(int artistsNumber) {
	this->artistsNumber = artistsNumber;
}

const vector<string>& Project::getArtWorkField() const {
	return artWorkField;
}

void Project::setArtWorkField(vector<string>& artWorkField) {
	this->artWorkField = artWorkField;
}

const SmartPtr<Client>& Project::getClient() const {
	return client;
}

void Project::setClient(const SmartPtr<Client>& client) {
	this->client = client;
}

const map<string, SmartPtr<Employee>>& Project::getCurWorkers() const {
	return curWorkers;
}

void Project::setCurWorkers(map<string, SmartPtr<Employee>>& curWorkers) {
	this->curWorkers = curWorkers;
}

const map<string, SmartPtr<Employee>>& Project::getFinishedWorkers() const {
	return finishedWorkers;
}

void Project::setFinishedWorkers(
		const map<string, SmartPtr<Employee>>& finishedWorkers) {
	this->finishedWorkers = finishedWorkers;
}

int Project::getHoursLeft() const {
	return hoursLeft;
}

void Project::setHoursLeft(int hoursLeft) {
	this->hoursLeft = hoursLeft;
}

SmartPtr<Employee>& Project::getManager() {
	return manager;
}

void Project::setManager(SmartPtr<Employee> manager) {
	this->manager = manager;
}

int Project::getProgrammersNumber() const {
	return programmersNumber;
}

void Project::setProgrammersNumber(int programmersNumber) {
	this->programmersNumber = programmersNumber;
}

const vector<string>& Project::getProgWorkField() const {
	return progWorkField;
}

void Project::setProgWorkField(vector<string>& progWorkField) {
	this->progWorkField = progWorkField;
}

const string& Project::getProjectName() const {
	return projectName;
}

void Project::setProjectName(const string& projectName) {
	this->projectName = projectName;
}

const string& Project::getProjId() const {
	return projId;
}

int Project::getTotalHours() const {
	return totalHours;
}

void Project::setTotalHours(int totalHours) {
	this->totalHours = totalHours;
}

void Project::checkFinish(){
    
}

void Project::speedUp(){
    
}

bool Project::checkIfNeeding(SmartPtr<Employee> &emp){
    Programmer *prog = dynamic_cast<Programmer*>(&emp);
    if (prog == NULL)
    {
        vector<string> vec = ((SmartPtr<Artist>&)emp)->getFields();
        for (vector<string>::iterator it1 = artWorkField.begin(); it1 != artWorkField.end(); it1++)
        {
            for (vector<string>::iterator it2 = vec.begin(); it2 != vec.end(); ++it2)
            {
                if (it2 == it1) return true;
            }
        }
        return false;
    }
    else
    {
        
    }
}

    return false;
}

bool Project::checkEmployee(SmartPtr<Employee> &emp){
    if (checkExist(emp)){
            return false;
}














