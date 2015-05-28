/*
 * Artist.h
 *
 *  Created on: May 23, 2015
 *      Author: Benda
 */

#ifndef ARTIST_H_
#define ARTIST_H_

#include "Headers.h"
#include "Employee.h"





class Artist : public virtual Employee {
protected:
	vector<string> fields;
    
public:
    Artist();
	Artist(const string id, const string& Name, const long phNum, string compId, Project& currProj, int TProjH, int THrs, int exp, bool employ, int hrsPDay, vector<string>& flds);
	virtual ~Artist();
	vector<string>& getFields() const;
	void setFields(vector<string>& fields);
    void Print();
};

#endif /* ARTIST_H_ */
