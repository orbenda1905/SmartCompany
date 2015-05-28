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
class WriteTofile{

protected:
    fstream LogFile;
public:
    
    WriteTofile();
    ~WriteTofile();
    
    
    
    
    
};
#endif /* defined(__SmartPtr__WriteToFile__) */
