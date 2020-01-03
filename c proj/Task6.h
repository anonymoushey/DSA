#ifndef TASK_6
#define TASK_6
#include "TaskTemplate.h"

class Task6 :public TaskInterface{
    public : 
    Task6(){}
    vector<double > solve();
    bool check(string e);
    string output();
    int findIndex(string e , char c, int repeatedTime);
    void correctPlusMinus();
    int checkInteger(string s);
    ~Task6();
    Task6(const Task6 &);
//     roundoff(float ans);
};

#endif