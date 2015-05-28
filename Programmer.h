/*
 * Programmer.h
 *
 *  Created on: May 23, 2015
 *      Author: Benda
 */

#ifndef PROGRAMMER_H_
#define PROGRAMMER_H_


<<<<<<< HEAD

#include "Employee.h"
#include "Headers.h"
=======
#include "Employee.h"
#include "Project.h"
>>>>>>> 7a7e5d0ffd02c47320b9e9fed3b21066d4fef9d9

using namespace std;


class Programmer : public virtual Employee {
protected:
	vector<string> knowedLangs;
	vector<string> fields;
public:
    Programmer();
	Programmer(const string id, const string& Name, const long phNum, string compId, string *currProj, int TProjH, int THrs, int exp, bool employ, int hrsPDay, vector<string>& langs, vector<string>& flds);
	virtual ~Programmer();
	const vector<string>& getFields() const;
	const vector<string>& getKnowedLangs() const;
	void setKnowedLangs(vector<string>& langs);
	void setFields(vector<string>& field);
    void Print();
};



#endif /* PROGRAMMER_H_ */
