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
	// Полученные данные со всех городов
	map<_Item, map<int, _Info>> _db;
	// Отсортированные данные, включают в себя мин. цену по городам и 
	// цену на БМ
	map<_Item, map<int, _Info>> _db_min_price;
	// Отсортированные данные из [db_min_price] по необходимой прибыли
	map<int, map<_Item, map<int, _Info>>> _db_sorted;

public:

				/// 1. Конструкторы и Деструкторы
	DataBase();

	~DataBase();
	

				/// 2. Работа с базами данных
	// Добавить предмет
	void _AddItem(const _Item& item, int city, const _Info& info);

	
	// Изменить стоить у предмета
	void _EditItemPrice(const _Item& item, int city, int new_price);

	// Отсортировать данные по необходимой прибыли
	void _Sort(int profit);

	// Вычислить мин. цену из всех городов на предмет
	void _Calculate(const set<set<string>>& Items, int city);

	// Проверка на наличие предмета в спике [List]
	bool _isItemCorrect(const _Item& item, int city) const;

	// Обновить цену, если прошлая устарела
	bool _RefreshPrice(const _Item& item, int city);


			/// 3. Работа с данными для вывода или ввода
	// Вывести содержимое [db]
	void _PrintPrice() const;

	// Вывести содержимое [db_min_price]
	void _PrintPrice(int nothing) const;

	// Сохранение данных в конце сеанса
	void _SaveData() const;

	// Считывание, сохраненных данных с последнего сеанса
	// данных из файла
	void _ReadData();

			/// 4. Сеттеры и Геттеры

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

