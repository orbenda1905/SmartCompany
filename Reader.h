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


using namespace std;

class Reader {
public:
	Reader(const char *file_name);
    virtual ~Reader();
    
    
};

#endif /* READER_H_ */
