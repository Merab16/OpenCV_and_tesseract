#include "../Headers/DataBase.h"



/// 1.
DataBase::DataBase() {
	
}

DataBase::~DataBase() {
	
}


/// 2.
void DataBase::_AddItem(const _Item& item, int city, const _Info& info) {
	_db[item][city] = info;
}

void DataBase::_EditItemPrice(const _Item& item, int city, int new_price) {
	_db[item][city].price = new_price;
	_db[item][city].time = _GetCurrentTime();
}

void DataBase::_Sort(int profit) {
	if (!_db_min_price.empty()) {
		_db_sorted.clear();

		for (const auto& el : _db_min_price) {
			vector<int> prices{};
			for (const auto& item : el.second) {
				prices.push_back(item.second.price);
			}
			int _profit = CalcProfit(prices[0], prices[1]);
			if (_profit >= profit) {
				_db_sorted[_profit].insert(el);
			}
		}
	}
	else {
		cout << "Need calculate\n";
	}
}

void DataBase::_Calculate(const set<set<string>>& Items, int city) {
	if (Items.empty()) {
		system("cls");
		cout << "Choose items!\n";
	}
	else {
		_db_min_price.clear();
		for (const auto& item : Items) {
			for (const auto& el : item) {
				_Item item = _ParseItem(el);
				_db_min_price[item][city].price = _db[item][city].price;
				_db_min_price[item][6].price = _db[item][6].price;
			}
		}
	}
}

bool DataBase::_isItemCorrect(const _Item& item, int city) const {
	if (_db.count(item) && _db.at(item).count(city)) {
		if (_db.at(item).at(city).price != -1) {
			return true;
		}
	}
	return false;
}

bool DataBase::_RefreshPrice(const _Item& item, int city) {
	myTime mt;
	mt.min = 5;
	if (_GetCurrentTime() - _db[item][city].time > mt) {
		return true;
	}
	return false;
}


/// 3.
void DataBase::_PrintPrice() const  {
	system("cls");
	if (!_db.empty()) {
		for (const auto& el : _db) {
			cout << "\t" << el.first << ":\n";
			for (const auto& item : el.second) {
				cout << IndexToCity(item.first)
					<< ":\t" << item.second.price << '\t'
					<< item.second.time << endl;
			}
		}
	}
	else {
		cout << "Empty, you need to scan market!\n";
	}
}

void DataBase::_PrintPrice(int nothing) const {

	for (auto _it = _db_sorted.rbegin(); _it != _db_sorted.rend(); ++_it) {
		for (const auto& el : _it->second) {
			cout << "\t" << el.first << endl;
			vector<int> prices{};
			for (const auto& item : el.second) {
				prices.push_back(item.second.price);
				cout << IndexToCity(item.first) << ":\t" << item.second.price << endl;
			}
			cout << "Profit: " << _it->first << '%' << endl;
		}
	}
}

void DataBase::_SaveData() const {
	ofstream fout("_save_data.txt");

	for (const auto& el : _db) {

		string _name = el.first.name;
		SwapOnDash(_name);
		fout << '\t' << '[' << _name << "] " << el.first.tier << '.'
			<< el.first.enchant << '\n';
		for (const auto& item : el.second) {
			fout << IndexToCity(item.first) << ": " << item.second.price <<
				"\t{" << item.second.time << '}' << '\n';
		}

	}

	fout.close();
	cout << "Data has been saved\n";
}

void DataBase::_ReadData() {
	//int counter = 0;
	ifstream fin("_save_data.txt");
	string str{};

	_Item item;
	_Info info;

	while (getline(fin, str)) {
		auto it_b = find(str.begin(), str.end(), '[');
		if (it_b != str.end()) {
			auto it_e = find(str.begin(), str.end(), ']');
			string name(it_b + 1, it_e);
			SwapOnSpace(name);
			string _tier(it_e + 2, it_e + 3);
			int tier = stoi(_tier);
			string _enchant(it_e + 4, str.end());
			int enchant = stoi(_enchant);

			item.name = name;
			item.tier = tier;
			item.enchant = enchant;
			//++counter;
			//cout << "Added: " << counter << endl;
		}
		else {
			auto it = find(str.begin(), str.end(), ':');
			string _city(str.begin(), it);
			int city = CityToIndex(_city);
			auto it_t = find(str.begin(), str.end(), '{');
			string _price(it + 2, it_t);
			int price = stoi(_price);

			// [Fort]: 1200		{01.02.2022 15:43}

			string _time(it_t + 1, str.end());
			myTime mt = _stringToTime(_time);

			info.price = price;
			info.time = mt;

			_db[item][city] = info;
		}
	}


	fin.close();
	cout << "Data has been loaded\n";
}


/// 4.
map<int, map<_Item, map<int, _Info>>> DataBase::GetDbSorted() const {
	return _db_sorted;
}





_Item _ParseItem(const string& s) {
	stringstream ss(s);
	string itemName{};
	int tier = 0, enchant = 0;

	ss >> itemName;
	ss.ignore(1);
	ss >> tier;
	ss.ignore(1);
	ss >> enchant;
	SwapOnSpace(itemName);

	_Item item;
	item.name = itemName;
	item.tier = tier;
	item.enchant = enchant;

	return item;
}

void SwapOnSpace(string& s) {
	for (auto& el : s) {
		if (el == '-') {
			el = ' ';
		}
	}
}

void SwapOnDash(string& s) {
	for (auto& el : s) {
		if (el == ' ') {
			el = '-';
		}
	}
}

string IndexToCity(int index) {
	switch (index) {
	case 0:
		return "THETFORD";
	case 1:
		return "FORTSTERLING";
	case 2:
		return "LYMHURST";
	case 3:
		return "BRIDGEWATCH";
	case 4:
		return "MARTLOCK";
	case 5:
		return "CAERLEON";
	case 6:
		return "BLACKMARKET";
	}
}

int CityToIndex(const string& city) {
	if (city == "THETFORD") {
		return 0;
	} 
	else if (city == "FORTSTERLING") {
		return 1;
	}
	else if (city == "LYMHURST") {
		return 2;
	}
	else if (city == "BRIDGEWATCH") {
		return 3;
	}
	else if (city == "MARTLOCK") {
		return 4;
	}
	else if (city == "CAERLEON") {
		return 5;
	}
	else if (city == "BLACKMARKET") {
		return 6;
	}
}

double CalcProfit(int b_price, int e_price) {
	return (e_price - b_price) * 1.0 / b_price * 100;
}

