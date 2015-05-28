/*
 * Reader.h
 *
 *  Created on: May 25, 2015
 *      Author: Benda
 */

#ifndef READER_H_
#define READER_H_
#include <iostream>
#include <fstream>
#include "Client.h"
#include "Company.h"
#include "Employee.h"
#include "Manager.h"
#include "Artist.h"
#include "Person.h"
#include "Programmer.h"




using namespace std;

class Reader {
private:
   char* get_line(ifstream &f);
public:
	Reader();
    virtual ~Reader();
    Reader(const char* file_name);
    vector<string> split(const string s, char c);
    

    
};

#endif /* READER_H_ */
