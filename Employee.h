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


class Employee: public Person {
private:
	string companyId;
protected:
	string *currentProjectId = NULL;
	int totalProjHours; //how many worked so far for this project
    int neededProjectHours = 0; //how many hours he needs to do for this project
	int totalHours;
	int experience;
	bool isEmployed;
	int hoursPerDay;
public:
    Employee();
	Employee(const string id, const string& Name, const long phNum, string compId, string *currProj, int TProjH, int THrs, int exp, bool employ, int hrsPDay);
	string getCompanyId() const;
	const string& getCurrentProjectId() const;
	int getExperience() const;
	void setExperience(int experience);
	int getHoursPerDay() const;
	void setHoursPerDay(int hoursPerDay);
	bool isIsEmployed() const;
	void setIsEmployed(bool isEmployed);
	int getTotalHours() const;
	void setTotalHours(int totalHours);
	int getTotalProjHours() const;
	void setTotalProjHours(int totalProjHours);
    void speedUp();
    virtual void Print()=0;
    int getNeededProjectHours() const;

	~Employee();
};

#endif /* EMPLOYEE_H_ */
