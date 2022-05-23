#include "../Headers/Game.h"

// mSettings support variables
map<string, bool> mIsImageSelected;


Game::Game()
{	
	LOG_DURATION("Load took: ");
	initWindow();
	InitEvent();
	InitFont();
	InitTextVar();
	InitMousePos();
	InitVecTB(vTB_menu, mMenu);
	InitVecTB(vTB_check, mCheck);
	InitVecTB(vTB_calculate, mCalculate);
	InitVecMI(vMI_settings, mSettings);
	InitBackground();
	InitDataBase();
}

Game::~Game()
{
	LOG_DURATION("Delete took: ");
	while (!wnd_stack.empty()) {
		delete wnd_stack.top();
		wnd_stack.pop();
	}

	DeleteVecMI(vMI_settings);

	DeleteVecTB(vTB_check);
	DeleteVecTB(vTB_calculate);
	DeleteVecTB(vTB_menu);
	DeleteDataBase();
	DeleteEvent();
	DeleteVersion();
	DeleteBackground();

	
}


// Init functions

void Game::initWindow()
{
	cout << "initWindow\n";
	window = new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "myGame", sf::Style::Close);
	
	window->setFramerateLimit(60);
	window->setVerticalSyncEnabled(false);
	wnd_stack.push(window);
}

void Game::InitEvent() {
	cout << "InitEvent\n";
	sfEvent = new Event;
}

void Game::InitFont() {
	cout << "InitFont\n";
	if (!font.loadFromFile("fonts/CascadiaCode.ttf")) {
		cout << "Font error!\n";
	}
}

void Game::InitMousePos() {
	cout << "InitMousePos\n";
	mousePos.setFont(font);
	mousePos.setCharacterSize(10);
	mousePos.setFillColor(Color::Green);
}

void Game::InitTextVar() {
	// FPS
	cout << "InitTextVar\n";
	fps.setFont(font);
	fps.setCharacterSize(12);
	fps.setFillColor(Color::White);
	fps.setPosition(Vector2f(5.f, 5.f));

	
	InitVersion();

}

void Game::InitVecTB(vector<TextBox*>& TB,
	const map<string, TB_Info> m) {
	cout << "InitVecTB\n";
	RectangleShape rect;
	Text text;

	for (const auto& el : m) {
		EmptyBox(rect, el.second.pos, el.second.size);
		CreateText(text, el.second.pos, font, el.first, el.second.font_size);
		TB.push_back(new TextBox( rect, text ));
	}
}

void Game::InitVecMI(vector<MyImg*>& MI,
	const map<string, MI_Info> m) {
	cout << "InitVecMI\n";
	for (const auto& el : m) {
		MyImg* img = new MyImg(el.first, el.second.pos);
		MI.push_back(img);
	}

}


void Game::InitBackground() {
	cout << "InitBackground\n";
	background = new MyImg("Backgrnd", { -100, -20 });
	background->sprite.setScale({ 0.8f, 0.8f });
	
}

void Game::InitDataBase() {
	cout << "InitDataBase\n";
	db = new DataBase;
}

void Game::InitVersion() {
	cout << "InitVersion\n";
	version = new Text;
	version->setFont(font);
	version->setString("Version 0.2.0");
	version->setCharacterSize(12);
	version->setPosition({ 5, 480 });
}

// Delete 

void Game::DeleteBackground() {
	cout << "DeleteBackground\n";
	delete background;
}

void Game::DeleteVecMI(vector<MyImg*>& MI) {
	cout << "DeleteVecMI\n";
	for (const auto& el : MI) {
		delete el;
	}
}

void Game::DeleteVecTB(vector<TextBox*>& MI) {
	cout << "DeleteVecTB\n";
	for (const auto& el : MI) {
		delete el;
	}
}

void Game::DeleteDataBase() {
	cout << "DeleteDataBase\n";
	delete db;
}

