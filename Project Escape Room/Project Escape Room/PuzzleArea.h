#pragma once
#pragma once
#ifndef PuzzleArea_h
#define PuzzleArea_h
#include <vector>
#include "Ekwipunek.h"

class PuzzleArea {
public:
	int X_exit=300;
	int Y_exit=450;
	int x_pos;
	int y_pos;
	int width;
	int height;
	int area_id;
		bool Backward(int,int,char);//Cofnij widok
		virtual bool Activate(Ekwipunek*,char)=0;
		PuzzleArea();
		PuzzleArea(int,int,int,int,int, int);
};

class PickItem : public PuzzleArea{
	using PuzzleArea::x_pos;
	using PuzzleArea::y_pos;
	using PuzzleArea::width;
	using PuzzleArea::height;
	using PuzzleArea::area_id;
	int  item_id;
	virtual bool Activate(Ekwipunek*,char);
};

class Code : public PuzzleArea {
public:
	using PuzzleArea::x_pos;
	using PuzzleArea::y_pos;
	using PuzzleArea::width;
	using PuzzleArea::height;
	using PuzzleArea::area_id;
	int ProgrammedCode[4]; 
	virtual bool Activate(Ekwipunek*,char);
	bool InsertCode(char);
	Code(int,int,int,int, int, int, int, int, int, int);
};

class UseItem : public PuzzleArea {
public:
	using PuzzleArea::x_pos;
	using PuzzleArea::y_pos;
	using PuzzleArea::width;
	using PuzzleArea::height;
	using PuzzleArea::area_id;
	int item_id;
	virtual bool Activate(Ekwipunek*,char);
	bool CheckClickEQ(int, int, char, Ekwipunek*,int);
	UseItem(int, int, int, int, int, int);
};

class Puzzle : private PuzzleArea {
	using PuzzleArea::x_pos;
	using PuzzleArea::y_pos;
	using PuzzleArea::width;
	using PuzzleArea::height;
	using PuzzleArea::area_id;
	virtual bool Activate();
};



#endif