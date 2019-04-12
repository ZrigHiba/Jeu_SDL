#include <stdlib.h>
#include <stdio.h>
#include "SDL/SDL.h"
#include <SDL/SDL_image.h>
#include "objet.h"

void initobjet(objet *o)
{
o->obj=NULL;
o->posobj.x=200;
o->posobj.y=350;
o->carre.hitbox.x=200;
o->carre.hitbox.y=350;
o->carre.hitbox.w=50;
o->carre.hitbox.h=50;
o->carre.vitx=0;
o->carre.vity=0;
}
