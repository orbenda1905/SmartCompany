
//
//  WriteToFile.cpp
//  SmartPtr
//
//  Created by Noam Roiz on 5/28/15.
//  Copyright (c) 2015 Noam Roiz. All rights reserved.
//

#include "WriteToFile.h"
#include "Headers.h"


void WriteTofile::OutToFile(string data){
    
    if (LogFile.is_open())
    {
        LogFile << "This is a line.\n";
        LogFile<< "This is another line.\n";
        LogFile.close();
    }
    else cout << "Unable to open file";
    return 0;
}
}