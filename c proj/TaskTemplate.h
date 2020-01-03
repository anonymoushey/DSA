#ifndef TASKTEMPLATE_H
#define TASKTEMPLATE_H

#include<string>
#include<vector>

using namespace std;

class TaskInterface
{
    protected:
    string equation;
    virtual vector <double> solve() = 0; //function to solve the equation in the data member string


    public:
    virtual bool check(string e) = 0;// return true if the string e is your task, else return false 
    virtual string output() = 0; // return a string containing your results

    void setEquation(string e)
    {
        equation = e;
    }

};

#endif