
//
//  WriteToFile.cpp
//  SmartPtr
//
//  Created by Noam Roiz on 5/28/15.
//  Copyright (c) 2015 Noam Roiz. All rights reserved.
//

#include "WriteToFile.h"

static ofstream output("Logger.txt", ios_base::app);

ofstream& WriteToFile::LogFile = output;


WriteToFile::WriteToFile(){


};

WriteToFile::~WriteToFile(){
    
    LogFile.close();

}