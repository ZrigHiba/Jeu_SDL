#include "struct.h"



int main(int argc, char const *argv[])
{
	personnage *st;
    SDL_Init(SDL_INIT_VIDEO);
    initialisation_personnage(&st);
    Uint32 start;
    //police= TTF_OpenFont("font/KidPixies.ttf",30);
    SDL_Color couleurHelp = {247, 199, 134},color= {0,0,0};
    int continuer=1,inp=0;
    const int FPS=60;
    while(continuer)
    {
		start=SDL_GetTicks();
		inp=input();
        afficher_personnage(st,&continuer);
        deplacement_personnageclavier(st,inp,&continuer);
        scrolling(st);
        SDL_Flip(st->ecran);
        //glClear(GL_COLOR_BUFFER_BIT);
        // SDL_GL_SwapBuffers();
        if (1000/FPS>SDL_GetTicks()-start)
        {
            SDL_Delay(1000/FPS-(SDL_GetTicks()-start));
        }
    }
    SDL_Quit();
}