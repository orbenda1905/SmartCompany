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
//#include <sstream>
//#include <string>
//#include <fstream>
#include "DataSplit.h"
//#include "SmartPtr.h"
#include "Company.h"

using namespace std;


class Reader : WriteToFile{
private:
    ifstream myFile;
    SmartPtr<Company> company;
    string str;
    vector<string> tokens;
    DataSplit ds;
public:
	Reader(string file_name);
    virtual ~Reader();
    void ReadData();
    void MakeClient();
    void MakeCompany();
    void MakeProgrammer();
    void MakeManager();
    void MakeArtist();
    void MakeProject();
    void MakeProjectCycle();
    void MakeEmployee();
    SmartPtr<Company>& getCompany();
    void startSimulate(string fileName);
};



#endif /* defined(__SmartPointer__DataSplit__) */