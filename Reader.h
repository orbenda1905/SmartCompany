/*
 * Reader.h
 *
 *  Created on: May 25, 2015
 *      Author: Benda
 */

#ifndef READER_H_
#define READER_H_
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>
#include "DataSplit.h"
#include "SmartPtr.h"
#include "Company.h"

using namespace std;


class Reader {
private:
    char* fileName;
public:
	Reader(const char *file_name);
    virtual ~Reader();
    Reader(const char* file_name);
    vector<string> split(const string s, char c);
    void Tokenize(const string& str,vector<string>& tokens,const string& delimiters);

    

    
};


#endif /* defined(__SmartPointer__DataSplit__) */