/*
 * Client.h
 *
 *  Created on: May 23, 2015
 *      Author: Benda
 */

#ifndef CLIENT_H_
#define CLIENT_H_

#include "Person.h"



class Client : public Person {
private:
	int totalProjects;
	string currentProjectId;
    bool projFinished = false;
public:
	Client(const string Name, const string pId, const string phNum, int tProjects, string curProjId);
	virtual ~Client();
    void PrintClient();
    bool getProjFinished();
    void setProjFinished(bool status);

};

#endif /* CLIENT_H_ */
