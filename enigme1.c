#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "enigme.h"




 void initenigme (enigme *e)
{


   e->Questionpart1 =NULL;
   e->Questionpart2 =NULL;
   e->Questionpart3 =NULL;
   e->Answer1 =0;
   e->Answer2=0;
   e->Answer3 =0;
   pos.x=0;
   pos.y=0;

}


void affenigme()

{


/* Chargement d'une image Bitmap dans une surface */
   imageDeFond = SDL_LoadBMP("QR1R2R3.bmp");
   fonttexte=TTF_OpenFont("E.ttf",65);
   texte = TTF_RenderText_Blended(fonttexte, "Salut les Zér0s !", couleurNoire);



    SDL_BlitSurface(imageDeFond, NULL, ecran, &position);
    position.x = 60;
    position.y = 370;
    SDL_BlitSurface(texte, NULL, ecran, &position);
    SDL_Flip(ecran);
    pause();

     SDL_FreeSurface(imageDeFond);


    TTF_CloseFont(fonttexte);
    TTF_Quit();

    SDL_FreeSurface(texte);
    SDL_Quit();
  return EXIT_SUCCESS;
}




void Generate_Enigme(enigme *E)
{
    int i = rand() % 10 + 1 ;
    char filename[50], tmp[4];

    if( i < 8 )
    {
         sprintf( filename, "enigme/enigme%d.txt", i);
    FILE *f = fopen(filename, "r");

    fscanf(f, "%s", E.QuestionPart1);
    fscanf(f, "%s", E.QuestionPart2);
    fscanf(f, "%s", E.QuestionPart3);
    fscanf(f, "%s", E.Answer1);
    fscanf(f, "%s", E.Answer2);
    fscanf(f, "%s", E.Answer3);
    fscanf(f, "%s", tmp);
    E.solution = tmp[2] - 48 ;

    E.QuestionPart1 = Replace_Hyphen( E.QuestionPart1 ) ;
    E.QuestionPart2 = Replace_Hyphen( E.QuestionPart2 ) ;
    E.QuestionPart3 = Replace_Hyphen( E.QuestionPart3 ) ;
    E.Answer1 = Replace_Hyphen( E.Answer1 ) ;
    E.Answer2 = Replace_Hyphen( E.Answer2 ) ;
    E.Answer3 = Replace_Hyphen( E.Answer3 ) ;

    fclose(f);
    }
    else
      {
        int rand_x = rand() % 9 + 1, rand_y = rand() % 9 + 1, s = rand() % 3 + 1 ;
        float answer1, answer2, answer3 ;

        if( s == 1 )
        {
            answer1 =  - ( (float) rand_y / rand_x ) ;
            answer2 = (float)( rand() % 1000 + 100 ) / -100 ;
            answer3 = (float)( rand() % 1000 + 100 ) / -100 ;
        }
        else if( s == 2 )
        {
            answer1 = (float)( rand() % 1000 + 100 ) / -100 ;
            answer2 =  - ( (float) rand_y / rand_x ) ;
            answer3 = (float)( rand() % 1000 + 100 ) / -100 ;
        }
        else if( s == 3 )
{
            answer1 = (float)( rand() % 1000 + 100 ) / -100 ;
            answer2 = (float)( rand() % 1000 + 100 ) / -100 ;
            answer3 = - ( (float) rand_y / rand_x ) ;
        }

        sprintf( E.QuestionPart1, "Q: What's The Solution To %dX + %d ?", rand_x, rand_y ) ;

        sprintf( E.Answer1, "1:%.2f", answer1 ) ;
        sprintf( E.Answer2, "2:%.2f", answer2 ) ;
        sprintf( E.Answer3, "3:%.2f", answer3 ) ;

        E.solution = s ;
    }

}



void teste_enigme(SDL_Surface *screen)
 {
    SDL_Surface = *answer = NULL, *enigme = NULL;
    SDL_Rect posanswer, posenigme;
    SDL_Event event;
    Mix_Chunk *sound;
    sound = Mix_LoadWAV("correct.png");
        int done = 1;
    posenigme.x= ;
    posenigme.y = ;
    enigme = IMG_Load ("enigme1.png");
    SDL_BlitSurface (enigme,NULL,screen; &posenigme);
    SDL-Flip(screen);


    while (done)
     {
       while (SDL_PollEvent(&event))
         {
           switch(event.type)
           {case SDL_KEYDOWN:
              if(event.key.keysym.sym == SDLK_a)
                {
                 answer = IMG_Load("incorrect.png");
                 posanswer.x = ;
                 posanswer.y = ;
                 SDL_BlitSurface (answer,NULL,screen,&posanswer);
                 SDL_Flip(screen);
                 Mix_PlayChnnel(-1,sound,0);
                 SDL_Deplay(1000);
                 done=0;
                 }

              else if (event.key.keysym.sym == SDLK_b)
                {
                 answer=IMG_Load("incorrect.png");
                 posanswer.x=699;
                 posanswer.y=358;
                 SDL_BlitSurface(answer,NULL,screen,&posanswer);
                 SDL_Flip(screen);
                 Mix_PlayChannel(-1,sound,0);
                 SDL_Delay(1000);
                 done=0;
                }

              else if(event.key.keysym.sym==SDLK_C)
                {
                  sound = Mix_LoadWAV("correct.wav");
                  Mix_PlayChannel(-1,sound,0);
                  answer = IMG_Load("correctanswer.png");
                  posanswer.x =  ;
                  posanswer.y =  ;
                  SDL_BlitSurface (answer, NULL, screen, &posanswer);
                  SDL_Flip(screen);

                  SDL_Delay(1000);
                  done = 0;
                 }
   SDL_Delay(1000);
                  done = 0;
                 }

              }
            }
         }

 Mix_FreeChunk(sound);
 SDL_FreeSurface(answer);
 SDL_FreeSurface(enigme);
}
