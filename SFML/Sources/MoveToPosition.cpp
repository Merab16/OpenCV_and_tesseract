#include "../Headers/MoveToPosition.h"

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
	{10, {500, 590}}
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
	Sleep(150);
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
	SetCursorPos(650, 270);
	MouseLeftClick();
}

void MoveToTier(int tier) {
	SetCursorPos(950, 270);
	MouseLeftClick();
	SetCursorPos(TierPosition[tier].first, TierPosition[tier].second);
	MouseLeftClick();
}

void MoveToTierC(int tier) {
	SetCursorPos(520, 400);
	MouseLeftClick();
	SetCursorPos(TierPositionC[tier].first, TierPositionC[tier].second);
	MouseLeftClick();
}

void MoveToEnchant(int enchant) {
	SetCursorPos(1100, 270);
	MouseLeftClick();
	SetCursorPos(EnchantPosition[enchant].first, EnchantPosition[enchant].second);
	MouseLeftClick();
}

void MoveToEnchantC(int enchant) {
	SetCursorPos(670, 400);
	MouseLeftClick();
	SetCursorPos(EnchantPositionC[enchant].first, EnchantPositionC[enchant].second);
	MouseLeftClick();
}

void MoveToQuality(int qual) {
	SetCursorPos(1230, 270);
	MouseLeftClick();
	SetCursorPos(QualityPosition[qual].first, QualityPosition[qual].second);
	MouseLeftClick();
}

void ClearItemName() {
	SetCursorPos(722, 270);
	MouseLeftClick();
}

void MoveToBuy() {
	SetCursorPos(1280, 430);
	MouseLeftClick();
}

void MoveToBuy2() {
	SetCursorPos(885, 735);
	MouseLeftClick();
}

void MoveToEdit() {
	SetCursorPos(1230, 410);
	MouseLeftClick();
}

void MoveToEditPrice() {
	SetCursorPos(635, 635);
	MouseLeftClick();
}

void UpdateOrder() {
	SetCursorPos(875, 735);
	MouseLeftClick();
}

// Other
void InsertItemName(const string& itemName) {
	MoveToInsertName();
	for (const auto& el : itemName) {
		KeyBrdBtnPress(el);
	}
}





