#pragma once
#include "DataBase.h"
#include "profile.h"
#include "MoveToPosition.h"
#include "ScreenCapture.h"
#include "MyTime.h"

#pragma once
#include <Windows.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include "numeric"


using namespace std;
using namespace cv;

void _CheckPrice(DataBase& db, const set<set<string>>& Items,
	int city, bool flag);

//void _CheckPriceC(DataBase& db, bool flag);

bool CheckList(const set <string>& List, const string& _name);

int _ParsePrice(const string& str);

int ParseFromImg(const ScreenShot& s_info, string txt_name);

bool CheckItemLimit(int tier, int enchant, int size_now);

void PrintItemLimit(map<_Item, int>& ItemLimit);

void PrintBoughtItems(map<_Item, map<int, int>>& item_bought);

void RefreshItemPrice();

void BuyItem(DataBase& db, const set<set<string>>& Items,
	map<_Item, int>& ItemLimit,
	map<_Item, map<int, int>>& item_bought, int profit);

void SellItem(int count);

void OrderItem(DataBase& db, const set<set<string>>& Items);

void RefreshOrder();