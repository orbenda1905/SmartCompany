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





class Project {
private:

	string projId;
	int totalHours;
	int hoursLeft;
	string projectName;
	int programmersNumber;
	int artistsNumber;
	vector<string> progWorkField;
	vector<string> artWorkField;
	SmartPtr<Manager> manager;
	map<SmartPtr<Employee>, string> curWorkers;
	map<SmartPtr<Employee>, string> finishedWorkers;
	SmartPtr<Client> client;

public:
	Project(string name, string id, int ttlHrs, int hrsLft, SmartPtr<Manager>& mngr, int progCnt, int artCnt, vector<string>& pFld,vector<string>& aFld, map<SmartPtr<Employee>, string>& curList, map<SmartPtr<Employee>, string>& doneList, SmartPtr<Client>& client);
	int getArtistsNumber() const;
	void setArtistsNumber(int artistsNumber);
	const vector<string>& getArtWorkField() const;
	void setArtWorkField(vector<string>& artWorkField);
	const SmartPtr<Client>& getClient() const;
	void setClient(const SmartPtr<Client>& client);
	const map<SmartPtr<Employee>, string>& getCurWorkers() const;
	void setCurWorkers(const map<SmartPtr<Employee>, string>& curWorkers);
	const map<SmartPtr<Employee>, string>& getFinishedWorkers() const;
	void setFinishedWorkers(const map<SmartPtr<Employee>, string>& finishedWorkers);
	int getHoursLeft() const;
	void setHoursLeft(int hoursLeft);
	const SmartPtr<Manager>& getManager() const;
	void setManager(const SmartPtr<Manager>& manager);
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
};



#endif /* PROJECT_H_ */
