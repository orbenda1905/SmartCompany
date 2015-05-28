
//
//  WriteToFile.cpp
//  SmartPtr
//
//  Created by Noam Roiz on 5/28/15.
//  Copyright (c) 2015 Noam Roiz. All rights reserved.
//

#include "WriteToFile.h"
#include "Headers.h"



WriteTofile::WriteTofile(){
    
    LogFile.open("Logger.txt", ios_base::app);
    if (!LogFile.is_open())
        cout<<"file couln'topen"<<endl;
};

WriteTofile::~WriteTofile(){
    
    LogFile.close();

}