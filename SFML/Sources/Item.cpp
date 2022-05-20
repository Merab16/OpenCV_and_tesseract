#include "../Headers/Item.h"

bool operator== (const _Item& lhs, const _Item& rhs) {

	if (lhs.name == rhs.name &&
		lhs.tier == rhs.tier &&
		lhs.enchant == rhs.enchant) {
		return true;
	}
	return false;

}

bool operator< (const _Item& lhs, const _Item& rhs) {

	return tie(lhs.name, lhs.tier, lhs.enchant) <
		tie(rhs.name, rhs.tier, rhs.enchant);

}


bool operator> (const _Item& lhs, const _Item& rhs) {
	return !(lhs < rhs);
}

ostream& operator<< (ostream& os, const _Item& item) {
	os << item.name << ' ' << item.tier << '.' << item.enchant;

	return os;
}


