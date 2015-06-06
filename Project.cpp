/*
 * Project.cpp
 *
 *  Created on: May 23, 2015
 *      Author: Benda
 */

#include "Project.h"


Project::Project(string name, string prId, int ttlHrs, int hrsLft, string mangr, int progCnt, int artCnt, vector<string> pFld,vector<string> aFld)
{
	projectName = name;
	projId = prId;
	totalHours = ttlHrs;
	hoursLeft = hrsLft;
    if (mangr != "NULL")
    {
        managerId = mangr;
    }
	programmersNumber = progCnt;
	artistsNumber = artCnt;
	progWorkField = pFld;
	artWorkField = aFld;
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

void Project::setArtWorkField(vector<string> artWorkField) {
	this->artWorkField = artWorkField;
}

const SmartPtr<Client>& Project::getClient() const {
	return client;
}

void Project::setClient(const SmartPtr<Client> client) {
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
    managerId = manager->getCompanyId();
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

void Project::setProgWorkField(vector<string> progWorkField) {
	this->progWorkField = progWorkField;
}

const string& Project::getProjectName() const {
	return projectName;
}

void Project::setProjectName(const string projectName) {
	this->projectName = projectName;
}

string& Project::getProjId(){
	return projId;
}

int Project::getTotalHours() const {
	return totalHours;
}

void Project::setTotalHours(int totalHours) {
	this->totalHours = totalHours;
}



void Project::speedUp(){
    string line = "project " + projId + " speeded up";
    for (map<string, SmartPtr<Employee>>::iterator it = programmers.begin(); it != programmers.end(); it++)
    {
        boost10Days(it->second);
    }
    if (hoursLeft <= 0)//project has finished its hours
    {
        needToRemove = true;
        checkFinish();
        LogFile << line << endl;
        cout << line << endl;
        return;
    }
    for (map<string, SmartPtr<Employee>>::iterator it = artists.begin(); it != artists.end(); it++)
    {
        boost10Days(it->second);
        LogFile << line << endl;
        cout << line << endl;
    }
    if (hoursLeft <= 0)
    {
        needToRemove = true;
    }
    checkFinish();
}

void Project::boost10Days(SmartPtr<Employee>& emp)
{
    int hrs = (emp->getSoFarProjHours());
    int totalProj = emp->getNeededProjectHours();
    int daily = emp->getHoursPerDay();
    int totalHrs = emp->getTotalHours();
    if ((hrs + (daily*10)) <= totalProj)
    {
        emp->setSoFarProjHours(hrs + (daily*10));
        emp->setTotalHours(totalHrs + (daily*10));
        hoursLeft -= daily*10;
    }
    else
    {
        hoursLeft -= totalProj - hrs;
        emp->setSoFarProjHours(totalProj);
        emp->setTotalHours(totalHrs + totalProj - hrs);
    }
}

bool Project::addProgrammer(SmartPtr<Employee>& emp)
{
    string line;
    if (programmers.size() < programmersNumber)
    {//if there is a place
        if (checkExistProg(emp))
        {
            line = "programmer " + emp->getCompanyId() + " already exist in this project";
            LogFile << line << endl;
            cout << line << endl;
            return false;
        }
        if (checkIfNeedingProg(emp))
        {
            programmers.emplace(emp->getCompanyId(), emp);
            line = "programmer " + emp->getCompanyId() + " has joid project " + emp->getCurrentProjectId();
            cout << line << endl;
            LogFile << line << endl;
            return true;
        }
    }
    line = "programmer " + emp->getCompanyId() + " isn't needed for project " + emp->getCurrentProjectId() + ", this project is fully occupied";
    LogFile << line << endl;
    cout << line << endl;;
    return false;
}

bool Project::addArtist(SmartPtr<Employee>& emp)
{
    string line;
    if (artists.size() < artistsNumber)
    {//if there is a place
        if (checkExistArtist(emp))
        {
            line = "artist " + emp->getCompanyId() + " already exist in project " + emp->getCurrentProjectId();
            LogFile << line << endl;
            cout << line << endl;
            return false;
        }
        if (checkIfNeedingArt(emp))
        {
            artists.emplace(emp->getCompanyId(), emp);
            line = "artist " + emp->getCompanyId() + " has joid project " + emp->getCurrentProjectId();
            LogFile << line << endl;
            cout << line << endl;
            return true;
        }
    }
    line = "artist " + emp->getCompanyId() + " isn't needed for project " + emp->getCurrentProjectId() + ", this project is fully occupied";
    LogFile << line << endl;
    cout << line << endl;
    return false;
}

bool Project::checkExistProg(SmartPtr<Employee>& emp)
{
    if (programmers.count(emp->getCompanyId()) == 1) return true;
    else return false;
}

bool Project::checkExistArtist(SmartPtr<Employee>& emp)
{
    if (artists.count(emp->getCompanyId()) == 1) return true;
    else return false;
}

bool Project::checkIfNeedingProg(SmartPtr<Employee>& emp)
{
    Programmer *prog = dynamic_cast<Programmer*>(emp.GetPtr());
    vector<string> vec = prog->getFields();
    for (int i = 0; i < progWorkField.size(); i++)
    {//checking if the field is match
        for (int j = 0; j < vec.size(); j++)
        {
            if (progWorkField[i] == vec[j]) return true;
        }
    }
    vec.clear();
    vec = prog->getKnowedLangs();
    for (int i = 0; i < progLangs.size(); i++)
    {//checking if the program languages matches
        for (int j = 0; j < vec.size(); j++)
        {
            if (progLangs[i] == vec[j]) return true;
        }
    }
    return false;
}

bool Project::checkIfNeedingArt(SmartPtr<Employee>& emp)
{
    Artist *art = dynamic_cast<Artist*>(emp.GetPtr());
    vector<string> vec = art->getFields();
    for (int i = 0; i < artWorkField.size(); i++)
    {
        for (int j = 0; j < vec.size(); j++)
        {
            if (artWorkField[i] == vec[j]) return true;
        }
    }
    return false;
}

void Project::beginTheProject()
{
    string line;
    long prog = programmers.size();
    long art = artists.size();
    if (prog + art == 0)
    {
        line = "no employee int project " + projectName;
        cout << line << endl;
        LogFile << line << endl;
        return;
    }
    long split = totalHours / (prog + art);
    for (map<string, SmartPtr<Employee>>::iterator it = programmers.begin(); it != programmers.end(); it++)
    {
        it->second->setNeededProjectHours((int)split);
    }
    for (map<string, SmartPtr<Employee>>::iterator it = artists.begin(); it != artists.end(); it++)
    {
        it->second->setNeededProjectHours((int)split);
    }
    hoursLeft = totalHours;
    line = "project " + projId + " has began";
    cout << line << endl;
    LogFile << line << endl;
}

void Project::dismissEmployee(SmartPtr<Employee>& emp)
{
//    string temp = "emplyee " + emp->getCompanyId() + "finished his part of project " + emp->getCurrentProjectId();
//    cout << temp << endl;
//    LogFile << temp << endl;
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
    if (manager.GetPtr() != NULL){
        dismissEmployee(manager);
    }
    programmers.clear();
    artists.clear();
    progWorkField.clear();
    artWorkField.clear();
    progLangs.clear();
    finishedWorkers.clear();
    if (client.GetPtr() != NULL)
    {
        client->setProjFinished(true);
        client->incTotalProjects();
    }
    string temp = "project " + projId + " destroyed";
    cout << temp << endl;
    LogFile << temp << endl;
}


void Project::checkFinish()
{
    int flag = 0;
    string employeeCompanyId;
    for (map<string, SmartPtr<Employee>>::iterator it = programmers.begin(); it != programmers.end(); it++)
    {
        if (flag == 1)
        {
            programmers.erase(employeeCompanyId);
            flag = 0;
        }
        if (it->second->getSoFarProjHours() == it->second->getNeededProjectHours())
        {
            flag = 1;
            employeeCompanyId = it->first;
            finishedWorkers.emplace(it->second->getCompanyId(), it->second);
            dismissEmployee(it->second);
        }
    }
    if (flag == 1){
        programmers.erase(employeeCompanyId);
        flag = 0;
    }
    for (map<string, SmartPtr<Employee>>::iterator it = artists.begin(); it != artists.end(); it++)
    {
        if (flag == 1)
        {
            artists.erase(employeeCompanyId);
            flag = 0;
        }
        if (it->second->getSoFarProjHours() == it->second->getNeededProjectHours())
        {
            flag = 1;
            employeeCompanyId = it->first;
            finishedWorkers.emplace(it->second->getCompanyId(), it->second);
            dismissEmployee(it->second);
        }
    }
    if (flag == 1)
    {
        artists.erase(employeeCompanyId);
    }
}

bool Project::getManagerOccupied()
{
    return managerOccupied;
}

void Project::setManagerOccupied(bool status)
{
    managerOccupied = status;
}

string Project::getManagerId()
{
    return managerId;
}


void Project::print()
{
    LogFile << "-----project " + projectName + "--------" << endl;
    LogFile << "id: " + projId << endl;
    LogFile << "hours: " + to_string(totalHours) << endl;
    LogFile << "hours left: " + to_string(hoursLeft) << endl;
    LogFile << "number of programmers: " << to_string(programmersNumber) << endl;
    LogFile << "number of artists: " << to_string(artistsNumber) << endl;
    LogFile << "manager :" + managerId << endl;
    if (fullyRecruit) LogFile << "fully recruited: yes" << endl;
    LogFile << "languages: ";
    for (int i = 0; i < progLangs.size(); i++)
    {
        LogFile << progLangs[i] + " ";
    }
    LogFile << "\nprogrammers fileds: ";
    for (int i = 0; i < progWorkField.size(); i++)
    {
        LogFile << progWorkField[i] << " ";
    }
    LogFile << "\nartists felds: ";
    for (int i = 0; i < artWorkField.size(); i++)
    {
        LogFile << artWorkField[i] + " ";
    }
    LogFile << "\nprogrammers: ";
    for (map<string, SmartPtr<Employee>>::iterator it = programmers.begin(); it != programmers.end(); it++)
    {
        LogFile << it->first + " ";
    }
    LogFile << "\nartists: ";
    for (map<string, SmartPtr<Employee>>::iterator it = artists.begin(); it != artists.end(); it++)
    {
        LogFile << it->first + " ";
    }
    LogFile << "\nclient: ";
    if (client.GetPtr() != NULL)
    {
        LogFile << client->getId();
    }
    LogFile << endl;
}

bool Project::removeEmployee(string empId)
{
    if (programmers.count(empId) == 1)
    {
        dismissEmployee(programmers.at(empId));
        programmers.erase(empId);
        LogFile << "programmer " + empId + " removed from project " + projId << endl;
        return true;
    }
    else if (artists.count(empId) == 1)
    {
        dismissEmployee(artists.at(empId));
        artists.erase(empId);
        LogFile << "artist " + empId + " removed from project " + projId << endl;
        return true;
    }
    else if (manager->getCompanyId() == empId)
    {
        dismissEmployee(manager);
        managerOccupied = false;
        managerId = "";
        LogFile << "manager " + empId + " rempved from project " + projId << endl;
        return false;
    }
    LogFile << "can't remove employee " + empId + " from project " + projId + "because doesn't exist already" << endl;
    return false;
}
