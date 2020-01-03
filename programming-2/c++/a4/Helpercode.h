#ifndef HELPER_
#define HELPER_
struct Date 
{ 
	int d, m, y; 
}; 
int countLeapYears(Date d) ;
int getDifference(Date dt1, Date dt2) ;
bool isLeap(int y);
int offsetDays(int d, int m, int y) ;
void revoffsetDays(int offset, int y, int *d, int *m) ;
Date addDays(int d1, int m1, int y1, int x) ;
#endif