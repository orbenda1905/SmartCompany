
//
//  WriteToFile.cpp
//  SmartPtr
//
//  Created by Noam Roiz on 5/28/15.
//  Copyright (c) 2015 Noam Roiz. All rights reserved.
//

#include "WriteToFile.h"

//static ofstream output("Logger.txt", ios::app);


fstream WriteToFile::LogFile("logger.txt", ios::app);


WriteToFile::WriteToFile(){
    

};

WriteToFile::~WriteToFile(){
    
}