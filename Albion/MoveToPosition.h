#pragma once
#include <Windows.h>
#include <string>
#include <map>
#include <set>



using namespace std;

// ������������ ���� � ������� ���������� ������� 
// �� ������������ ������� ����� 'C' ��������, ��� ������� ������������
// ��� ������� �����: [MoveToTier] - ��� ������ ���� �������
// [MoveToTierC] - ������ ��� ������� �����


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







