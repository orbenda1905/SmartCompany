//
//  DataSplit.h
//  SmartPointer
//
//  Created by itay noama on 5/30/15.
//  Copyright (c) 2015 itay. All rights reserved.
//

#ifndef __SmartPointer__DataSplit__
#define __SmartPointer__DataSplit__

#include <iostream>
#include <vector>
#include <string>

using namespace std;


class DataSplit{
public:
    vector<string> Tokenize(const string& str,
        vector<string>& tokens,const string& delimiters = " ");
private:
    
};



//int main()
//{
//    vector<string> vec;
//    string str = {"[donald duck;302945241;4506;cpp,bend]"};
//    Tokenize(str, vec, "[];");
//    for (vector<string>::iterator it = vec.begin(); it != vec.end(); ++it)
//    {
//        cout << *it << endl;
//    }

#endif /* READER_H_ */
