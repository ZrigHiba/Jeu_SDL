#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
int main (void)
{
	SDL_Surface *screen;
	SDL_Surface *background;
	SDL_Surface *ngb;
	SDL_Rect posback;
	SDL_Rect posngb;
	SDL_Event event;
	int pos;
	if (SDL_Init(SDL_INIT_VIDEO)!=0)
	{
		printf("Unable to initialize SDL: %s\n",SDL_GetError());
		return 1;
	}
	screen= SDL_SetVideoMode(1280,720,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
	if(screen==NULL)
	{
		printf("Unable to set 1280x720 video: %s\n",SDL_GetError());
		return 1;
	}
	background= SDL_LoadBMP("menubackground2.bmp");
	if (background==NULL)
	{
		printf("Unable to load bitmap: %s\n",SDL_GetError());
		return 1;
	}
	ngb=IMG_Load("ngbutton.png");
	if (ngb= NULL)
	{
		printf("Unable to load .png : %s\n",SDL_GetError());
		return 1;
	}
	posback.x=0;
	posback.y=0;
	posngb.x=530;
	posngb.y=300;
	if (Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
	{
		printf("%s\n",Mix_GetError());
	}
	Mix_Music *theme;
	theme= Mix_LoadMUS("menutheme.mp3");
	Mix_PlayMusic(theme,-1);
	int done =1;
	pos=1;
	while(done==1)
	{
		SDL_BlitSurface(background,NULL,screen,&posback);
		SDL_BlitSurface(ngb,NULL,screen,&posngb);
		SDL_Flip(screen);
   		while (SDL_PollEvent(&event))
   		{
			switch (event.type)
			{
				case SDL_QUIT:
				done=0;
				break;
				case SDL_KEYDOWN:
					if (event.key.keysym.sym ==SDLK_ESCAPE)
				  	done=0;
					else 
					{		
					if (event.key.keysym.sym ==SDLK_DOWN)
					  pos++;
					else if (event.key.keysym.sym==SDLK_UP)
					  pos--;
				}
				break;
		}
		switch (pos)
		{
			case 1:
			ngb=IMG_Load("ngbutton.png");
			if (ngb == NULL)
			{
				printf("Unable to load .png : %s\n",SDL_GetError());
				return 1;
			}
			posngb.x=530;
			posngb.y=300;
			SDL_BlitSurface(ngb,NULL,screen,&posngb);
			break;
			case 2:
 			ngb=IMG_Load("loadbutton.png");
			if (ngb == NULL)
			{
				printf("Unable to load .png : %s\n",SDL_GetError());
				return 1;
			}
			posngb.x=530;
			posngb.y=300;
			SDL_BlitSurface(ngb,NULL,screen,&posngb);
			break;
			case 3:
	 		ngb=IMG_Load("settingsbutton.png");
			if (ngb == NULL)
			{
				printf("Unable to load .png : %s\n",SDL_GetError());
				return 1;
			}
			posngb.x=530;
			posngb.y=300;
			SDL_BlitSurface(ngb,NULL,screen,&posngb);
			if (event.key.keysym.sym ==SDLK_RETURN)
			{
				ngb=IMG_Load("InputMethod.png");
				if (ngb == NULL)
				{
					printf("Unable to load .png : %s\n",SDL_GetError());
					return 1;
				}
				posngb.x=530;
				posngb.y=300;
				SDL_BlitSurface(ngb,NULL,screen,&posngb);
			}
			break;
			case 4:
	 		ngb=IMG_Load("creditsbutton.png");
			if (ngb == NULL)
			{
				printf("Unable to load .png : %s\n",SDL_GetError());
				return 1;
			}
			posngb.x=530;
			posngb.y=300;
			SDL_BlitSurface(ngb,NULL,screen,&posngb);
			break;
			case 5:
	 		ngb=IMG_Load("quitbutton.png");
			if (ngb == NULL)
			{
				printf("Unable to load .png : %s\n",SDL_GetError());
				return 1;
			}
			posngb.x=530;
			posngb.y=300;
			SDL_BlitSurface(ngb,NULL,screen,&posngb);
			if (event.key.keysym.sym ==SDLK_RETURN)
			{
				done=0;	
			}
			break;
		}
	}
}
Mix_FreeMusic(theme);
SDL_FreeSurface(background);
SDL_FreeSurface(ngb);
SDL_Quit;
}
