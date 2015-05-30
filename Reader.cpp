/*
 * Reader.cpp
 *
 *  Created on: May 25, 2015
 *      Author: Benda
 */

#include "Reader.h"
#include "DataSplit.cpp"
#include <iostream>
#include <string>

using namespace std;

Reader::Reader(const char* file_name)
{
    fileName = new char[strlen(file_name)+1];
    strcpy(fileName, file_name);
}

void Reader::ReadData()
{
    SmartPtr<Company> company = new Company();
    string str;
    ifstream myFile (fileName);
    if (myFile.is_open())
    {
        while (!myFile.eof())
        {
            getline(myFile,str);
            if (str == "#INPUT-COMP\r")
            {
                getline(myFile,str);
                if (str[0] != '#' && str != "\r")
                {
                    vector<string> tokens = ds.Tokenize(str, tokens, ";");
                    cout << tokens[0] << endl;
                    
                }
            }else if(str == "#INPUT-CLIENT\r")
            {
                getline(myFile,str);
                while (str[0] != '#' && str != "\r")
                {
                    vector<string> tokens = ds.Tokenize(str, tokens, ";");
                    SmartPtr<Client> client = new Client();
                    Client->
                }
            }
        }
    }
}








Reader::~Reader() {
	
}


/*
 ifstream f(file_name);
 char* line = get_line(f);
 SmartPtr<Company> company = new Company(line);
 
 */