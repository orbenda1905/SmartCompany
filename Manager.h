/*
 * Manager.h
 *
 *  Created on: May 23, 2015
 *      Author: Benda
 */

#ifndef MANAGER_H_
#define MANAGER_H_

#include "Headers.h"
#include "Artist.h"
#include "Programmer.h"

using namespace std;

class Manager : public Programmer, public Artist {
private:
	int projCount;
public:
	Manager(const string Name, const string pId, const string phNum, string compId, int THrs, string currProj, int currProjHrs, int exp, int hrsPDay, bool employ, vector<string> knwdP, vector<string> fieldP, vector<string> fieldA);
	virtual ~Manager();
    void Printmanger();

};


#endif /* MANAGER_H_ */
