/*
 * Reader.cpp
 *
 *  Created on: May 25, 2015
 *      Author: Benda
 */

#include "Reader.h"

using namespace std;

Reader::Reader(string file_name)
{
    myFile.open(file_name);
}

void Reader::ReadData()
{
    
    if (myFile.is_open())
    {
        while (!myFile.eof())
        {
            getline(myFile,str);
            if (str == "#INPUT-COMP\r")
            {
                MakeCompany();
            }else if(str == "#INPUT-CLIENT\r")
            {
                MakeClient();
            }else if(str == "#INPUT-EMP\r")
            {
                MakeEmployee();
            }else if (str == "#INPUT-PROJ\r")
            {
                MakeProject();
            }else if (str == "#INPUT-PROJCYC\r")
            {
                MakeProjectCycle();
            }
            
        }
    }
}

SmartPtr<Company> Reader::getCompany()
{
    return company;
}

void Reader::MakeClient()
{
    tokens.clear();
    getline(myFile,str);
    tokens = ds.Tokenize(str, tokens, ";[]#");
    cout << tokens[0] << tokens[1]<<tokens[2] <<tokens[3] <<tokens[4] << endl;
    SmartPtr<Client> client = new Client(tokens[0],tokens[1], tokens[2],stoi(tokens[3]),tokens[4]);
}

void Reader::MakeCompany()
{
    tokens.clear();
    getline(myFile,str);
    tokens = ds.Tokenize(str,tokens, ";[]#");
    cout << tokens[0] << endl;
    company = new Company(tokens[0]);
}

void Reader::MakeEmployee()
{
    tokens.clear();
    getline(myFile,str);
    tokens = ds.Tokenize(str, tokens,";[]#");
    if (tokens[3] == "M")
        MakeManager();
    if (tokens[3] == "A")
        MakeArtist();
    if (tokens[3] == "P")
        MakeProgrammer();
    else{
        cout << "no correct employee" << endl;
    }
    
}


void Reader::MakeProgrammer()
{
    tokens = ds.Tokenize(str, tokens,"[];#");
    vector<string> tempLangs;
    vector<string> tempFlds;
    ds.Tokenize(tokens[11], tempLangs,",");
    ds.Tokenize(tokens[12], tempFlds,",");
    SmartPtr<Programmer> programmer  = new Programmer(tokens[0],tokens[1],tokens[2],tokens[4],stoi(tokens[5]),tokens[6],stoi(tokens[7]),stoi(tokens[8]),stoi(tokens[9]),stoi(tokens[10]),tempLangs,tempFlds);
    for (vector<string>::iterator it = tokens.begin(); it != tokens.end(); it++)
    {
        cout << *it << endl;
    }
    
}

void Reader::MakeManager()
{
    tokens = ds.Tokenize(str, tokens,"[];#");
    vector<string> fieldA;
    vector<string> fieldP;
    vector<string> knwdP;
    ds.Tokenize(tokens[11], knwdP,",");
    ds.Tokenize(tokens[12], fieldP,",");
    ds.Tokenize(tokens[13], fieldA,",");
    SmartPtr<Manager> manager  = new Manager(tokens[0],tokens[1],tokens[2],tokens[4],stoi(tokens[5]),tokens[6],stoi(tokens[7]),stoi(tokens[8]),stoi(tokens[9]),stoi(tokens[10]),knwdP,fieldP,fieldA);
    for (vector<string>::iterator it = tokens.begin(); it != tokens.end(); it++)
    {
        cout << *it << endl;
    }

}

void Reader::MakeArtist()
{
    getline(myFile,str);
    tokens = ds.Tokenize(str, tokens,"[];#");
    vector<string> flds;
    ds.Tokenize(tokens[11], flds,",");
    SmartPtr<Artist> artist  = new Artist(tokens[0],tokens[1],tokens[2],tokens[4],stoi(tokens[5]),tokens[6],stoi(tokens[7]),stoi(tokens[8]),stoi(tokens[9]),stoi(tokens[10]),flds);
    for (vector<string>::iterator it = tokens.begin(); it != tokens.end(); it++)
    {
        cout << *it << endl;
    }
}

void Reader::MakeProject()
{
    getline(myFile,str);
    tokens = ds.Tokenize(str, tokens,"[];#");
    vector<string> pFld;
    vector<string> aFld;
    ds.Tokenize(str, aFld,",");
    ds.Tokenize(str, pFld,",");
    SmartPtr<Project> project  = new Project(tokens[0],tokens[1],stoi(tokens[2]),stoi(tokens[3]),stoi(tokens[4]),stoi(tokens[5]),pFld,aFld);
    for (vector<string>::iterator it = tokens.begin(); it != tokens.end(); it++)
    {
        cout << *it << endl;
    }
}

void Reader::MakeProjectCycle()
{
    getline(myFile,str);
    tokens = ds.Tokenize(str, tokens,"[];#");
    company->addProjCycle(tokens[0], tokens[1]);
    for (vector<string>::iterator it = tokens.begin(); it != tokens.end(); it++)
    {
        cout << *it << endl;
    }
}



Reader::~Reader()
{
	
}