void Game::DeleteEvent() {
	cout << "DeleteEvent\n";
	delete sfEvent;
}

void Game::DeleteVersion() {
	cout << "DeleteVersion\n";
	delete version;
}


// Functions 
string Game::isButtonClicked(const vector<TextBox*>& TB) {

	for (const auto& el : TB) {
		IntRect rect(
			int(el->GetRect().getPosition().x),
			int(el->GetRect().getPosition().y),
			int(el->GetRect().getSize().x),
			int(el->GetRect().getSize().y));
		if (rect.contains(mPosX, mPosY)) {
			//cout << string(el.GetText().getString()) << '\n';
			return string(el->GetText().getString());
		}
	}

	return "";

}

string Game::isButtonClicked(const vector<MyImg*>& MI) {
	for (const auto& el : MI) {
		if (el->sprite.getGlobalBounds().contains(mPosX, mPosY)) {

			//cout << el->category << "\n";
			return el->category;
		}
	}

	return "";
}

void Game::isButtonHover(vector<TextBox*>& TB) {
	for (auto& el : TB) {
		IntRect rect(
			int(el->GetRect().getPosition().x),
			int(el->GetRect().getPosition().y),
			int(el->GetRect().getSize().x),
			int(el->GetRect().getSize().y));
		if (rect.contains(mPosX, mPosY)) {
			el->GetRect().setOutlineColor(Color::Yellow);
			el->GetText().setFillColor(Color::Yellow);
		}
		else {
			el->GetRect().setOutlineColor(Color::White);
			el->GetText().setFillColor(Color::White);
		}

	}
}

void Game::MenuConroller(const string& command) {
	system("cls");
	//cout << command << '\n';
	if (command == "Check") {
		current_wnd = command;
	}
	else if (command == "Calculate") {
		current_wnd = command;
		
	}
	else if (command == "Sort") {
		current_wnd = "EnterWndS";	
	}
	else if (command == "Buy") {
		current_wnd = "EnterWndB";
	}
	else if (command == "Refresh") {
		RefreshItemPrice();
	}
	else if (command == "Print") {
		db->_PrintPrice();
	}
	else if (command == "PrintB") {
		PrintBoughtItems(item_bought);
	}
	else if (command == "Settings") {
		current_wnd = command;
	}
	else if (command == "Sell") {
		SellItem(item_bought, item_sold);
	}
	else if (command == "Save") {
		db->_SaveData();
	}
	else if (command == "Load") {
		db->_ReadData();
	}
	else if (command == "Exit") {
		wnd_stack.top()->close();
	}
}

void Game::CheckConroller(const string& command) {
	if (command == "THETFORD") {

		_CheckPrice(*db, selected_categories, 0, 1);
		
	}
	else if (command == "FORT STERLING") {
		
		_CheckPrice(*db, selected_categories, 1, 1);
		
	}
	else if (command == "LYMHURST") {
		
		_CheckPrice(*db, selected_categories, 2, 1);
		
	}
	else if (command == "BRIDGEWATCH") {
		
		_CheckPrice(*db, selected_categories, 3, 1);
		
	}
	else if (command == "MARTLOCK") {
		
		_CheckPrice(*db, selected_categories, 4, 1);
		
	}
	else if (command == "CAERLEON") {
		
		_CheckPrice(*db, selected_categories, 5, 1);
		
	}
	else if (command == "BLACK MARKET") {
		
		_CheckPrice(*db, selected_categories, 6, 1);
		
	}
	else if (command == "BACK") {
		current_wnd = "Menu";
	}
}

