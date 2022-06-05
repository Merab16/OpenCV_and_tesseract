#pragma once
#include <vector>
#include <map>
#include <fstream>

#pragma once
#include "Item.h"

using namespace std;

//map<string, int> CITY = {
//	{"THETFORD", 0},
//	{"FORT", 1},
//	{"LYMHURST", 2},
//	{"BRIDGEWATCH", 3},
//	{"MARTLOCK", 4},
//	{"CAERLEON", 5},
//};


class DataBase
{

private:
	// ���������� ������ �� ���� �������
	map<_Item, map<int, _Info>> _db;
	// ��������������� ������, �������� � ���� ���. ���� �� ������� � 
	// ���� �� ��
	map<_Item, map<int, _Info>> _db_min_price;
	// ��������������� ������ �� [db_min_price] �� ����������� �������
	map<int, map<_Item, map<int, _Info>>> _db_sorted;

public:

				/// 1. ������������ � �����������
	DataBase();

	~DataBase();
	

				/// 2. ������ � ������ ������
	// �������� �������
	void _AddItem(const _Item& item, int city, const _Info& info);

	
	// �������� ������ � ��������
	void _EditItemPrice(const _Item& item, int city, int new_price);

	// ������������� ������ �� ����������� �������
	void _Sort(int profit);

	// ��������� ���. ���� �� ���� ������� �� �������
	void _Calculate(const set<set<string>>& Items, int city);

	// �������� �� ������� �������� � ����� [List]
	bool _isItemCorrect(const _Item& item, int city) const;

	// �������� ����, ���� ������� ��������
	bool _RefreshPrice(const _Item& item, int city);


			/// 3. ������ � ������� ��� ������ ��� �����
	// ������� ���������� [db]
	void _PrintPrice() const;

	// ������� ���������� [db_min_price]
	void _PrintPrice(int nothing) const;

	// ���������� ������ � ����� ������
	void _SaveData() const;

	// ����������, ����������� ������ � ���������� ������
	// ������ �� �����
	void _ReadData();

			/// 4. ������� � �������

	map<int, map<_Item, map<int, _Info>>> GetDbSorted() const;

	const int GetItemPriceDB(const _Item& item) const ;



};

//void NextCity(CITY& city);


_Item _ParseItem(const string& s);

void SwapOnSpace(string& s);

void SwapOnDash(string& s);

string IndexToCity(int index);

int CityToIndex(const string& city);

double CalcProfit(int b_price, int e_price);

