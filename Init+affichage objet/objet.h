#ifndef OBJET_H_INCLUDED
#define OBJET_H_INCLUDED

typedef struct
{
SDL_Rect hitbox;
int vitx,vity;
}square;
typedef struct
{
SDL_Surface *obj;
SDL_Rect posobj;
square carre;
}objet;
void initobjet(objet *o);
void afficherobjet(objet *o);



#endif //OBJET_H_INCLUDED
