#include "plateau.hpp"


void initPlateau(plateau &grille){
  for(int i = 0; i<L; i++){
    for(int j = 0; j<C; j++){
      grille[i][j] = 0;
    }
  }
}

void choixPlacement(placement &place){
  for(int i = 0; i<C; i++){
    place[i] = 0;
  }
}


void affichePlateau(plateau &grille, placement &place){
  printf("   ");
  for(int i = 0; i<C; i++){
    switch(place[i]){
      case 0: printf("    "); break;
      case 1: printf(" \033[31;2m◉\033[0m "); break;
      case 2: printf(" \033[33;2m◉\033[0m "); break;
    }
  }
  printf("\n");
  for (int i = 0; i<C+2; i++){ //Boucle qui permet de créer les bordures supérieures des deux cadres
    if (i==0){
      printf("\033[36;2m  ⌻\033[0m");
    }
    else if (i==C+1){
      printf("\b\033[36;2m⌻\033[0m\n");
    }
    else{
      printf("    ");
    }
  }
  for (int i = 0; i<L;i++){ //Boucle qui permet d'afficher le plateau principal à la zone correspondante au deuxième cadre (les 5 premières lignes)
    printf("\033[36;2m%d ⎟\033[0m", i);
    for(int j =0; j<C; j++){
      switch(grille[i][j]){ //On prend la grille principale en référence et on affiche cette dernière
        case 0: printf("   \033[36;2m⎟\033[0m"); break;
        case 1: printf(" \033[31;2m◉\033[0m \033[36;2m⎟\033[0m"); break;
        case 2: printf(" \033[33;2m◉\033[0m \033[36;2m⎟\033[0m"); break;
      }
    }
    printf("\n");
  }
  for (int i = 0; i<C+2; i++){ //Boucle qui permet d'afficher les bordures inférieures du cadre
    if (i==0){
      printf("\033[36;2m  ⌻\033[0m");
    }
    else if (i==C+1){
      printf("\b\033[36;2m⌻\033[0m\n");
    }
    else{
      printf("\033[36;2m⎼⎼⎼⎼\033[0m");
    }
  }
  printf("  ");
  for (int i = 0; i<C; i++){
    printf("\033[36;2m  %d \033[0m",i);
  }
  printf("\n");
}

void tableauCopie(plateau &grille, plateau &grille2){
	int i, j;
  for(i = 0; i<L; i++){
    for(j = 0; j<C; j++){
      grille2[i][j] = grille[i][j]; //La seconde grille récupère les coordonnées de la première pour la copie
    }
  }
}
