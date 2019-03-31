#include "structs.h"
#include <stdio.h>
#include <stdlib.h>



void initialisation_personnage(personnage *st)
{
	char path[200];
    int i=0;
    
    st->pos_score.x=275;
    st->pos_score.y=150;
    st->position_back.x=0;  
    st->position_back.y=0;
    st->position_text.x=100;  //init cordonnés text
    st->position_text.y=100;
    st->pos_personnage.x=4000;  //init pos personnage absolue
    st->pos_personnage.y=6000;
    st->pos_camera.x=((st->pos_personnage.x)-600);
    st->pos_camera.y=((st->pos_personnage.y)-400);
    st->pos_personnage_onscreen.x=600;
    st->pos_personnage_onscreen.y=500;
    st->pos_camera.w = 1366;
    st->pos_camera.h = 762;
    st->perso=NULL;
    st->texte=NULL;
    st->background_collision=NULL;
    st->perso=IMG_Load("Wbot1.png");
    st->background_collision=IMG_Load("stage_collision2.jpg");
    //SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);
    st->ecran=SDL_SetVideoMode(1366,762,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Alpha", NULL);
    SDL_EnableKeyRepeat(10,10);
    for (i=0; i<=2; i++)
    {
        sprintf(path,"imin/imin_%d.png",i);
        st->alex_right[i]=IMG_Load(path);
    }
    for (i=0; i<=2; i++)
    {
        sprintf(path,"issar/issar_%d.png",i);
        st->alex_left[i]=IMG_Load(path);
    }
    for (i=0; i<=2; i++)
    {
        sprintf(path,"fou9/lfou9_%d.png",i);
        st->alex_top[i]=IMG_Load(path);
    }
    for (i=0; i<=2; i++)
    {
        sprintf(path,"louta/louta_%d.png",i);
        st->alexbot[i]=IMG_Load(path);
    }
    st->background=IMG_Load("map1.jpg");
}
void afficher_personnage(personnage *st,int *continuer)
{
	if (continuer == 1)
	{
	while (continuer)
	{
	SDL_BlitSurface(st->alex_right[0],NULL,st->ecran,&st->pos_personnage_onscreen);
	SDL_Flip(st->ecran);
	}
	}
	else 
	{
		*continuer=0;
	}
}
