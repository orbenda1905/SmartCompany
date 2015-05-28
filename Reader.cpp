/*
 * Reader.cpp
 *
 *  Created on: May 25, 2015
 *      Author: Benda
 */

#include "Reader.h"
#include <iostream>
#include <string.h>

using namespace::std;

#define N 250

Reader::Reader(const char* file_name){
    ifstream f(file_name);
    char* line = get_line(f);
    SmartPtr<Company> company = new Company(line);
    string company_name = strtok(line, ";");
    Company(Company(company_name));
    
    line = get_line(f);
    SmartPtr<Client> client = new Client();
    string client_name = strtok(NULL, ";");
    
    
    
    
    
    
    
    
}

vector<string> Reader::split(const string s, char c){
    vector<string> result;
    int start = 1;
    int end = 1;
    
    while(s[end] != ']'){
        while(s[end] != c){
            end++;
        }
        
        result.push_back(string(s,start,end-start));
        start = end+1;
        end++;
    }
    return result;
}

char* Reader::get_line(ifstream &f) {
    char *temp = new char[N];
    f.getline(temp, N);
    
    if (temp[0] == '#') {
        delete[] temp;
        return get_line(f);
    }
    
    return temp;
}

Reader::Reader() {
	

}

Reader::~Reader() {
	
}

