/*
 * Client.h
 *
 *  Created on: May 23, 2015
 *      Author: Benda
 */

#ifndef CLIENT_H_
#define CLIENT_H_

#include "Person.h"


class Client:public Person {
private:
	int totalProjcets;
	string currentProjectId;
public:
    Client(const string& Name, const string id, const string phNum, string curProjId,int tProjects);
	virtual ~Client();
    void PrintClient();


};

#endif /* CLIENT_H_ */
