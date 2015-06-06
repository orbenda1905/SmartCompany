//
//  main.cpp
//  Company
//
//  Created by Or Ben David on 6/1/15.
//  Copyright (c) 2015 Or Ben David. All rights reserved.
//

#include <iostream>
#include "Company.h"
#include "SmartPtr.h"
#include "Reader.h"


int main()
{
    Reader *read = new Reader("SampleInput.txt");
    read->ReadData();
    read->getCompany()->startArrange();
    read->startSimulate("SampleSimulation.txt");
    delete read;
}