/*
 * Project.h
 *
 *  Created on: May 23, 2015
 *      Author: Benda
 */

#ifndef PROJECT_H_
#define PROJECT_H_
#include "Headers.h"
#include "Manager.h"
#include "Employee.h"
#include "Client.h"
#include "SmartPtr.h"
#include "WriteToFile.h"





class Project : public WriteToFile {
private:

	string projId;
	int totalHours;
	int hoursLeft;
	string projectName;
    int programmersNumber;
	int artistsNumber;
    string managerId = "";
    bool fullyRecruit = false;
    bool needToRemove = false;
    bool managerOccupied = false;
	vector<string> progWorkField;
    vector<string> progLangs;
	vector<string> artWorkField;
	SmartPtr<Employee> manager;
    map<string, SmartPtr<Employee>> artists;
    map<string, SmartPtr<Employee>> programmers;
	map<string, SmartPtr<Employee>> finishedWorkers;
	SmartPtr<Client> client;
    

public:
	Project(string name, string prId, int ttlHrs, int hrsLft, string mangr, int progCnt, int artCnt, vector<string>& pFld,vector<string>& aFld);
    ~Project();
	int getArtistsNumber() const;
	void setArtistsNumber(int artistsNumber);
	const vector<string>& getArtWorkField() const;
	void setArtWorkField(vector<string>& artWorkField);
	const SmartPtr<Client>& getClient() const;
	void setClient(const SmartPtr<Client>& client);
	int getHoursLeft() const;
	void setHoursLeft(int hoursLeft);
    SmartPtr<Employee>& getManager();
	void setManager(SmartPtr<Employee> manager);
	int getProgrammersNumber() const;
	void setProgrammersNumber(int programmersNumber);
	const vector<string>& getProgWorkField() const;
	void setProgWorkField(vector<string>& progWorkField);
	const string& getProjectName() const;
	void setProjectName(const string& projectName);
	const string& getProjId() const;
	int getTotalHours() const;
	void setTotalHours(int totalHours);
	void speedUp();
	void checkFinish();
    bool checkExistProg(SmartPtr<Employee>& emp);
    bool checkExistArtist(SmartPtr<Employee>& emp);
    bool checkIfNeedingProg(SmartPtr<Employee>& emp);
    bool checkIfNeedingArt(SmartPtr<Employee>& emp);
    bool addProgrammer(SmartPtr<Employee>& emp);
    bool addArtist(SmartPtr<Employee>& emp);
    void beginTheProject();
    void finishProject();
    void dismissEmployee(SmartPtr<Employee>& emp);
    bool getNeedToRemove();
    bool getManagerOccupied();
    string getManagerId();

};



#endif /* PROJECT_H_ */
