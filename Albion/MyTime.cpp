#include "MyTime.h"

ostream& operator<< (ostream& os, const myTime& mT) {
	os << _intToString(mT.day) 
		<< '.' << _intToString(mT.month)
		<< '.' << _intToString(mT.year)
		<< ' ' << _intToString(mT.hours)
		<< ':' << _intToString(mT.min);
	return os;
}

myTime& operator- (const myTime& lhs, const myTime& rhs) {
	myTime mt;
	mt.day = lhs.day - rhs.day;
	mt.month = lhs.month - rhs.month;
	mt.year = lhs.year - rhs.year;
	mt.hours = lhs.hours - rhs.hours;
	mt.min = lhs.min - rhs.min;

	return mt;
}

bool operator> (const myTime& lhs, const myTime& rhs) {

	

	return tie(lhs.year, lhs.month, lhs.day, lhs.hours, lhs.min) >
		tie(rhs.year, rhs.month, rhs.day, rhs.hours, rhs.min);
}

myTime _GetCurrentTime() {

	// Mon May 2 16:45:31 2022
	time_t rawtime;
	struct tm* timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	string str = asctime(timeinfo);

	string _month;
	int _day, _hours, _min, _year;
	
	stringstream ss(str);

	string trash;
	ss >> trash;
	ss >> _month;
	ss >> _day;
	ss >> _hours;
	ss.ignore(1);
	ss >> _min;
	ss.ignore(3);
	ss >> _year;

	myTime mT;
	mT.day = _day;
	mT.month = MonthToIndex(_month);
	mT.year = _year;
	mT.hours = _hours;
	mT.min = _min;
	return mT;
}

string _intToString(int num) {
	string s = to_string(num);
	if (s.size() == 1) {
		s.push_back(s[0]);
		s[0] = '0';
	}
	return s;
}

myTime _stringToTime(const string& s) {
	stringstream ss(s);
	// 01.02.2022 15:43
	myTime mt;
	ss >> mt.day;
	ss.ignore(1);
	ss >> mt.month;
	ss.ignore(1);
	ss >> mt.year;
	ss >> mt.hours;
	ss.ignore(1);
	ss >> mt.min;
	
	return mt;
}

int MonthToIndex(const string& month) {
	if (month == "Jan") {
		return 1;
	}
	else if (month == "Feb") {
		return 2;
	}
	else if (month == "Mar") {
		return 3;
	}
	else if (month == "Apr") {
		return 4;
	}
	else if (month == "May") {
		return 5;
	}
	else if (month == "Jun") {
		return 6;
	}
	else if (month == "Jul") {
		return 7;
	}
	else if (month == "Aug") {
		return 8;
	}
	else if (month == "Sept") {
		return 9;
	}
	else if (month == "Oct") {
		return 10;
	}
	else if (month == "Nov") {
		return 11;
	}
	else if (month == "Dec") {
		return 12;
	}
}