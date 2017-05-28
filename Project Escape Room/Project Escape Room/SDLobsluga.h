#pragma once
#ifndef SDLobsluga_h
#define SDLobsluga_h
#include <iostream>
#include <SDL_image.h>
#include <string>
#include <SDL.h>

enum WallP
{
	Start=5,
	North=0,
	West=1,
	East=2,
	South=3,
	Obecny
};

SDL_Window* Ekran;

SDL_Renderer* Obraz=NULL;

SDL_Texture* ObrazSciany[4];
SDL_Texture* ElementyOtoczenia[10];
SDL_Texture* EkwipunekT = NULL;


SDL_Texture* ObecnyObraz;

//Wymiary okna	
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

SDL_Rect mainview;
SDL_Rect Ekwip;

bool init();
bool loadMedia();
void close();
SDL_Texture* loadTexture(std::string path);
SDL_Surface* loadSurface(std::string);
#endif