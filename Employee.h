/*
 * Employee.h
 *
 *  Created on: May 23, 2015
 *      Author: Benda
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include "Headers.h"
#include "Project.h"


using namespace std;


class Employee : public Person {
private:
	string companyId;
protected:
	string currentProjectId;
	int soFarProjHours; //how many worked so far for this project
    int neededProjectHours; //how many hours he needs to do for this project
	int totalHours;
	int experience;
	bool isEmployed;
	int hoursPerDay;
public:
    Employee();
	Employee(const string Name, const string pId, const string phNum, string compId, int THrs, string currProj, int currProjHrs, int exp, int hrsPDay, bool employ);
	string getCompanyId() const;
	const string& getCurrentProjectId() const;
    void setProjectId(string& projId);
	int getExperience() const;
	void setExperience(int experience);
	int getHoursPerDay() const;
	void setHoursPerDay(int hoursPerDay);
	bool isIsEmployed() const;
	void setIsEmployed(bool isEmployed);
	int getTotalHours() const;
	void setTotalHours(int totalHours);
	int getSoFarProjHours() const;
	void setSoFarProjHours(int soFarProjHours);
    void speedUp();
    virtual void Print()=0;
    int getNeededProjectHours() const;
    void setNeededProjectHours(int num);
    const string& getId() const;
    void eraseProjId();
    bool getIsEmployed();

	~Employee();
};

#endif /* EMPLOYEE_H_ */
