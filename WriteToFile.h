//
//  WriteToFile.h
//  SmartPtr
//
//  Created by Noam Roiz on 5/28/15.
//  Copyright (c) 2015 Noam Roiz. All rights reserved.
//

#ifndef __SmartPtr__WriteToFile__
#define __SmartPtr__WriteToFile__

#include <iostream>
#include <fstream>
using namespace std;
class WriteToFile{
    
protected:

    static fstream LogFile;

public:
    WriteToFile();
    ~WriteToFile();
    
};



#endif /* defined(__SmartPtr__WriteToFile__) */