void Game::CalculateController(const string& command) {
	if (command == "THETFORD") {
		db->_Calculate(selected_categories, 0);
	}
	else if (command == "FORT STERLING") {
		db->_Calculate(selected_categories, 1);
		current_wnd = "Menu";
	}
	else if (command == "LYMHURST") {
		db->_Calculate(selected_categories, 2);
		current_wnd = "Menu";
	}
	else if (command == "BRIDGEWATCH") {
		db->_Calculate(selected_categories, 3);
		current_wnd = "Menu";
	}
	else if (command == "MARTLOCK") {
		db->_Calculate(selected_categories, 4);
		current_wnd = "Menu";
	}
	else if (command == "CAERLEON") {
		db->_Calculate(selected_categories, 5);
		current_wnd = "Menu";
	}
	else if (command == "BACK") {
		current_wnd = "Menu";
	}
}

void Game::SortController() {
	db->_Sort(stoi(_profit));
	db->_PrintPrice(0);

}

void Game::BuyController() {
	BuyItem(*db, selected_categories, ItemLimit, item_bought, stoi(_profit));
}


void Game::SettingsController(const string& command) {
	if (command == "Axe") {
		if (mIsImageSelected[command]) {
			selected_categories.erase(Axe);
			mIsImageSelected[command] = 0;
		}
		else {
			selected_categories.insert(Axe);
			mIsImageSelected[command] = 1;
		}

	}
	else if (command == "Curse") {
		if (mIsImageSelected[command]) {
			selected_categories.erase(Curse);
			mIsImageSelected[command] = 0;
		}
		else {
			selected_categories.insert(Curse);
			mIsImageSelected[command] = 1;
		}
	}
	else if (command == "Arcane") {
		if (mIsImageSelected[command]) {
			selected_categories.erase(Arcane);
			mIsImageSelected[command] = 0;
		}
		else {
			selected_categories.insert(Arcane);
			mIsImageSelected[command] = 1;
		}
	}
	else if (command == "Fire") {
		if (mIsImageSelected[command]) {
			selected_categories.erase(Fire);
			mIsImageSelected[command] = 0;
		}
		else {
			selected_categories.insert(Fire);
			mIsImageSelected[command] = 1;
		}
	}
	else if (command == "Frost") {
		if (mIsImageSelected[command]) {
			selected_categories.erase(Frost);
			mIsImageSelected[command] = 0;
		}
		else {
			selected_categories.insert(Frost);
			mIsImageSelected[command] = 1;
		}
	}
	else if (command == "Holy") {
		if (mIsImageSelected[command]) {
			selected_categories.erase(Holy);
			mIsImageSelected[command] = 0;
		}
		else {
			selected_categories.insert(Holy);
			mIsImageSelected[command] = 1;
		}
	}
	else if (command == "Nature") {
		if (mIsImageSelected[command]) {
			selected_categories.erase(Nature);
			mIsImageSelected[command] = 0;
		}
		else {
			selected_categories.insert(Nature);
			mIsImageSelected[command] = 1;
		}
	}
	else if (command == "Dagger") {
		if (mIsImageSelected[command]) {
			selected_categories.erase(Dagger);
			mIsImageSelected[command] = 0;
		}
		else {
			selected_categories.insert(Dagger);
			mIsImageSelected[command] = 1;
		}
	}
	else if (command == "Hammer") {
		if (mIsImageSelected[command]) {
			selected_categories.erase(Hammer);
			mIsImageSelected[command] = 0;
		}
		else {
			selected_categories.insert(Hammer);
			mIsImageSelected[command] = 1;
		}
	}
	else if (command == "Mace") {
		if (mIsImageSelected[command]) {
			selected_categories.erase(Mace);
			mIsImageSelected[command] = 0;
		}
		else {
			selected_categories.insert(Mace);
			mIsImageSelected[command] = 1;
		}
	}
	else if (command == "Robe") {
		if (mIsImageSelected[command]) {
			selected_categories.erase(Robe);
			mIsImageSelected[command] = 0;
		}
		else {
			selected_categories.insert(Robe);
			mIsImageSelected[command] = 1;
		}
	}
	else if (command == "Cowl") {
		if (mIsImageSelected[command]) {
			selected_categories.erase(Cowl);
			mIsImageSelected[command] = 0;
		}
		else {
			selected_categories.insert(Cowl);
			mIsImageSelected[command] = 1;
		}
	}
	else if (command == "SatchelOfInsight") {
		if (mIsImageSelected[command]) {
			selected_categories.erase(SatchelOfInsight);
			mIsImageSelected[command] = 0;
		}
		else {
			selected_categories.insert(SatchelOfInsight);
			mIsImageSelected[command] = 1;
		}
	}
	else if (command == "Sandals") {
		if (mIsImageSelected[command]) {
			selected_categories.erase(Sandals);
			mIsImageSelected[command] = 0;
		}
		else {
			selected_categories.insert(Sandals);
			mIsImageSelected[command] = 1;
		}
	}
	else if (command == "Bag") {
		if (mIsImageSelected[command]) {
			selected_categories.erase(Bag);
			mIsImageSelected[command] = 0;
		}
		else {
			selected_categories.insert(Bag);
			mIsImageSelected[command] = 1;
		}
	}
	else if (command == "Boots") {
		if (mIsImageSelected[command]) {
			selected_categories.erase(Boots);
			mIsImageSelected[command] = 0;
		}
		else {
			selected_categories.insert(Boots);
			mIsImageSelected[command] = 1;
		}
	}
	else if (command == "Shoes") {
		if (mIsImageSelected[command]) {
			selected_categories.erase(Shoes);
			mIsImageSelected[command] = 0;
		}
		else {
			selected_categories.insert(Shoes);
			mIsImageSelected[command] = 1;
		}
	}
	else if (command == "Armor") {
		if (mIsImageSelected[command]) {
			selected_categories.erase(Armor);
			mIsImageSelected[command] = 0;
		}
		else {
			selected_categories.insert(Armor);
			mIsImageSelected[command] = 1;
		}
	}
	else if (command == "Jacket") {
		if (mIsImageSelected[command]) {
			selected_categories.erase(Jacket);
			mIsImageSelected[command] = 0;
		}
		else {
			selected_categories.insert(Jacket);
			mIsImageSelected[command] = 1;
		}
	}
	else if (command == "Helmet") {
		if (mIsImageSelected[command]) {
			selected_categories.erase(Helmet);
			mIsImageSelected[command] = 0;
		}
		else {
			selected_categories.insert(Helmet);
			mIsImageSelected[command] = 1;
		}
	}
	else if (command == "Hood") {
		if (mIsImageSelected[command]) {
			selected_categories.erase(Hood);
			mIsImageSelected[command] = 0;
		}
		else {
			selected_categories.insert(Hood);
			mIsImageSelected[command] = 1;
		}
	}
	else if (command == "Back") {
		current_wnd = "Menu";
	}
}



