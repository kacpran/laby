#include <iostream>
#include <iterator>
#include "PuzzleArea.h"
#include "Item.h"

Item::Item(){
}


void Item::PickUp(int id,Ekwipunek equipment) {
	equipment.inside.push_back(new Item(id));
	return;
}

bool Item::Use(Ekwipunek equipment, int given_id){
	std::vector<Item*>::iterator it;
	it = equipment.inside.begin();
	do {
		if (given_id == (*it)->id) {
		}
		it++;
	} while (it != equipment.inside.end());
	return false;
}

void Item::Remove(Ekwipunek equipment, int given_id) {
	std::vector<Item*>::iterator it;
	it = equipment.inside.begin();
	do{ 
		if (given_id == (*it)->id) {
			equipment.inside.erase(it);
		}
	it++;
	} while (it != equipment.inside.end());
	return;
}

Item::Item(int nr) {
	id = nr;
}