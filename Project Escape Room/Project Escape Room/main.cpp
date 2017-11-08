#include <SDL.h>
#include <iostream>
#include "Room.h"
#include "SDLobsluga.h"
#include <SDL_image.h>
using namespace std;


int main(int argc, char* args[])
{
	int x, y;
	Room room;
	Ekwipunek* equipment=new Ekwipunek;
	room.WeNeedToBuildAWall();
	room.AddNewPuzzle('N', 359, 210, 70, 45, 0, 0,1);//sejf
	room.AddNewPuzzle('N', 140, 290, 135, 130, 1, 1, 2);//szafka
	room.AddNewPuzzle('S', 420, 275, 90, 50, 2, 2, 2);//szuflada
	room.AddNewPuzzle('S', 125, 300, 250, 100, 3, 3, 2);//skrzynia
	room.AddNewPuzzle('N', 490, 150, 200, 230, 4, 4, 2);//drzwi

	room.AddNewPuzzle('E', 420, 360, 90, 50, 6, 6, 2);//szafa
	room.AddNewPuzzle('W', 420, 360, 90, 50, 7, 7, 2);//krzeslo

	//Start up SDL and create window
	try {
		init();
	}
	catch (int) {
		cout << "Error, inicjhalizacja not working" << endl;
		return 0;
	}
		//Load media
		if (!loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			bool quit = false;
			bool paused = false;
			//Obsluga zdarzen
			SDL_Event e;
			ObecnyObraz = ObrazSciany[North];
			Prepare();
			
			while (!quit)
			{
				//Kolejka zdarzen
				while (SDL_PollEvent(&e) != 0)
				{
					if(e.type==SDL_MOUSEBUTTONDOWN){
						SDL_GetMouseState(&x, &y);
						paused=room.CheckClick(x, y,room.walls->direction, equipment);
					}
					//Sprawdza czy zamykany
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}
					//Sprawdza ktory przycisk
					if (e.type == SDL_KEYDOWN&&paused!=true)
					{
						//Lewo czy prawo
						switch (e.key.keysym.sym)
						{
						case SDLK_LEFT:
							room.walls=room.walls->previous;
							break;
						case SDLK_RIGHT:
							room.walls = room.walls->next;
							break;
						default:
							break;
						}
						//Jaka sciana
						switch (room.walls->direction) {
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
					}
					SDL_RenderCopy(Obraz, ObecnyObraz, NULL, NULL);
					SDL_RenderPresent(Obraz);
				}
			}
		}
		close();
	return 0;
}
