#include "../Headers/MoveToPosition.h"
#include "../Headers/Config.h"

MyConfig Config;


// Coordinates of position all the tier items; 
// Tier 1 = (X, Y);
map<int, pair<int, int>> TierPosition = {
	{1, {950, 325}},
	{2, {950, 353}},
	{3, {950, 379}},
	{4, {950, 407}},
	{5, {950, 434}},
	{6, {950, 460}},
	{7, {950, 488}},
	{8, {950, 515}}
};

map<int, pair<int, int>> TierPositionC = {
	{4, {500, 428}},
	{5, {500, 455}},
	{6, {500, 482}},
	{7, {500, 509}},
	{8, {500, 535}},
	{9, {500, 563}},
	{10, {500, 590}},
	{11, {500, 617}},
};

// Coordinates of position all the enchant items; 
// Enchant 1 = (X, Y);
map<int, pair<int, int>> EnchantPosition = {
	{0, {1100, 325}},
	{1, {1100, 340}},
	{2, {1100, 379}},
	{3, {1100, 407}}
};

map<int, pair<int, int>> EnchantPositionC = {
	{0, {675, 428}},
	{1, {675, 455}},
	{2, {675, 482}},
	{3, {675, 509}},
};

// Coordinates of position all the quality items; 
// Enchant 1 = (X, Y);
map<int, pair<int, int>> QualityPosition = {
	{0, {1235, 298}},
	{1, {1235, 325}},
	{2, {1235, 353}},
	{3, {1235, 379}},
	{4, {1235, 407}},
	{5, {1235, 434}},
};



// Mouse and Keyboard Events
void MouseLeftClick() {
	Sleep(120);
	INPUT Inputs[1] = { 0 };

	Inputs[0].type = INPUT_MOUSE;
	Inputs[0].mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
	UINT uSent = SendInput(ARRAYSIZE(Inputs), Inputs, sizeof(INPUT));
	if (uSent != ARRAYSIZE(Inputs))
	{
		printf("SendInput failed: 0x%x\n", HRESULT_FROM_WIN32(GetLastError()));
	}

	Sleep(100);
	Inputs[0].type = INPUT_MOUSE;
	Inputs[0].mi.dwFlags = MOUSEEVENTF_LEFTUP;
	uSent = SendInput(ARRAYSIZE(Inputs), Inputs, sizeof(INPUT));
	if (uSent != ARRAYSIZE(Inputs))
	{
		printf("SendInput failed: 0x%x\n", HRESULT_FROM_WIN32(GetLastError()));
	}
	Sleep(100);
}

void KeyBrdBtnPress(char lt) {
	INPUT inputs[1] = {};
	inputs[0].type = INPUT_KEYBOARD;

	inputs[0].ki.wVk = 0;
	inputs[0].ki.dwFlags = KEYEVENTF_UNICODE;
	inputs[0].ki.wScan = lt;
	UINT uSent = SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));

	if (uSent != ARRAYSIZE(inputs))
	{
		printf("SendInput failed: 0x%x\n", HRESULT_FROM_WIN32(GetLastError()));
	}
	Sleep(100);
}

// Move to Positiopns
void MoveToInsertName() {
	SetCursorPos(Config.ScreenScale.first * 650, Config.ScreenScale.second * 270);
	MouseLeftClick();
}

void MoveToTier(int tier) {
	SetCursorPos(Config.ScreenScale.first * 950, Config.ScreenScale.second * 270);
	MouseLeftClick();
	SetCursorPos(Config.ScreenScale.first * TierPosition[tier].first, Config.ScreenScale.second * TierPosition[tier].second);
	MouseLeftClick();
}

void MoveToTierC(int tier) {
	SetCursorPos(Config.ScreenScale.first * 520, Config.ScreenScale.second * 400);
	MouseLeftClick();
	SetCursorPos(Config.ScreenScale.first * TierPositionC[tier].first, Config.ScreenScale.second * TierPositionC[tier].second);
	MouseLeftClick();
}

