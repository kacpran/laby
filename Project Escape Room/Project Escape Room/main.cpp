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
	Ekwipunek equipment;
	room.WeNeedToBuildAWall();
	room.AddNewPuzzle('N', 359, 210, 70, 45, 0, 1,1);//sejf
	room.AddNewPuzzle('N', 490, 150, 200, 230, 0, 2, 2);//drzwi
	room.AddNewPuzzle('N', 140, 290, 135, 130, 0, 3, 2);//szafka
	room.AddNewPuzzle('S', 125, 300, 250, 100, 0, 4, 2);//skrzynia
	room.AddNewPuzzle('S', 420, 275, 90, 50, 0, 5, 2);//szuflada
	room.AddNewPuzzle('E', 420, 360, 90, 50, 0, 6, 2);
	room.AddNewPuzzle('W', 420, 360, 90, 50, 0, 7, 2);
	//Start up SDL and create window
	if (!init()){
		printf("Failed to initialize!\n");
	}
	else
	{
		//Load media
		if (!loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			//Main loop flag
			bool quit = false;
			bool paused = false;
			//Event handler
			SDL_Event e;
			//Set default current surface

			ObecnyObraz = ObrazSciany[North];
			
		
			mainview.x = 0;
			mainview.y = 0;
			mainview.w = SCREEN_WIDTH;
			mainview.h = SCREEN_HEIGHT - 125;

			
			Ekwip.x = 0;
			Ekwip.y = SCREEN_HEIGHT - 125;
			Ekwip.w = SCREEN_WIDTH;
			Ekwip.h = 125;

			SDL_RenderSetViewport(Obraz, &mainview);
			//SDL_RenderCopy(Obraz, ObecnyObraz, NULL, NULL);
			
			
			SDL_RenderSetViewport(Obraz, &Ekwip);
			ObecnyObraz = EkwipunekT;
			SDL_RenderCopy(Obraz, ObecnyObraz, NULL, NULL);
			ObecnyObraz = ObrazSciany[North];
			SDL_RenderSetViewport(Obraz, &mainview);

	
			//While application is running
			while (!quit)
			{
				//Handle events on queue
				while (SDL_PollEvent(&e) != 0)
				{
					if(e.type==SDL_MOUSEBUTTONDOWN){
						SDL_GetMouseState(&x, &y);
						cout << "X: " << x << " Y: " << y << endl;
						paused=room.CheckClick(x, y,room.walls->direction, equipment);
					}
					
						//User requests quit
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
	}
	return 0;
	
}
