#ifndef ENIGME1_H_INCLUDED
#define ENIGME1_H_INCLUDED

typedef struct enigme
 {

      int QuestionPart1;
      int QuestionPart2;
      int Questionpart3;
      int Answer1;
      int Answer2;
      int Answer3;
      int solution;
      SDL_Rect pos;
 }enigme;



 void initenigme(enigme *e[]);
 void generation_enigme(enigme E);
 void affenigme();
 void teste_enigme(SDL_Surface *screen);


#endif // ENIGME1_H_INCLUDED
