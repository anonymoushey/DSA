#include <iostream>    
#include<vector> 
#include<stdio.h>
#include <utility> 
using namespace std;

bool compare(pair <int, int> a, pair<int, int> b)
{
	if(a * a < b * b)
		return true;
	else
		return false;
}


int main(void)
{
	vector <pair <int, int> > a;
	a.push_back(makepair(10,20));
	a.push_back(makepair(30,20));
	a.push_back(makepair(10,150));
	a.push_back(makepair(150,20));
	sort(a.begin(), a.end(), compare);
	return 0;
}