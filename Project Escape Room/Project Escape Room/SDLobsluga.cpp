#include "SDLobsluga.h"
#include <SDL_image.h>
#include <SDL.h>
#include <stdio.h>
#include <string>

void Prepare() {
	mainview.x = 0;
	mainview.y = 0;
	mainview.w = SCREEN_WIDTH;
	mainview.h = SCREEN_HEIGHT - 125;


	Ekwip.x = 0;
	Ekwip.y = SCREEN_HEIGHT - 125;
	Ekwip.w = SCREEN_WIDTH;
	Ekwip.h = 125;

	Slot1.x = 20;
	Slot1.y = 490;
	Slot1.w = 100;
	Slot1.h = 100;

	Slot2.x = 148;
	Slot2.y = 490;
	Slot2.w = 100;
	Slot2.h = 100;

	Slot3.x = 276;
	Slot3.y = 490;
	Slot3.w = 100;
	Slot3.h = 100;

	Slot4.x = 410;
	Slot4.y = 490;
	Slot4.w = 100;
	Slot4.h = 100;

	Slot5.x = 548;
	Slot5.y = 490;
	Slot5.w = 100;
	Slot5.h = 100;

	Slot6.x = 680;
	Slot6.y = 490;
	Slot6.w = 100;
	Slot6.h = 100;

	SDL_RenderSetViewport(Obraz, &mainview);
	SDL_RenderSetViewport(Obraz, &Ekwip);
	ObecnyObraz = EkwipunekT;
	SDL_RenderCopy(Obraz, ObecnyObraz, NULL, NULL);
	ObecnyObraz = ObrazSciany[North];
	SDL_RenderSetViewport(Obraz, &mainview);
	return;
}

SDL_Texture* loadTexture(std::string path)
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(Obraz, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;
}

bool init()
{
	bool success = true;

	//Inicjalizacja, sprawdzenie
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		throw success;
	}
	else
	{
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}
		//Tworzy ekran
		Ekran = SDL_CreateWindow("Escape Room", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (Ekran == NULL)
		{
			throw success;
		}
		else
		{
			//Initialize renderer color
			
			Obraz = SDL_CreateRenderer(Ekran, -1, SDL_RENDERER_ACCELERATED);
			
			SDL_SetRenderDrawColor(Obraz, 0xFF, 0xFF, 0xFF, 0xFF);

			//Initialize PNG loading
			int imgFlags = IMG_INIT_PNG;
			if (!(IMG_Init(imgFlags) & imgFlags))
			{
				printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
				throw success;
			}			
		}
	}

	return success;
}
	
bool loadMedia()
{
	bool success = true;

	EkwipunekT = loadTexture("Ekwipunek.jpg");
	if (EkwipunekT == NULL)
	{
		throw success;
	}

	ObrazSciany[North] = loadTexture("Wall_PERN.jpg");
	if (ObrazSciany[North] == NULL)
	{
		throw success;
	}

	ObrazSciany[East] = loadTexture("Wall_PERE.jpg");
	if (ObrazSciany[East] == NULL)
	{
		printf("Failed to load right image!\n");
		throw success;
	}

	ObrazSciany[West] = loadTexture("Wall_PERW.jpg");
	if (ObrazSciany[West] == NULL)
	{
		printf("Failed to load right image!\n");
		throw success;
	}

	ObrazSciany[South] = loadTexture("Wall_PERS.jpg");
	if (ObrazSciany[South] == NULL)
	{
		printf("Failed to load right image!\n");
		throw success;
	}

	Przedmioty[0] = loadTexture("kluczSzafeczka.jpg");
	if (Przedmioty[0] == NULL) 
	{
		throw success;
	}

	Przedmioty[1] = loadTexture("kartaSzuflada.jpg");
	if (Przedmioty[1] == NULL)
	{
		throw success;
	}

	Przedmioty[2] = loadTexture("lom.jpg");
	if (Przedmioty[2] == NULL)
	{
		throw success;
	}

	Przedmioty[3] = loadTexture("kluczDrzwi.jpg");
	if (Przedmioty[3] == NULL)
	{
		throw success;
	}
	
	Przedmioty[6] = loadTexture("pustyEQ.jpg");
	if (Przedmioty[6] == NULL)
	{
		throw success;
	}

	ElementyOtoczenia[0] = loadTexture("sejf.jpg"); 
	if (ElementyOtoczenia[0] == NULL)
	{
		throw success;
	}

	ElementyOtoczenia[1] = loadTexture("szafka.jpg");
	if (ElementyOtoczenia[1] == NULL)
	{
		throw success;
	}

	ElementyOtoczenia[2] = loadTexture("szuflada.jpg");
	if (ElementyOtoczenia[2] == NULL)
	{
		throw success;
	}

	ElementyOtoczenia[3] = loadTexture("skrzynia.jpg");
	if (ElementyOtoczenia[3] == NULL)
	{
		throw success;
	}

	return success;
}

void close()
{
	//Deallocate surfaces
	for (int i = 0; i < 4; ++i)
	{
		//SDL_FreeSurface(ObrazSciany[i]);
		ObrazSciany[i] = NULL;
	}

	//Destroy window
	SDL_DestroyWindow(Ekran);
//	SDL_DestroyTexture(SDL_Texture* gTexture);
	Ekran = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}	

SDL_Surface* loadSurface(std::string path)
{
	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
	}

	return loadedSurface;
}
