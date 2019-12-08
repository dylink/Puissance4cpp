#include "plateau.hpp"


int main(){
  printf("\e[2J\e[8;27;100t");
  /*plateau grille = {0,0,0,0,0,0,0,
                    0,0,0,0,0,0,0,
                    0,0,0,0,0,0,0,
                    1,0,0,0,0,0,0,
                    1,0,2,0,0,0,0,
                    1,2,2,0,0,0,1};

  placement rien;
  affichePlateau(grille, rien);
  printf("Joueur 1 == %d\n Joueur 2 == %d\n", getScore(grille, 1), getScore(grille, 2));*/
  jeu();
  return 0;
}
