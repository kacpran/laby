//#include <SDL.h>
#include <iostream>
#include <iterator>
#include "Room.h"

void Room::WeNeedToBuildAWall() {
	walls = new Wall;
	Wall* pomoc = new Wall;

	walls->direction = 'N';
	walls->next = pomoc;

	pomoc->direction = 'E';
	pomoc->previous = walls;
	pomoc->next = new Wall;
	pomoc->next->previous = pomoc;
	pomoc = pomoc->next;

	pomoc->direction = 'S';
	pomoc->next = new Wall;
	pomoc->next->previous = pomoc;
	pomoc = pomoc->next;

	pomoc->direction = 'W';
	pomoc->next = walls;
	walls->previous = pomoc;
	std::cout <<std::endl;
	return;
}

void Room::AddNewPuzzle(char direction, int x, int y, int given_width, int given_heigth, int given_itemnumber, int given_area_id, int type) {
	Wall* pomoc = walls;
	while (direction != pomoc->direction) {
		pomoc = pomoc->next;
	}
	switch (type){
	case 1:
		pomoc->puzzles.push_front(new Code(1,8,6,3,x, y, given_width, given_heigth, given_itemnumber, given_area_id));
		break;
	case 2:
		pomoc->puzzles.push_front(new UseItem( x,  y, given_width,  given_heigth,  given_itemnumber,  given_area_id));
		break;
	default:
		break;
}
	return;
}

bool Room::CheckClick(int x, int y,char direction,Ekwipunek equipment) {
	int i = 1;
	std::list<PuzzleArea*>::iterator it;
	Wall* pomoc = walls;
	

	while (pomoc->direction != direction) {
		pomoc = pomoc->next;
	}

		it=pomoc->puzzles.begin();
		do {
			std::cout << i << std::endl;
			if (x >= (*it)->x_pos && x <= ((*it)->width) + ((*it)->x_pos)) {
				if (y >= (*it)->y_pos && y <= ((*it)->height) + ((*it)->y_pos)) {
					return (*it)->Activate(equipment,direction);
				}
			}
			i++;
			it++;
		} while (it!=pomoc->puzzles.end());
	return false;
}