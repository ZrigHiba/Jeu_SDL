bool Collision(Cercle C1,Cercle C2)
{
   int d2 = (C1.x-C2.x)*(C1.x-C2.x) + (C1.y-C2.y)*(C1.y-C2.y);
   if (d2 > (C1.rayon + C2.rayon)*(C1.rayon + C2.rayon))
      return false;
   else
      return true;
}
