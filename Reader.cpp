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
        getline(myFile, str);
        while (!myFile.eof())
        {
            if (str == "#INPUT-COMP\r")
            {
                getline(myFile, str);
                MakeCompany();
                getline(myFile, str);
                continue;
            }else if(str == "#INPUT-CLIENT\r")
            {
                getline(myFile, str);
                while (str[0] != '#') {
                    MakeClient();
                    getline(myFile, str);
                }
                continue;
            }else if(str == "#INPUT-EMP\r")
            {
                getline(myFile, str);
                while (str[0] != '#'){
                    MakeEmployee();
                    getline(myFile, str);
                }
                continue;
            }else if (str == "#INPUT-PROJ\r")
            {
                getline(myFile, str);
                while (str[0] != '#')
                {
                    MakeProject();
                    getline(myFile, str);
                }
                continue;
            }else if (str == "#INPUT-PROJCYC\r")
            {
                getline(myFile, str);
                while (str[0] != '#') {
                    MakeProjectCycle();
                    getline(myFile, str);
                }
                continue;
            }
            getline(myFile, str);
            
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
    ds.Tokenize(str, tokens, ";[]#");
    for (int i = 0; i < tokens.size(); i++)
    {
        cout << tokens[i] << endl;
    }
    SmartPtr<Client> client = new Client(tokens[0],tokens[1], tokens[2],stoi(tokens[3]),tokens[4]);
    company->addClient(client);
}

void Reader::MakeCompany()
{
    tokens.clear();
    ds.Tokenize(str,tokens, ";[]#");
    cout << tokens[0] << endl;
    company = new Company(tokens[0]);
}

void Reader::MakeEmployee()
{
    tokens.clear();
    ds.Tokenize(str, tokens,";[]#");
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
    ds.Tokenize(str, tokens,"[];#");
    vector<string> tempLangs;
    vector<string> tempFlds;
    ds.Tokenize(tokens[11], tempLangs,",");
    ds.Tokenize(tokens[12], tempFlds,",");
    SmartPtr<Employee> programmer  = new Programmer(tokens[0],tokens[1],tokens[2],tokens[4],stoi(tokens[5]),tokens[6],stoi(tokens[7]),stoi(tokens[8]),stoi(tokens[9]),stoi(tokens[10]),tempLangs,tempFlds);
    for (vector<string>::iterator it = tokens.begin(); it != tokens.end(); it++)
    {
        cout << *it << endl;
    }
    company->addEmployee(programmer);
}

void Reader::MakeManager()
{
    
    ds.Tokenize(str, tokens,"[];#");
    vector<string> fieldA;
    vector<string> fieldP;
    vector<string> knwdP;
    ds.Tokenize(tokens[11], knwdP,",");
    ds.Tokenize(tokens[12], fieldP,",");
    ds.Tokenize(tokens[13], fieldA,",");
    SmartPtr<Employee> manager  = new Manager(tokens[0],tokens[1],tokens[2],tokens[4],stoi(tokens[5]),tokens[6],stoi(tokens[7]),stoi(tokens[8]),stoi(tokens[9]),stoi(tokens[10]),knwdP,fieldP,fieldA);
    for (vector<string>::iterator it = tokens.begin(); it != tokens.end(); it++)
    {
        cout << *it << endl;
    }
    company->addEmployee(manager);
}

void Reader::MakeArtist()
{
    getline(myFile,str);
    ds.Tokenize(str, tokens,"[];#");
    vector<string> flds;
    ds.Tokenize(tokens[11], flds,",");
    SmartPtr<Employee> artist  = new Artist(tokens[0],tokens[1],tokens[2],tokens[4],stoi(tokens[5]),tokens[6],stoi(tokens[7]),stoi(tokens[8]),stoi(tokens[9]),stoi(tokens[10]),flds);
    for (vector<string>::iterator it = tokens.begin(); it != tokens.end(); it++)
    {
        cout << *it << endl;
    }
    company->addEmployee(artist);
}

void Reader::MakeProject()
{
    tokens.clear();
    ds.Tokenize(str, tokens,"[];#");
    vector<string> pFld;
    vector<string> aFld;
    ds.Tokenize(str, aFld,",");
    ds.Tokenize(str, pFld,",");
    SmartPtr<Project> project  = new Project(tokens[0],tokens[1],stoi(tokens[2]),stoi(tokens[3]),tokens[4],stoi(tokens[5]), stoi(tokens[6]), pFld,aFld);
    for (vector<string>::iterator it = tokens.begin(); it != tokens.end(); it++)
    {
        cout << *it << endl;
    }
    company->addProject(project);
}

void Reader::MakeProjectCycle()
{
    tokens.clear();
    ds.Tokenize(str, tokens,"[];#");
    company->addProjCycle(tokens[0], tokens[1]);
    for (vector<string>::iterator it = tokens.begin(); it != tokens.end(); it++)
    {
        cout << *it << endl;
    }
}



Reader::~Reader()
{
	
}




