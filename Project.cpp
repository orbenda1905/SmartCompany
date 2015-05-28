/*
 * Project.cpp
 *
 *  Created on: May 23, 2015
 *      Author: Benda
 */

#include "Project.h"

Project::Project(string name, string id, int ttlHrs, int hrsLft,
    SmartPtr<Manager>& mngr, int progCnt, int artCnt, vector<string>& pFld,vector<string>& aFld, map<SmartPtr<Employee>, string>& curList, map<SmartPtr<Employee>, string>& doneList, SmartPtr<Client>& client){
	projectName = name;
	projId = id;
	totalHours = ttlHrs;
	hoursLeft = hrsLft;
	manager = mngr;
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

const map<SmartPtr<Employee>, string>& Project::getCurWorkers() const {
	return curWorkers;
}

void Project::setCurWorkers(map<SmartPtr<Employee>, string>& curWorkers) {
	this->curWorkers = curWorkers;
}

const map<SmartPtr<Employee>, string>& Project::getFinishedWorkers() const {
	return finishedWorkers;
}

void Project::setFinishedWorkers(
		const map<SmartPtr<Employee>, string>& finishedWorkers) {
	this->finishedWorkers = finishedWorkers;
}

int Project::getHoursLeft() const {
	return hoursLeft;
}

void Project::setHoursLeft(int hoursLeft) {
	this->hoursLeft = hoursLeft;
}

const SmartPtr<Manager>& Project::getManager() const {
	return manager;
}

void Project::setManager(const SmartPtr<Manager>& manager) {
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
        
    }
}











