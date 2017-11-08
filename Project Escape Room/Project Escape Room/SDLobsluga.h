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
SDL_Texture* Przedmioty[7];
SDL_Texture* EkwipunekT = NULL;


SDL_Texture* ObecnyObraz;
SDL_Texture* Pomoc;

//Wymiary okna	
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

SDL_Rect mainview;
SDL_Rect Ekwip;
SDL_Rect Slot1;
SDL_Rect Slot2;
SDL_Rect Slot3;
SDL_Rect Slot4;
SDL_Rect Slot5;
SDL_Rect Slot6;
void Prepare();//przygotuj obraz i porty
bool init();//inicjalizacja sdl
bool loadMedia();
void close();
SDL_Texture* loadTexture(std::string path);
SDL_Surface* loadSurface(std::string);
#endif