#include <iostream>
#include <iterator>
#include "PuzzleArea.h"
#include "Item.h"
#include "SDLobsluga.h"
#include <string>

Item::Item(){
}

void Item::ChangeImage(int id,bool OnOff) {
	switch (id) {
	case 1:
		SDL_RenderSetViewport(Obraz, &Slot1);
		break;
	case 2:
		SDL_RenderSetViewport(Obraz, &Slot2);
		break;
	case 3:
		SDL_RenderSetViewport(Obraz, &Slot3);
		break;
	case 4:
		SDL_RenderSetViewport(Obraz, &Slot4);
		break;
	case 5:
		SDL_RenderSetViewport(Obraz, &Slot5);
		break;
	case 6:
		SDL_RenderSetViewport(Obraz, &Slot6);
		break;
	}
	if (OnOff == true) {
		ObecnyObraz = Przedmioty[id -1];
	}
	else {
		ObecnyObraz = Przedmioty[6];
	}
	SDL_RenderCopy(Obraz, ObecnyObraz, NULL, NULL);
	SDL_RenderPresent(Obraz);
	SDL_RenderSetViewport(Obraz, &mainview);
	return;
}



void Item::PickUp(int id,Ekwipunek* equipment) {
	equipment->inside.push_back(new Item(id));
	ChangeImage(id,true);
	return;
}

bool Item::Use(Ekwipunek* equipment, int given_id){
	std::vector<Item*>::iterator it;
	it = equipment->inside.begin();
	do {
		if (given_id == (*it)->id) {
		}
		it++;
	} while (it != equipment->inside.end());
	return false;
}

void Item::Remove(Ekwipunek* equipment, int given_id) {
	std::vector<Item*>::iterator it;
	bool odp;
	do{ 
		it = equipment->inside.begin();
		if (given_id == (*it)->id) {
			equipment->inside.erase(it);
			it = equipment->inside.end();
			ChangeImage(given_id, false);
			odp = true;
		}
		else {
			it++;
		}
	} while (it != equipment->inside.end()||odp!=true);
	return;
}

Item::Item(int nr) {
	id = nr;
}