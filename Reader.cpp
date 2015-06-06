/*
 * Reader.cpp
 *
 *  Created on: May 25, 2015
 *      Author: Benda
 */

#include "Reader.h"

using namespace std;

Reader::Reader(string file_name) : WriteToFile()
{
    LogFile << "==============================================" << endl;    
    myFile.open(file_name);
}

void Reader::ReadData()
{
    
    if (myFile.is_open())
    {
        getline(myFile, str);
        while (!myFile.eof())
        {
            if (str.find("#INPUT-COMP") != -1)
            {
                getline(myFile, str);
                MakeCompany();
                getline(myFile, str);
                continue;
            }else if(str.find("#INPUT-CLIENT") != -1)
            {
                getline(myFile, str);
                while (str[0] != '#' && str.size() > 1) {
                    MakeClient();
                    getline(myFile, str);
                }
                continue;
            }else if(str.find("#INPUT-EMP") != -1)
            {
                getline(myFile, str);
                while (str[0] != '#' && str.size() > 1){
                    MakeEmployee();
                    getline(myFile, str);
                }
                continue;
            }else if (str == "#INPUT-PROJ\r")
            {
                getline(myFile, str);
                while (str[0] != '#' && str.size() > 1)
                {
                    MakeProject();
                    getline(myFile, str);
                }
                continue;
            }else if (str.find("#INPUT-PROJCYC") != -1)
            {
                getline(myFile, str);
                while (str[0] != '#' && str.size() > 1) {
                    MakeProjectCycle();
                    getline(myFile, str);
                }
                continue;
            }
            getline(myFile, str);
            
        }
    }
}

SmartPtr<Company>& Reader::getCompany()
{
    return company;
}

void Reader::MakeClient()
{
    tokens.clear();
    ds.Tokenize(str, tokens, ";[]#");
    SmartPtr<Client> client = new Client(tokens[0],tokens[1], tokens[2],tokens[3],stoi(tokens[4]));
    company->addClient(client);
}

void Reader::MakeCompany()
{
    tokens.clear();
    ds.Tokenize(str,tokens, ";[]#");
    company = new Company(tokens[0]);
}

void Reader::MakeEmployee()
{
    tokens.clear();
    ds.Tokenize(str, tokens,";[]#");
    if (tokens[3] == "M"){
        MakeManager();
        return;
    }
    if (tokens[3] == "A"){
        MakeArtist();
        return;
    }
    if (tokens[3] == "P"){
        MakeProgrammer();
        return;
    }
    else{
        LogFile  << "no correcrt position to employee" << endl;
        cout << "no correcrt position to employee" << endl;
    }
    
}


void Reader::MakeProgrammer()
{
    vector<string> tempLangs;
    vector<string> tempFlds;
    ds.Tokenize(tokens[11], tempLangs,",");
    ds.Tokenize(tokens[12], tempFlds,",");
    SmartPtr<Employee> programmer  = new Programmer(tokens[0],tokens[1],tokens[2],tokens[4],stoi(tokens[5]),tokens[6],stoi(tokens[7]),stoi(tokens[8]),stoi(tokens[9]),stoi(tokens[10]),tempLangs,tempFlds);
    company->addEmployee(programmer);
}

void Reader::MakeManager()
{
    
    vector<string> fieldA;
    vector<string> fieldP;
    vector<string> knwdP;
    ds.Tokenize(tokens[11], knwdP, ",");
    ds.Tokenize(tokens[12], fieldP, ",");
    ds.Tokenize(tokens[13], fieldA, ",");
    SmartPtr<Employee> manager  = new Manager(tokens[0],tokens[1],tokens[2],tokens[4],stoi(tokens[5]),tokens[6],stoi(tokens[7]),stoi(tokens[8]),stoi(tokens[9]),stoi(tokens[10]),knwdP,fieldP,fieldA);
    company->addEmployee(manager);
}

void Reader::MakeArtist()
{
    vector<string> flds;
    ds.Tokenize(tokens[11], flds,",");
    SmartPtr<Employee> artist  = new Artist(tokens[0],tokens[1],tokens[2],tokens[4],stoi(tokens[5]),tokens[6],stoi(tokens[7]),stoi(tokens[8]),stoi(tokens[9]),stoi(tokens[10]),flds);
    company->addEmployee(artist);
}

void Reader::MakeProject()
{
    tokens.clear();
    ds.Tokenize(str, tokens,"[];#");
    vector<string> pFld;
    vector<string> aFld;
    ds.Tokenize(tokens[7], pFld,",");
    ds.Tokenize(tokens[8], aFld,",");
    SmartPtr<Project> project  = new Project(tokens[0],tokens[1],stoi(tokens[2]),stoi(tokens[3]),tokens[4],stoi(tokens[5]), stoi(tokens[6]), pFld,aFld);
    company->addProject(project);
}

void Reader::MakeProjectCycle()
{
    tokens.clear();
    ds.Tokenize(str, tokens,"[];#");
    company->addProjCycle(tokens[0], tokens[1]);
}

void Reader::startSimulate(string fileName)
{
    if (myFile.is_open()) myFile.close();
    myFile.open(fileName);
    getline(myFile, str);
    while (!myFile.eof())
    {
        if (str == "#AddEmp\r")//the reason for this check is because in mac computers strings ends with "\r\n"and in with "find" method it fits for mac and pc"
        {
            getline(myFile, str);
            MakeEmployee();
        }
        else if (str == "#AddProj\r")
        {
            getline(myFile, str);
            MakeProject();
        }
        else if (str.find("#AddClient") != -1)
        {
            getline(myFile, str);
            MakeClient();
        }
        else if (str.find("#PrintProjects") != -1)
        {
            company->printProjects();
        }
        else if (str.find("#AdvanceTime") != -1)
        {
            company->speedUp();
        }
        else if (str.find("#PrintClient") != -1)
        {
            getline(myFile, str);
            tokens.clear();
            ds.Tokenize(str, tokens, ";[]");
            company->printClient(tokens[0]);
        }
        else if (str.find("#PrintEmployeeList") != -1)
        {
            company->printEmployees();
        }
        else if (str.find("#END") != -1)
        {
            delete company;
            return;
        }
        else if (str.find("#AddEmpToProj") != -1)
        {
            getline(myFile, str);
            tokens.clear();
            ds.Tokenize(str, tokens, "[];");
            company->addEmployeeToProject(tokens[0], tokens[1], tokens[2]);
        }
        else if (str.find("#RemEmpFrmProj") != -1)
        {
            getline(myFile, str);
            tokens.clear();
            ds.Tokenize(str, tokens, ";[]");
            company->removeEmpFromProject(tokens[0], tokens[1]);
            continue;
        }
        else if (str == "#PrintProj\r")
        {
            getline(myFile, str);
            tokens.clear();
            ds.Tokenize(str, tokens, ";[]");
            company->printProject(tokens[0]);
            continue;
        }
        else if (str.find("#HaltProj") != -1)
        {
            getline(myFile, str);
            tokens.clear();
            ds.Tokenize(str, tokens, ";[]");
            company->stopCycle(tokens[0]);
        }
        getline(myFile, str);
    }
}


Reader::~Reader()
{
    LogFile << "reader destroyed" << endl;
    cout << "reader destroyed" << endl;
    myFile.close();
}




