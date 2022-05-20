#pragma once
#include <Windows.h>
#include <string>
#include <map>
#include <set>



using namespace std;

// Заголовочный файл в котором находяться функции 
// по перемещениям курсора буква 'C' означает, что функция используется
// для черного рынка: [MoveToTier] - для рынков всех городов
// [MoveToTierC] - ТОЛЬКО для черного рынка


// Mouse and Keyboard Events
void MouseLeftClick();

void KeyBrdBtnPress(char lt);

// Move to Positions
void MoveToInsertName();

void MoveToTier(int tier);

void MoveToTierC(int tier);

void MoveToEnchant(int enchant);

void MoveToEnchantC(int enchant);

void MoveToQuality(int qual);

void ClearItemName();

void MoveToBuy();

void MoveToBuy2();

void MoveToEdit();

void MoveToEditPrice();

void UpdateOrder();

// Other
void InsertItemName(const string& itemName);







