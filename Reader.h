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


class Reader {
private:
   
public:
	Reader(const char *file_name);
    virtual ~Reader();
    Reader(const char* file_name);
    vector<string> split(const string s, char c);
    void Tokenize(const string& str,vector<string>& tokens,const string& delimiters);

    

    
};


//int main()
//{
//    vector<string> vec;
//    string str = {"[donald duck;302945241;4506;cpp,bend]"};
//    Tokenize(str, vec, "[];");
//    for (vector<string>::iterator it = vec.begin(); it != vec.end(); ++it)
//    {
//        cout << *it << endl;
//    }

#endif /* READER_H_ */
