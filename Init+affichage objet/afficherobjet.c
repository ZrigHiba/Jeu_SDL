#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include <SDL/SDL_image.h>
#include "objet.h"

void afficherobjet (objet *o)
{
SDL_Surface *ecran;
SDL_Surface *background;
SDL_Rect positionecran;


if (SDL_Init(SDL_INIT_VIDEO)!=0){
	printf("Unable to initialize SDL: %s\n",SDL_GetError());
	return 1;
}
ecran=SDL_SetVideoMode(1280,720,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
if (ecran == NULL){
	printf("Unable to set video mode: %s\n",SDL_GetError());
	return 1;
}
background = SDL_LoadBMP();
positionecran.x=0;
positionecran.y=0;
positionecran.w=background->w;
positionecran.h=background->h;
if (background == NULL){
	printf("Unable to load Bitmap: %s\n",SDL_GetError());
	return 1;
o->obj=IMG_Load();
}
