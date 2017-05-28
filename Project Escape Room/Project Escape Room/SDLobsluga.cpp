#include "SDLobsluga.h"
#include <SDL_image.h>
#include <SDL.h>
#include <stdio.h>
#include <string>

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
		success = false;
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
			success = false;
		}
		else
		{
			//Initialize renderer color
			
			//EkwipunekR = SDL_CreateRenderer(Ekran, -1, SDL_RENDERER_ACCELERATED);
			Obraz = SDL_CreateRenderer(Ekran, -1, SDL_RENDERER_ACCELERATED);
			//SDL_SetRenderDrawColor(EkwipunekR, 0xFF, 0xFF, 0xFF, 0xFF);
			SDL_SetRenderDrawColor(Obraz, 0xFF, 0xFF, 0xFF, 0xFF);

			//Initialize PNG loading
			int imgFlags = IMG_INIT_PNG;
			if (!(IMG_Init(imgFlags) & imgFlags))
			{
				printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
				success = false;
			}

			//Obraz = SDL_GetWindowSurface(Ekran);
		}
	}

	return success;
}
	
bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Obrazek = loadTexture("Wall_PERN.jpg");

	EkwipunekT = loadTexture("Ekwipunek.jpg");
	if (EkwipunekT == NULL)
	{
		success = false;
	}

	ObrazSciany[North] = loadTexture("Wall_PERN.jpg");
	if (ObrazSciany[North] == NULL)
	{
		success = false;
	}

	ElementyOtoczenia[0] = loadTexture("sejf.jpg"); 
	if (ElementyOtoczenia[0] == NULL)
	{
		success = false;
	}

	ElementyOtoczenia[5] = loadTexture("szuflada.jpg");
	if (ElementyOtoczenia[5] == NULL)
	{
		success = false;
	}

	ElementyOtoczenia[4] = loadTexture("skrzynia.jpg");
	if (ElementyOtoczenia[4] == NULL)
	{
		success = false;
	}

	ElementyOtoczenia[3] = loadTexture("szafka.jpg");
	if (ElementyOtoczenia[3] == NULL)
	{
		success = false;
	}


	ObrazSciany[East] = loadTexture("Wall_PERE.jpg");
	if (ObrazSciany[East] == NULL)
	{
		printf("Failed to load right image!\n");
		success = false;
	}

	ObrazSciany[West] = loadTexture("Wall_PERW.jpg");
	if (ObrazSciany[West] == NULL)
	{
		printf("Failed to load right image!\n");
		success = false;
	}

	ObrazSciany[South] = loadTexture("Wall_PERS.jpg");
	if (ObrazSciany[South] == NULL)
	{
		printf("Failed to load right image!\n");
		success = false;
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
