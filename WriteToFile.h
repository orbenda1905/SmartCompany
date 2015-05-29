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

private:
    fstream LogFile;
public:
    void OutToFile(string data);
    WriteTofile();
    ~WriteTofile();
    
    
    
    
    
};
#endif /* defined(__SmartPtr__WriteToFile__) */
