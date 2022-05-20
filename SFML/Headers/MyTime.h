#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <ctime>
#include <string>
#include <sstream>
#include <iostream>
#include <tuple>


using namespace std;

struct myTime {
	int day = 0;
	int month = 0;
	int year = 0;
	int hours = 0;
	int min = 0;
};

myTime _GetCurrentTime();

string _intToString(int num);

myTime _stringToTime(const string& s);

int MonthToIndex(const string& month);

ostream& operator<< (ostream& os, const myTime& mT);

myTime& operator- (const myTime& lhs, const myTime& rhs);

bool operator> (const myTime& lhs, const myTime& rhs);