void MoveToEnchant(int enchant) {
	SetCursorPos(Config.ScreenScale.first * 1100, Config.ScreenScale.second * 270);
	MouseLeftClick();
	SetCursorPos(Config.ScreenScale.first * EnchantPosition[enchant].first, Config.ScreenScale.second * EnchantPosition[enchant].second);
	MouseLeftClick();
}

void MoveToEnchantC(int enchant) {
	SetCursorPos(Config.ScreenScale.first * 670, Config.ScreenScale.second * 400);
	MouseLeftClick();
	SetCursorPos(Config.ScreenScale.first * EnchantPositionC[enchant].first, Config.ScreenScale.second * EnchantPositionC[enchant].second);
	MouseLeftClick();
}

void MoveToQuality(int qual) {
	SetCursorPos(Config.ScreenScale.first * 1230, Config.ScreenScale.second * 270);
	MouseLeftClick();
	SetCursorPos(Config.ScreenScale.first * QualityPosition[qual].first, Config.ScreenScale.second * QualityPosition[qual].second);
	MouseLeftClick();
}

void ClearItemName() {
	SetCursorPos(Config.ScreenScale.first * 722, Config.ScreenScale.second * 270);
	MouseLeftClick();
}

void MoveToBuy() {
	SetCursorPos(Config.ScreenScale.first * 1280, Config.ScreenScale.second * 430);
	MouseLeftClick();
}

void MoveToBuy2() {
	SetCursorPos(Config.ScreenScale.first * 885, Config.ScreenScale.second * 735);
	MouseLeftClick();
}

void MoveToEdit() {
	SetCursorPos(Config.ScreenScale.first * 1230, Config.ScreenScale.second * 410);
	MouseLeftClick();
}

void MoveToEditPrice() {
	SetCursorPos(Config.ScreenScale.first * 635, Config.ScreenScale.second * 635);
	MouseLeftClick();
}

void UpdateOrder() {
	SetCursorPos(Config.ScreenScale.first * 875, Config.ScreenScale.second * 735);
	MouseLeftClick();
}

void CloseGameWindow() {
	// Нажатие, чтобы закрыть окно (если открыто)
	SetCursorPos(Config.ScreenScale.first * 937, Config.ScreenScale.second * 310);
	MouseLeftClick();
}

void SellBtn() {
	// Кнопка продать
	SetCursorPos(Config.ScreenScale.first * 1280, Config.ScreenScale.second * 430);
	MouseLeftClick();
}

void ClickSellTab() {
	SetCursorPos(Config.ScreenScale.first * 1385, Config.ScreenScale.second * 415);
	MouseLeftClick();
}

void ClickBuyTab() {
	SetCursorPos(Config.ScreenScale.first * 1385, Config.ScreenScale.second * 335);
	MouseLeftClick();
}

void PriceMinusOneSilver() {
	SetCursorPos(Config.ScreenScale.first * 563, Config.ScreenScale.second * 635);
	MouseLeftClick();
}

void PricePlusOneSilver() {
	// Нажатие на +1 серебро для ордера
	SetCursorPos(862, 635);
	MouseLeftClick();
}

void ChooseCountOrder() {
	// Выбираем количество 
	SetCursorPos(Config.ScreenScale.first * 575, Config.ScreenScale.second * 575);
	MouseLeftClick();
}

void ConfirmBuy() {
	// Подтверждение покупки
	SetCursorPos(807, 550);
	MouseLeftClick();
}

void ConfirmBuy2() {
	// Подтверждение если не можете носить итем
	SetCursorPos(805, 575);
	MouseLeftClick();
}

void NoName1() {
	SetCursorPos(Config.ScreenScale.first * 990, Config.ScreenScale.second * 375);
	MouseLeftClick();
}

void NoName2() {
	SetCursorPos(Config.ScreenScale.first * 1275, Config.ScreenScale.second * 430);
	MouseLeftClick();
}

void NoName3() {
	SetCursorPos(Config.ScreenScale.first * 561, Config.ScreenScale.second * 540);
	MouseLeftClick();
}

// Other
void InsertItemName(const string& itemName) {
	MoveToInsertName();
	for (const auto& el : itemName) {
		KeyBrdBtnPress(el);
	}
}





