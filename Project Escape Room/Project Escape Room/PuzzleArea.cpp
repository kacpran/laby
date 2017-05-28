#include <iostream>
#include "PuzzleArea.h"
#include "Item.h"
#include "SDLobsluga.h"
#include <iterator>

PuzzleArea::PuzzleArea() {
}

bool PuzzleArea::Backward(int x,int y,char direction) {
	if (x > X_exit&&x<X_exit + 200 && y>Y_exit&&y < Y_exit + 50) {
		switch (direction) {
		case 'N':
			ObecnyObraz = ObrazSciany[North];
			break;
		case 'E':
			ObecnyObraz = ObrazSciany[East];
			break;
		case 'S':
			ObecnyObraz = ObrazSciany[South];
			break;
		case 'W':
			ObecnyObraz = ObrazSciany[West];
			break;
		}
		//SDL_BlitSurface(ObecnyObraz, NULL, Obraz, NULL);
		SDL_UpdateWindowSurface(Ekran);
		return true;
	}
	return false;
}

PuzzleArea::PuzzleArea(int x,int y,int given_width,int given_heigth,int given_itemnumber,int given_area_id) {
	x_pos = x;
	y_pos = y;
	width = given_width;
	height = given_heigth;
}


bool PickItem::Activate(Ekwipunek equipment,char) {
	Item* pomoc = new Item();
	pomoc->PickUp(item_id,equipment);
	return false;
}

bool UseItem::CheckClickEQ(int x, int y, char direction, Ekwipunek equipment) {
	std::vector<Item*>::iterator it;
	if (y >= SCREEN_HEIGHT - 125) {
		for (int i = 0; i < 6; i++) {
			if (x > 20+i*130 && x < 150 + i * 130) {
				if ((*it)->id == item_id) {
					//odblokuj obszar
					(*it)->Remove(equipment, item_id);
				}
			}
		}
	}
	return false;
}

bool UseItem::Activate(Ekwipunek equipment,char direction) {
	int x, y;
	SDL_Event e;
	ObecnyObraz = ElementyOtoczenia[this->area_id];
	SDL_RenderCopy(Obraz, ObecnyObraz, NULL, NULL);
	//SDL_UpdateWindowSurface(Ekran);
	SDL_RenderPresent(Obraz);
	bool quit = false;
	while (!quit) {
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_MOUSEBUTTONDOWN) {
				SDL_GetMouseState(&x, &y);
				quit = Backward(x, y, direction);
			}
			if (e.type == SDL_QUIT )
			{
				quit = true;
			}
		}
	}
	std::cout << "dziala" << std::endl;
	return false;
}

UseItem::UseItem(int x, int y, int given_width, int given_heigth, int given_itemnumber, int given_area_id) {
	x_pos = x;
	y_pos = y;
	width = given_width;
	height = given_heigth;
	area_id = given_area_id;
	return;
}

bool Puzzle::Activate() {
	//Item* pomoc = new Item();
	int type=0;
	switch (type) {
	case 1://puzzle
		break;
	case 2://kabelki
		break;
	case 3://cus
		break;
	}
	return false;
}

bool Code::Activate(Ekwipunek equipment,char direction) {
	if (InsertCode(direction) == true) {

	}
	return false;
}

bool Code::InsertCode(char direction) {
	int InsertedCode[4];
	bool odp = false;
	ObecnyObraz = ElementyOtoczenia[0];
	SDL_RenderCopy(Obraz, ObecnyObraz, NULL, NULL);
	//SDL_UpdateWindowSurface(Ekran);
	SDL_RenderPresent(Obraz);
	SDL_Event e;
	int x,y,i = 0;
	//Sprawdza ktory przycisk
	bool quit = false;
	while (!quit){
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_MOUSEBUTTONDOWN) {
				SDL_GetMouseState(&x, &y);
				quit = Backward(x, y,direction);
			}
			if (e.type == SDL_QUIT||i==4)
			{
				quit = true;
			}
			else if (e.type == SDL_KEYDOWN){
					switch (e.key.keysym.sym)
					{
					case SDLK_0:
						InsertedCode[i] = 0;
						break;
					case SDLK_1:
						InsertedCode[i] = 1;
						i++;
						break;
					case SDLK_2:
						InsertedCode[i] = 2;
						i++;
						break;
					case SDLK_3:
						InsertedCode[i] = 3;
						i++;
						break;
					case SDLK_4:
						InsertedCode[i] = 4;
						i++;
						break;
					case SDLK_5:
						InsertedCode[i] = 5;
						i++;
						break;
					case SDLK_6:
						InsertedCode[i] = 6;
						i++;
						break;
					case SDLK_7:
						InsertedCode[i] = 7;
						i++;
						break;
					case SDLK_8:
						InsertedCode[i] = 8;
						i++;
						break;
					case SDLK_9:
						InsertedCode[i] = 9;
						i++;
						break;
					default:
						break;
					}
				}	
			}
		}
	for (int i = 0; i < 4; i++) {
		if (InsertedCode[i] != ProgrammedCode[i]) {
			return false;
			}
		else {
			std::cout << "good" << std::endl;
			odp = true;
			}
		}
	return odp;
}

Code::Code(int p, int d, int t, int c, int x, int y, int given_width, int given_heigth, int given_itemnumber, int given_area_id){
	ProgrammedCode[0] = p;
	ProgrammedCode[1] = d;
	ProgrammedCode[2] = t;
	ProgrammedCode[3] = c;
	x_pos = x;
	y_pos = y;
	width = given_width;
	height = given_heigth;

}