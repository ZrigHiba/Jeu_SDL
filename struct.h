#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_ttf.h>
#include <time.h>


typedef struct 
{
		
SDL_Surface *ecran,*background,*background_collision,*alex_right[2],*alex_left[2],*alex_top[2],*alexbot[2];
SDL_Rect pos_personnage,pos_personnage_onscreen,position_text,position_back,pos_camera,pos_vie,pos_score;


}personnage;

/*typedef struct
{
    SDL_Rect pos_personnage,pos_personnage_onscreen,position_text,position_back,pos_camera,position_mob,pos_enigme,pos_vie,pos_score;
    SDL_Surface *ecran,*background,*background_collision,*alex_right[2],*alex_left[2],*alex_top[2],*alexbot[2],*cerebus_imin[7],*cerebus_isar[7],*texte,*texte1,*texte2,*perso,*enigme;
    int vie1,score1,vie2,score2;

}stage;*/

void initialisation_personnage(personnage *st);
void scrolling(personnage *st);
int input();
void afficher_personnage(personnage *st,int *continuer);
void deplacement_et_animation_perso(personnage *st,int inp,int *continuer,int *compteur_droite,int *compteur_gauche,int *compteur_bas,int *compteur_haut, int *etat,SDL_Color color);
SDL_Color getpixel(SDL_Surface* psurface,int x,int y);