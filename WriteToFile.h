//
//  WriteToFile.h
//  SmartPtr
//
//  Created by Noam Roiz on 5/28/15.
//  Copyright (c) 2015 Noam Roiz. All rights reserved.
//

#ifndef __SmartPtr__WriteToFile__
#define __SmartPtr__WriteToFile__

#include <stdio.h>
#include <fstream>
using namespace std;
class WriteToFile{
protected:

    static ofstream& LogFile;
    
public:
    WriteToFile();
    ~WriteToFile();
    
};

static ofstream output("Logger.txt", ios_base::app);

ofstream& WriteToFile::LogFile = output;
#endif /* defined(__SmartPtr__WriteToFile__) */
