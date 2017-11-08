#pragma once
#ifndef Item_h
#define Item_h
#include <vector>
#include "PuzzleArea.h"
#include "Ekwipunek.h"


class Item {
	public:
		int id;
		void PickUp(int, Ekwipunek*);
		bool Use(Ekwipunek*,int);
		void Remove(Ekwipunek*,int);
		void ChangeImage(int,bool);
	Item();
	Item(int);
};


#endif