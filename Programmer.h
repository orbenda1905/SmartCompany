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
	Programmer(const string Name, const string pId, const string phNum, string compId, int THrs, string currProj, int currProjHrs, int exp, int hrsPDay, bool employ, vector<string> langs, vector<string> flds);
	virtual ~Programmer();
	virtual vector<string>& getFields();
	virtual vector<string>& getKnowedLangs();
	void setKnowedLangs(vector<string>& langs);
	virtual void setFields(vector<string>& field);
    void Print();
    void PrintProg();
};



#endif /* PROGRAMMER_H_ */
