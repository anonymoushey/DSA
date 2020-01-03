/*acknowledgements in the bottom*/
// C++ program two find number of days between two given dates 
#include "Helpercode.h"
#include<iostream> 
using namespace std; 

// A date has day 'd', month 'm' and year 'y' 


// To store number of days in all months from January to Dec. 
const int monthDays[12] = {31, 28, 31, 30, 31, 30, 
						31, 31, 30, 31, 30, 31}; 

// This function counts number of leap years before the 
// given date 
int countLeapYears(Date d) 
{ 
	int years = d.y; 

	// Check if the current year needs to be considered 
	// for the count of leap years or not 
	if (d.m <= 2) 
		years--; 

	// An year is a leap year if it is a multiple of 4, 
	// multiple of 400 and not a multiple of 100. 
	return years / 4 - years / 100 + years / 400; 
} 

// This function returns number of days between two given 
// dates 
int getDifference(Date dt1, Date dt2) 
{ 
	// COUNT TOTAL NUMBER OF DAYS BEFORE FIRST DATE 'dt1' 

	// initialize count using years and day 
	long int n1 = dt1.y*365 + dt1.d; 

	// Add days for months in given date 
	for (int i=0; i<dt1.m - 1; i++) 
		n1 += monthDays[i]; 

	// Since every leap year is of 366 days, 
	// Add a day for every leap year 
	n1 += countLeapYears(dt1); 

	// SIMILARLY, COUNT TOTAL NUMBER OF DAYS BEFORE 'dt2' 

	long int n2 = dt2.y*365 + dt2.d; 
	for (int i=0; i<dt2.m - 1; i++) 
		n2 += monthDays[i]; 
	n2 += countLeapYears(dt2); 

	// return difference between two counts 
	return (n2 - n1); 
} 


//	cout << "Difference between two dates is " << getDifference(dt1, dt2); 

/////////


// C++ program to find date after adding 
// given number of days. 


// Return if year is leap year or not. 
bool isLeap(int y) 
{ 
	if ((y%100 != 0 && y%4 == 0) || y %400 == 0) 
		return true; 

	return false; 
} 

// Given a date, returns number of days elapsed 
// from the beginning of the current year (1st 
// jan). 
int offsetDays(int d, int m, int y) 
{ 
	int offset = d; 

	switch (m - 1) 
	{ 
	case 11: 
		offset += 30; 
	case 10: 
		offset += 31; 
	case 9: 
		offset += 30; 
	case 8: 
		offset += 31; 
	case 7: 
		offset += 31; 
	case 6: 
		offset += 30; 
	case 5: 
		offset += 31; 
	case 4: 
		offset += 30; 
	case 3: 
		offset += 31; 
	case 2: 
		offset += 28; 
	case 1: 
		offset += 31; 
	} 

	if (isLeap(y) && m > 2) 
		offset += 1; 

	return offset; 
} 

// Given a year and days elapsed in it, finds 
// date by storing results in d and m. 
void revoffsetDays(int offset, int y, int *d, int *m) 
{ 
	int month[13] = { 0, 31, 28, 31, 30, 31, 30, 
					31, 31, 30, 31, 30, 31 }; 

	if (isLeap(y)) 
		month[2] = 29; 

	int i; 
	for (i = 1; i <= 12; i++) 
	{ 
		if (offset <= month[i]) 
			break; 
		offset = offset - month[i]; 
	} 

	*d = offset; 
	*m = i; 
} 

// Add x days to the given date. 
Date addDays(int d1, int m1, int y1, int x) 
{ 
	int offset1 = offsetDays(d1, m1, y1); 
	int remDays = isLeap(y1)?(366-offset1):(365-offset1); 

	// y2 is going to store result year and 
	// offset2 is going to store offset days 
	// in result year. 
	int y2, offset2; 
	if (x <= remDays) 
	{ 
		y2 = y1; 
		offset2 = offset1 + x; 
	} 

	else
	{ 
		// x may store thousands of days. 
		// We find correct year and offset 
		// in the year. 
		x -= remDays; 
		y2 = y1 + 1; 
		int y2days = isLeap(y2)?366:365; 
		while (x >= y2days) 
		{ 
			x -= y2days; 
			y2++; 
			y2days = isLeap(y2)?366:365; 
		} 
		offset2 = x; 
	} 

	// Find values of day and month from 
	// offset of result year. 
	int m2, d2; 
	revoffsetDays(offset2, y2, &d2, &m2); 
    Date d = {d2,m2,y2};
	return d;
} 



//	addDays(d, m, y, x); 




//Credits - GeeksforGeeks https://www.geeksforgeeks.org/find-number-of-days-between-two-given-dates/, https://www.geeksforgeeks.org/date-after-adding-given-number-of-days-to-the-given-date/