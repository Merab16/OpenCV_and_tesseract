#include <iostream>
#include <sstream>
#include <fstream>
#include <ctime>
#include <algorithm>
#include <numeric>

#include "MarketAction.h"

using namespace std;

void Check(DataBase& db);
//void CheckC(DataBase& db);
void Sort(DataBase& db);
void Edit(DataBase& db);
void Print(DataBase& db);
void Calc(DataBase& db);
void Buy(DataBase& db, map<_Item, int>& ItemLimit,
	map<_Item, map<int, int>>& item_bought);
void CalcTotalProfit(map<_Item, map<int, int>>& item_bought,
	map<_Item, map<int, int>>& item_sold,
	map<_Item, int>& total_profit);
void PrintTotalProfit(map<_Item, map<int, int>>& item_bought,
	map<_Item, map<int, int>>& item_sold,
	map<_Item, int>& total_profit);


// +1. Переделать сканирования цен везде как на черном рынке
// 2. Через костыль сделана продажа итемов
// 3. Сделать структуру, где будет учитываться качетсво предмета
// 4. Перенести итемы с тиром 3+ в отдельнуый лист, и тиры 2+ - в отдельный
// +5. Пересмотреть функции где есть [Sleep] и оптимизировать 


int main(int argc, char* argv[])
{
	
	DataBase db;
	map<_Item, int> ItemLimit;
	map<_Item, map<int, int>> item_bought;
	map<_Item, map<int, int>> item_sold;
	map<_Item, int> total_profit;
	//int current_city = 0;

	while (true) {
		string command;
		cin >> command;
		if (command == "check") {
			Check(db);
		}
		if (command == "print") {
			Print(db);
		}
		if (command == "printb") {
			PrintBoughtItems(item_bought);
		}
		else if (command == "prints") {
			PrintBoughtItems(item_sold);
		}
		else if (command == "printp") {
			PrintTotalProfit(item_bought, item_sold, total_profit);
		}
		else if (command == "calc") {
			Calc(db);
		}
		else if (command == "sort") {
			Sort(db);
		}
		else if (command == "edit") {
			Edit(db);
		}
		else if (command == "buy") {
			Buy(db, ItemLimit, item_bought);
		}
		else if (command == "sell") {
			SellItem(item_bought, item_sold);
		}
		else if (command == "refresh") {
			RefreshItemPrice();
		}
		else if (command == "exit") {
			break;
		}
	}

	return 0;
}


void Check(DataBase& db) {
	int c;
	bool flag;
	system("cls");
	cout << "Enter [city flag(0 - non-refresh, 1 - refresh)]: ";
	cin >> c >> flag;
	
	_CheckPrice(db, c, flag);
}

/*void CheckC(DataBase& db) {
	bool flag;
	system("cls");
	cout << "Enter [flag(0 - non-refresh, 1 - refresh)]: ";
	cin >> flag;
	
	_CheckPriceC(db, flag);
}*/

void Print(DataBase& db) {
	system("cls");
	db._PrintPrice();
}

void Calc(DataBase& db) {
	
	int city;
	system("cls");
	cout << "Enter [city]: ";
	cin >> city;
	db._Calculate(city);
}

void Sort(DataBase& db) {
	
	int profit = 0;
	system("cls");
	cout << "Enter [profit]: ";
	cin >> profit;
	
	db._Sort(profit);
	db._PrintPrice(0);
}

void Edit(DataBase& db) {
	int city = 0, price = 0;
	string _name, _tier;
	system("cls");
	cout << "Enter [name city price]: ";
	cin >> _name >> _tier;
	_name += ' ' + _tier;

	_Item item = _ParseItem(_name);
	cin >> city >> price;
	
	db._EditItemPrice(item, city, price);
}

void Buy(DataBase& db, map<_Item, int>& ItemLimit,
	map<_Item, map<int, int>>& item_bought) {
	system("cls");
	cout << "Enter profit: ";
	int profit = 0;
	cin >> profit;
	BuyItem(db, ItemLimit, item_bought, profit);
}

void CalcTotalProfit(map<_Item, map<int, int>>& item_bought,
	map<_Item, map<int, int>>& item_sold,
	map<_Item, int>& total_profit) {
	for (const auto& el : item_bought) {
		int b_sum = 0;
		int s_sum = 0;
		for (const auto& item : el.second) {
			b_sum += item.first * item.second;
		}
		for (const auto& item : item_sold[el.first]) {
			s_sum += item.first * item.second;
		}

		total_profit[el.first] = s_sum - b_sum;
	}
}

void PrintTotalProfit(map<_Item, map<int, int>>& item_bought,
	map<_Item, map<int, int>>& item_sold,
	map<_Item, int>& total_profit) {

	CalcTotalProfit(item_bought, item_sold, total_profit);
	system("cls");
	int total = 0;
	for (const auto& el : total_profit) {
		cout << el.first << ": " << el.second << '\n';
		total += el.second;
	}
	cout << "Total: " << total << endl;
}
