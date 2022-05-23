#pragma once
#include <string>
#include <tuple>
#include <map>



#pragma once
#include "MyTime.h"
#include "Items.h"


using namespace std;

struct _Item
{
	string name;
	int tier;
	int enchant;

	
};

struct _Info {
	myTime time;
	int price;
};


bool operator< (const _Item& lhs, const _Item& rhs);

bool operator== (const _Item& lhs, const _Item& rhs);

bool operator> (const _Item& lhs, const _Item& rhs);

ostream& operator<< (ostream& os, const _Item& item);



