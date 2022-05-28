#pragma once
#include <map>
#include <string>

#include "Shapes.h"
#include "MyImg.h"

using namespace std;

const vector<string> vMenu = {

	"Check",
	"Calculate",
	"Sort",

	"Buy",
	"Order",
	"Refresh",

	"RefreshOrders",

	"Print",
	"PrintB",
	"Sell",

	"Categories",
	"Load",
	"Save",

	"Exit",

};

// Не используется
/*const map<string, TB_Info> mMenu = {
	{"Check" , {Vector2f(50, 50), Vector2f(100, 40), 16}},
	{"Calculate" , {Vector2f(200, 50), Vector2f(100, 40), 16}},
	{"Sort" , {Vector2f(350, 50), Vector2f(100, 40), 16}},

	{"Buy" , {Vector2f(50, 100), Vector2f(100, 40), 16}},
	{"Order" , {Vector2f(200, 100), Vector2f(100, 40), 16}},
	{"Refresh" , {Vector2f(350, 100), Vector2f(100, 40), 16}},

	{"Print" , {Vector2f(50, 150), Vector2f(100, 40), 16}},
	{"PrintB" , {Vector2f(200, 150), Vector2f(100, 40), 16}},
	{"Sell" , {Vector2f(350, 150), Vector2f(100, 40), 16}},

	{"Settings" , {Vector2f(50, 200), Vector2f(100, 40), 16}},
	{"Exit" , {Vector2f(200, 200), Vector2f(100, 40), 16}},


	{"Load" , {Vector2f(100, 400), Vector2f(100, 40), 16}},
	{"Save" , {Vector2f(300, 400), Vector2f(100, 40), 16}},
};*/

const map<string, TB_Info> mCheck = {

	{"THETFORD" , {Vector2f(50, 50), Vector2f(150, 40), 16}},
	{"FORT STERLING" , {Vector2f(50, 100), Vector2f(150, 40), 16}},
	{"LYMHURST" , {Vector2f(50, 150), Vector2f(150, 40), 16}},
	{"BRIDGEWATCH" , {Vector2f(50, 200), Vector2f(150, 40), 16}},
	{"MARTLOCK" , {Vector2f(50, 250), Vector2f(150, 40), 16}},
	{"CAERLEON" , {Vector2f(50, 300), Vector2f(150, 40), 16}},
	{"BLACK MARKET" , {Vector2f(50, 350), Vector2f(150, 40), 16}},
	{"BACK" , {Vector2f(50, 400), Vector2f(150, 40), 16}},

};

const map<string, TB_Info> mCalculate = {

	{"THETFORD" , {Vector2f(50, 50), Vector2f(150, 40), 16}},
	{"FORT STERLING" , {Vector2f(50, 100), Vector2f(150, 40), 16}},
	{"LYMHURST" , {Vector2f(50, 150), Vector2f(150, 40), 16}},
	{"BRIDGEWATCH" , {Vector2f(50, 200), Vector2f(150, 40), 16}},
	{"MARTLOCK" , {Vector2f(50, 250), Vector2f(150, 40), 16}},
	{"CAERLEON" , {Vector2f(50, 300), Vector2f(150, 40), 16}},
	
	{"BACK" , {Vector2f(50, 400), Vector2f(150, 40), 16}},

};


//const map<string, MI_Info> mSettings = {
//
//	{"Curse" , Vector2f(40.f, 50.f)},
//	{"Arcane" , Vector2f(115.f, 50.f)},
//	{"Fire" , Vector2f(190.f, 50.f)},
//	{"Frost" , Vector2f(265.f, 50.f)},
//	{"Holy" , Vector2f(340.f, 50.f)},
//	{"Nature" , Vector2f(415.f, 50.f)},
//
//	{"Axe" , Vector2f(40.f, 125.f)},
//	{"Dagger" , Vector2f(115.f, 125.f)},
//	{"Hammer" , Vector2f(190.f, 125.f)},
//	{"Mace" , Vector2f(265.f, 125.f)},
//	{"Bag" , Vector2f(340.f, 125.f)},
//	{"SatchelOfInsight" , Vector2f(415.f, 125.f)},
//	
//	{"Cowl" , Vector2f(40.f, 200.f)},
//	{"Robe" , Vector2f(115.f, 200.f)},
//	{"Sandals" , Vector2f(190.f, 200.f)},
//	{"Hood" , Vector2f(265.f, 200.f)},
//	{"Jacket" , Vector2f(340.f, 200.f)},
//	{"Shoes" , Vector2f(415.f, 200.f)},
//
//	{"Helmet" , Vector2f(40.f, 275.f)},
//	{"Armor" , Vector2f(115.f, 275.f)},
//	{"Boots" , Vector2f(190.f, 275.f)},
//	
//	
//	{"Back" , Vector2f(50.f, 400.f)},
//};

const vector<string> vCategories = {

	"Curse" ,
	"Arcane" ,
	"Fire" ,
	"Frost" ,
	"Holy" ,
	"Nature" ,

	"Axe" ,
	"Dagger" ,
	"Hammer" ,
	"Mace" ,
	"Sword",

	"OffHand",

	"Bag" ,
	"SatchelOfInsight" ,

	"Cowl" ,
	"Robe" ,
	"Sandals" ,

	"Hood" ,
	"Jacket",
	"Shoes" ,

	"Helmet" ,
	"Armor",
	"Boots" ,

	"Back" ,
};




