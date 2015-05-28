/*
 * Programmer.h
 *
 *  Created on: May 23, 2015
 *      Author: Benda
 */

#ifndef PROGRAMMER_H_
#define PROGRAMMER_H_



#include "Project.h"

using namespace std;


class Programmer : public virtual Employee {
protected:
	vector<string> knowedLangs;
	vector<string> fields;
public:
    Programmer();
	Programmer(const string id, const string& Name, const long phNum, string compId, SmartPtr<Project>& currProj, int TProjH, int THrs, int exp, bool employ, int hrsPDay, vector<string>& langs, vector<string>& flds);
	virtual ~Programmer();
	const vector<string>& getFields() const;
	const vector<string>& getKnowedLangs() const;
	void setKnowedLangs(vector<string>& langs);
	void setFields(vector<string>& field);
};



#endif /* PROGRAMMER_H_ */
