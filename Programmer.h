/*
 * Programmer.h
 *
 *  Created on: May 23, 2015
 *      Author: Benda
 */

#ifndef PROGRAMMER_H_
#define PROGRAMMER_H_



#include "Employee.h"
#include "Headers.h"

using namespace std;


class Programmer : public virtual Employee {
protected:
	vector<string> knowedLangs;
	vector<string> fields;
public:
    Programmer();
	Programmer(const string id, const string& Name, const long phNum, string compId, string *currProj, int TProjH, int THrs, int exp, bool employ, int hrsPDay, vector<string>& langs, vector<string>& flds);
	virtual ~Programmer();
	virtual vector<string>& getFields();
	virtual vector<string>& getKnowedLangs();
	void setKnowedLangs(vector<string>& langs);
	virtual void setFields(vector<string>& field);
    void Print();
};



#endif /* PROGRAMMER_H_ */
