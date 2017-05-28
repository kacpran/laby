#pragma once
#ifndef Ekwipunek_h
#define Ekwipunek_h
#include <vector>

class Ekwipunek {
public:
	friend class Item;
	std::vector<Item*>inside;
};

#endif