void Game::EnterToWindow() {
	
	if (sfEvent->key.code == Keyboard::Escape) {
		wnd_stack.top()->close();
	}
	if (current_wnd == "EnterWndS" || current_wnd == "EnterWndB") {
		
		if (sfEvent->key.code == Keyboard::Num0) {
			_profit += '0';
		}
		else if (sfEvent->key.code == Keyboard::Num1) {
			_profit += '1';
		}
		else if (sfEvent->key.code == Keyboard::Num2) {
			_profit += '2';
		}
		else if (sfEvent->key.code == Keyboard::Num3) {
			_profit += '3';
		}
		else if (sfEvent->key.code == Keyboard::Num4) {
			_profit += '4';
		}
		else if (sfEvent->key.code == Keyboard::Num5) {
			_profit += '5';
		}
		else if (sfEvent->key.code == Keyboard::Num6) {
			_profit += '6';
		}
		else if (sfEvent->key.code == Keyboard::Num7) {
			_profit += '7';
		}
		else if (sfEvent->key.code == Keyboard::Num8) {
			_profit += '8';
		}
		else if (sfEvent->key.code == Keyboard::Num9) {
			_profit += '9';
		}
		else if (sfEvent->key.code == Keyboard::Backspace) {
			if (_profit.size() > 0)
				_profit.erase(_profit.size() - 1);
		}
		else if (sfEvent->key.code == Keyboard::Enter) {
			
			if (current_wnd == "EnterWndS") {
				SortController();
			}
			else if (current_wnd == "EnterWndB") {
				BuyController();	
			}
			current_wnd = "Menu";
			_profit = "";
		}
	}
	
	
}





