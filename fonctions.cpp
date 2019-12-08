#include "plateau.hpp"


int placerJeton(plateau &grille, int j, int joueur){
  if(grille[0][j]){
    return 0;
  }
  for(int i = 0; i<L; i++){
    if(grille[i][j]){
      grille[i-1][j] = joueur;
      return 1;
    }
  }
  grille[L-1][j] = joueur;
  return 1;
}

int finDeJeu(plateau &grille){
  for(int i = L-1; i>=0; i--){
    for(int j = C-1;j>=0;j--){
      if(grille[i][j]){
        if( (grille[i-1][j] == grille[i][j] && grille[i-2][j] == grille[i][j] && grille[i-3][j] == grille[i][j]) ||
        (grille[i-1][j+1] == grille[i][j] && grille[i-2][j+2] == grille[i][j] && grille[i-3][j+3] == grille[i][j]) ||
        (grille[i-1][j-1] == grille[i][j] && grille[i-2][j-2] == grille[i][j] && grille[i-3][j-3] == grille[i][j]) ||
        (grille[i][j+1] == grille[i][j] && grille[i][j+2] == grille[i][j] && grille[i][j+3] == grille[i][j]) ) {
          printf("Le joueur %d a gagné!\n", grille[i][j]);
          return grille[i][j];
        }
      }
    }
  }
  return 0;
}
