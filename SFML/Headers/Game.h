#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include <sstream>
#include <fstream>
#include <ctime>
#include <algorithm>
#include <numeric>
#include <stack>

#include "MarketAction.h"
#include "Config.h"
//#include "Shapes.h"
#include "Menus.h"


using namespace std;
using namespace sf;






class Game
{
private:
	// Variables

	// Window
	stack<RenderWindow*> wnd_stack;
	RenderWindow* window;
	Event* sfEvent;
	string current_wnd = "Menu";

	// Background
	MyImg* background;
	
	
	// DataBase
	DataBase* db;

	// Support Variables for Bying Procces
	map<_Item, int> ItemLimit;
	map<_Item, map<int, int>> item_bought;
	map<_Item, map<int, int>> item_sold;
	map<_Item, int> total_profit;


	// Mouse
	Text mousePos;
	int mPosX;
	int mPosY;

	// Clock 
	Clock dtClock;
	float dt;
	Text fps;

	
	// Font
	Font font;

	// Main Menu
	vector<TextBox*>	vTB_menu;

	// Check Menu
	vector<TextBox*>	vTB_check;

	// Calculate Menu
	vector<TextBox*>	vTB_calculate;

	// Settings
	vector<MyImg*> vMI_settings;

	// EnterWnd
	string _profit = "";

	// Version
	Text* version;



	// Selected categories
	set<set<string>> selected_categories;



	// Init functions
	void initWindow();
	void InitEvent();
	void InitMousePos();
	void InitFont();
	void InitTextVar();
	void InitVecTB(vector<TextBox*>& TB,
		const map<string, TB_Info> m);
	void InitVecMI(vector<MyImg*>& MI,
		const map<string, MI_Info> m);
	void InitVecLoading();
	void InitBackground();
	void InitDataBase();
	void InitVersion();


	// Delete

	void DeleteBackground();
	void DeleteVecMI(vector<MyImg*>& MI);
	void DeleteVecTB(vector<TextBox*>& MI);
	void DeleteDataBase();
	void DeleteEvent();
	void DeleteVersion();


public:
	// Constr&Destr
	Game();
	virtual ~Game();

	// Functions 
	string isButtonClicked(const vector<TextBox*>& TB);
	string isButtonClicked(const vector<MyImg*>& MI);

	void isButtonHover(vector<TextBox*>& TB);

	void MenuConroller(const string& command);
	void CalculateController(const string& command);
	void CheckConroller(const string& command);
	void SortController();
	void BuyController();
	void SettingsController(const string& command);
	
	void EnterToWindow();
	

	// Run
	void run();

	// Update
	void update();
	void updateSFMLEvents();
	void updateDt();
	void updateMousePos();

	// render
	void render();
	void drawTB(const vector<TextBox*>& TB);
	void drawMI(const vector<MyImg*>& MI);
	void drawEnterWnd();
	void drawVersion();
	
	


	

	
	

};

///////////////////////
void EnterToConsole(int& var);