// Run
void Game::run()
{
	while (wnd_stack.top()->isOpen())
	{
		updateDt();
		update();
		render();
	}
}

// Update

void Game::update()
{
	updateMousePos();
	updateSFMLEvents();

}

void Game::updateSFMLEvents()
{
	while (wnd_stack.top()->pollEvent(*sfEvent))
	{
		switch (sfEvent->type) {
		case Event::Closed:
			wnd_stack.top()->close();
			break;
		case Event::KeyPressed:
			EnterToWindow();
			break;

		case Event::MouseButtonPressed:
			if (current_wnd == "Menu") {
				MenuConroller(isButtonClicked(vTB_menu));
			}
			else if (current_wnd == "Check") {
				CheckConroller(isButtonClicked(vTB_check));
			}
			else if (current_wnd == "Calculate") {
				CalculateController(isButtonClicked(vTB_calculate));
			}

			else if (current_wnd == "Settings") {
				SettingsController(isButtonClicked(vMI_settings));
			}
			break;
			
	


		}

	}
}

void Game::updateDt() {
	this->dt = this->dtClock.restart().asSeconds();
	fps.setString("FPS: " + to_string(int(1 / dt)));

}

void Game::updateMousePos()
{
	mPosX = Mouse::getPosition(*wnd_stack.top()).x;
	mPosY = Mouse::getPosition(*wnd_stack.top()).y;
	mousePos.setString(std::to_string(mPosX) + ';' + std::to_string(mPosY));
	mousePos.setPosition(mPosX, mPosY - 20);
}


// Render

void Game::render()
{
	wnd_stack.top()->clear();



	wnd_stack.top()->draw(background->sprite);

	if (current_wnd == "Menu") {
		drawTB(vTB_menu);
		isButtonHover(vTB_menu);
	}
	else if (current_wnd == "Check" ) {
		drawTB(vTB_check);
		isButtonHover(vTB_check);
	}
	else if (current_wnd == "Calculate") {
		drawTB(vTB_calculate);
		isButtonHover(vTB_calculate);
	}
	else if (current_wnd == "Settings") {
		drawMI(vMI_settings);
	}
	else if (current_wnd == "EnterWndS" || current_wnd == "EnterWndB") {
		drawEnterWnd();
	}
	

	//Loading();

	wnd_stack.top()->draw(mousePos);
	wnd_stack.top()->draw(fps);
	drawVersion();

	wnd_stack.top()->display();
}

void Game::drawTB(const vector<TextBox*>& TB) {
	for (const auto& el : TB) {
		el->Draw(*wnd_stack.top());
	}
}

void Game::drawMI(const vector<MyImg*>& MI) {
	for (const auto& el : MI) {
		wnd_stack.top()->draw(el->sprite);
		if (mIsImageSelected[el->category]) {
			wnd_stack.top()->draw(
				CreateFrame(el->sprite.getPosition(),
					Vector2f(el->sprite.getGlobalBounds().width,
						el->sprite.getGlobalBounds().height))
			);

		}
	}


}

void Game::drawEnterWnd() {

	RectangleShape rect;
	Text tx;
	Vector2f pos(100, 100);
	Vector2f size(150, 50);
	CreateText(tx, pos, font, _profit, 24);
	EmptyBox(rect, pos, size);

	TextBox new_tb(rect, tx);

	new_tb.Draw(*wnd_stack.top());

}

void Game::drawVersion() {
	wnd_stack.top()->draw(*version);
}


//////////////
void EnterToConsole(int& var) {
	cin >> var;
}