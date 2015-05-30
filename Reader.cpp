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

Reader::Reader(){
    
}

  
void Reader::Tokenize(const string& str,vector<string>& tokens,const string& delimiters){
    // Skip delimiters at beginning.
    string::size_type lastPos = str.find_first_not_of(delimiters, 0);
    // Find first "non-delimiter".
    string::size_type pos     = str.find_first_of(delimiters, lastPos);
    
    while (string::npos != pos || string::npos != lastPos)
    {
        // Found a token, add it to the vector.
        tokens.push_back(str.substr(lastPos, pos - lastPos));
        // Skip delimiters.  Note the "not_of"
        lastPos = str.find_first_not_of(delimiters, pos);
        // Find next "non-delimiter"
        pos = str.find_first_of(delimiters, lastPos);
    }
}



Reader::~Reader() {
	
}


/*
 ifstream f(file_name);
 char* line = get_line(f);
 SmartPtr<Company> company = new Company(line);
 
 */