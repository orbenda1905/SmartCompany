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



void Project::speedUp(){
    for (map<string, SmartPtr<Employee>>::iterator it = programmers.begin(); it != programmers.end(); it++)
    {
        int hrs = (it->second->getSoFarProjHours());
        int totalProj = it->second->getNeededProjectHours();
        int daily = it->second->getHoursPerDay();
        int totalHrs = it->second->getTotalHours();
        if ((hrs + (daily*10)) <= totalProj)
        {
            it->second->setSoFarProjHours(hrs + (daily*10));
            it->second->setTotalHours(totalHrs + (daily*10));
            hoursLeft -= daily*10;
        }
        else
        {
            hoursLeft -= totalProj - hrs;
            it->second->setSoFarProjHours(totalProj);
            it->second->setTotalHours(totalHrs + totalProj - hrs);
        }
    }
    if (hoursLeft <= 0)//project has finished its hours
    {
        needToRemove = true;
        return;
    }
    checkFinish();
}



bool Project::addProgrammer(SmartPtr<Employee> &emp)
{
    string temp;
    if (programmers.size() < programmersNumber)
    {//if there is a place
        if (checkExistProg(emp))
        {
            temp = "programmer " + emp->getId() + " already exist in this project\n";
            LogFile << temp;
            cout << temp;
            return false;
        }
        if (checkIfNeedingProg(emp))
        {
            programmers.emplace(emp->getId(), emp);
            return true;
        }
    }
    temp = "programmer " + emp->getId() + " isn't needed for this project, this project is already fully occupied\n";
    LogFile << temp;
    cout << temp;
    return false;
}

bool Project::addArtist(SmartPtr<Employee> &emp)
{
    string temp;
    if (artists.size() < artistsNumber)
    {//if there is a place
        if (checkExistArtist(emp))
        {
            temp = "artist " + emp->getId() + " already exist in this project\n";
            LogFile << temp;
            cout << temp;
            return false;
        }
        if (checkIfNeedingArt(emp))
        {
            artists.emplace(emp->getId(), emp);
            temp = "artist " + emp->getId() + "has joid the project\n";
            LogFile << temp;
            cout << temp;
            return true;
        }
    }
    temp = "artist " + emp->getId() + " isn't needed for this project, this project is already fully occupied\n";
    LogFile << temp;
    cout << temp;
    return false;
}

bool Project::checkExistProg(SmartPtr<Employee> &emp)
{
    for (map<string, SmartPtr<Employee>>::iterator it = programmers.begin(); it != programmers.end(); it++)
    {
        if (emp->getId() == it->second->getId()) return true;
    }
    return false;
}

bool Project::checkExistArtist(SmartPtr<Employee> &emp)
{
    for (map<string, SmartPtr<Employee>>::iterator it = artists.begin(); it != artists.end(); it ++)
    {
        if (emp->getId() == it->second->getId()) return true;
    }
    return false;
}

bool Project::checkIfNeedingProg(SmartPtr<Employee> &emp)
{
    vector<string> vec = ((SmartPtr<Programmer>&)emp)->getFields();
    for (vector<string>::iterator it1 = progWorkField.begin(); it1 != progWorkField.end(); it1++)
    {//checking if the field is match
        for (vector<string>::iterator it2 = vec.begin(); it2 != vec.end(); it2++)
        {
            if (it2 == it1) return true;
        }
    }
    vec = ((SmartPtr<Programmer>&)emp)->getKnowedLangs();
    for (vector<string>::iterator it1 = vec.begin(); it1 != vec.end(); it1++)
    {//checking if the program languages matches
        for (vector<string>::iterator it2 = progLangs.begin(); it2 != progLangs.end(); it2++)
        {
            if (it2 == it1) return true;
        }
    }
    return false;
}

bool Project::checkIfNeedingArt(SmartPtr<Employee> &emp)
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

void Project::beginTheProject()
{
    int prog = programmers.size();
    int art = artists.size();
    int split = totalHours / (prog + art);
    for (map<string, SmartPtr<Employee>>::iterator it = programmers.begin(); it != programmers.end(); it++)
    {
        it->second->setNeededProjectHours(split);
    }
    for (map<string, SmartPtr<Employee>>::iterator it = artists.begin(); it != artists.end(); it++)
    {
        it->second->setNeededProjectHours(split);
    }
    hoursLeft = totalHours;
}

void Project::dismissEmployee(SmartPtr<Employee> &emp)
{
    emp->setIsEmployed(false);
    emp->eraseProjId();
    emp->setNeededProjectHours(0);
    emp->setSoFarProjHours(0);
}

bool Project::getNeedToRemove()
{
    return needToRemove;
}

Project::~Project()
{
    for (map<string, SmartPtr<Employee>>::iterator it = programmers.begin(); it != programmers.end(); it++)
    {
        dismissEmployee(it->second);
        
    }
    for (map<string, SmartPtr<Employee>>::iterator it = artists.begin(); it != artists.end(); it++)
    {
        dismissEmployee(it->second);
    }
    programmers.clear();
    artists.clear();
    progWorkField.clear();
    artWorkField.clear();
    progLangs.clear();
    finishedWorkers.clear();
    client->setProjFinished(true);
    delete client;
    delete manager;
}

void Project::checkFinish()
{
    for (map<string, SmartPtr<Employee>>::iterator it = programmers.begin(); it != programmers.end(); it++)
    {
        if (it->second->getSoFarProjHours() == it->second->getNeededProjectHours())
        {
            finishedWorkers.emplace(it->second->getId(), it->second);
            programmers.erase(it->second->getId());
        }
    }
    for (map<string, SmartPtr<Employee>>::iterator it = artists.begin(); it != artists.end(); it++)
    {
        if (it->second->getSoFarProjHours() == it->second->getNeededProjectHours())
        {
            finishedWorkers.emplace(it->second->getId(), it->second);
            programmers.erase(it->second->getId());
        }
    }
}

bool Project::getManagerOccupied()
{
    return managerOccupied;
}


