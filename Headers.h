/*
 * Headers.h
 *
 *  Created on: May 23, 2015
 *      Author: Benda
 */

#ifndef HEADERS_H_
#define HEADERS_H_
#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include "SmartPtr.h"
//#include "WriteToFile.h"
using namespace std;

typedef enum FieldProg {FEND, SEC, MBL, BEND} FieldProg;
typedef enum FieldArt {TwoD, ThreeD, MSC, CRTV} FieldArt;
typedef enum ProgLang {C, CPP, JAVA, HTML} ProgLang;

void WriteToFile(string OutToFile){
    ofstream LogFile;
    LogFile.open("Logger.txt", ios_base::app);
    if (LogFile.is_open())
    {
        LogFile << OutToFile;
        LogFile.close();
    }
    else cout << "Unable to open file";
}



#endif /* HEADERS_H_ */
