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
	SmartPtr<Project> currentProject;
	int totalProjHours;
	int totalHours;
	int experience;
	bool isEmployed;
	int hoursPerDay;
public:
	Employee(const string id, const string& Name, const long phNum, string compId, SmartPtr<Project>& currProj, int TProjH, int THrs, int exp, bool employ, int hrsPDay);
	string getCompanyId() const;
	Project& getCurrentProject() const;
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

	~Employee();
};

#endif /* EMPLOYEE_H_ */
