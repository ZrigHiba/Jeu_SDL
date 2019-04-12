#include "struct.h"


void initialisation_personnage(personnage *st)
{
	char path[200];
    int i=0;
    st->pos_vie.x=100;
    st->pos_vie.y=150;
    st->pos_score.x=275;
    st->pos_score.y=150;
    st->position_back.x=0;  //init background
    st->position_back.y=0;
    st->position_text.x=100;  //init text mta3 il cordonné
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
    //st->background=IMG_Load("map1.jpg");
}


int input()
{
    int input=0;
    /*****declaration de la variable SDL event*///////////
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            input=0;
            break;
        case SDL_KEYUP:
            input=10;
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                input=0;
                break;
            case SDLK_RIGHT:
                input=1;
                break;
            case SDLK_LEFT:
                input=2;
                break;
            case SDLK_UP:
                input=3;
                break;
            case SDLK_DOWN:
                input=4;
                break;
            default:
                break;
            case SDLK_s:
                input=5;
                break;
            case SDLK_p:
                input=6;
                break;
            }
        }
    }
    return input;
}



void afficher_personnage(personnage *st,int *continuer)
{
	if (continuer == 1)
	{
	SDL_BlitSurface(st->alex_right[0],NULL,st->ecran,&st->pos_personnage_onscreen);
	SDL_Flip(st->ecran);
}

	
}


void deplacement_personnageclavier(personnage *st,int inp,int *continuer)
{
  
    if (inp==0)
    {
        *continuer=0;

    }
    else if (inp==1) /*****Fleche Droite******/
    {
        (st->pos_personnage.x)+=5; /*****Mouvement vers la droite****/
  		SDL_BlitSurface(st->alex_right[0],NULL,st->ecran,&st->pos_personnage_onscreen);/*****Sprite sheet vers la droite*****/
    }
    else if (inp==2)/******Fleche Gauche*****/
    {
        (st->pos_personnage.x)-=5;/*****Mouvement vers la gauche*****/
       	SDL_BlitSurface(st->alex_left[0],NULL,st->ecran,&st->pos_personnage_onscreen);/******Sprite sheet vers la gauche****/
    }
    else if (inp==3)/*********Fleche bas *****/
    {
        (st->pos_personnage.y)-=5;
     	SDL_BlitSurface(st->alex_top[0],NULL,st->ecran,&st->pos_personnage_onscreen);
    }
    else if (inp==4)/*******Fleche Haut******/
    {
        (st->pos_personnage.y)+=5;
        SDL_BlitSurface(st->alexbot[0],NULL,st->ecran,&st->pos_personnage_onscreen);
    }

}



void scrolling(personnage *st)
{
	
	/************Initialisation de la position caméra par rapport au personnage*/////////////
	
	st->pos_camera.x=((st->pos_personnage.x)-600);
    st->pos_camera.y=((st->pos_personnage.y)-400);
    
    /************arret de la caméra a la fin de la map*/////////////
    if  (st->pos_personnage.x<=0)
    {
        st->pos_personnage.x=0;
    }
    if  (st->pos_personnage.x>=7800)
    {
        st->pos_personnage.x=7800;
    }
    if  (st->pos_personnage.y<=0)
    {
        st->pos_personnage.y=0;
    }
    if  (st->pos_personnage.y>=7800)
    {
        st->pos_personnage.y=7800;
    }
	if (st->pos_camera.x<=0)
    {
        st->pos_camera.x=0;
        st->pos_personnage_onscreen.x=st->pos_personnage.x;
    }
    if (st->pos_camera.x>=7800)
    {
        st->pos_camera.x=7800;
        st->pos_personnage_onscreen.x=st->pos_personnage.x-8600;
    }
    if (st->pos_camera.y<=0)
    {
        st->pos_camera.y=0;
        st->pos_personnage_onscreen.y=st->pos_personnage.y;
    }
    if (st->pos_camera.y>=500)
    {
        st->pos_camera.y=500;
        st->pos_personnage_onscreen.y=st->pos_personnage.y-500;
    }
 
 }


