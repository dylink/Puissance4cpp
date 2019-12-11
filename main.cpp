#include "plateau.hpp"


int main(){
  printf("\e[2J\e[8;27;100t");
  /*plateau grille = {0,0,1,0,0,0,0,
                    0,0,2,0,0,0,0,
                    0,2,2,0,0,0,0,
                    0,2,2,1,1,0,0,
                    1,1,1,2,1,0,0,
                    1,1,2,2,1,0,0
                    };

  placement rien;
  affichePlateau(grille, rien);
  printf("Joueur 1 == %d\nJoueur 2 == %d\n", eval(grille, 1), eval(grille, 2));
  //printf("%d\n", finDeJeu(grille));
  printf("%d\n", finDeJeu(grille));*/
  jeu();
  return 0;
}
