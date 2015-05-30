/*
 * Reader.cpp
 *
 *  Created on: May 25, 2015
 *      Author: Benda
 */

#include "Reader.h"
#include <iostream>
#include <string.h>

using namespace std;

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




Reader::~Reader() {
	
}

