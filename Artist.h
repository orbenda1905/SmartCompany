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
	Artist(const string Name, const string pId, const string phNum, string compId, int THrs, string currProj, int currProjHrs, int exp, int hrsPDay, bool employ, vector<string> flds);
	virtual ~Artist();
	virtual vector<string>& getFields();
	virtual void setFields(vector<string>& fields);
    void Print();
    void PrintArtist();
};

#endif /* ARTIST_H_ */
