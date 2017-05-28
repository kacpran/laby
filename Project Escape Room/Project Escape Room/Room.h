#pragma once
#ifndef Room_h
#define Room_h
#include "PuzzleArea.h"
#include <list>
class Room {

	struct Wall {
		char direction;
		Wall* next;
		Wall* previous;
		std::list<PuzzleArea*>puzzles;
	};

	
public:
	Wall* walls;
	void WeNeedToBuildAWall();
	void AddNewPuzzle(char,int , int , int , int , int , int ,int );
	bool CheckClick(int, int,char,Ekwipunek);
};

#endif