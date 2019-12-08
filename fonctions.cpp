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

int enleverJeton(plateau &grille, int j){
  for(int i = 0; i<L; i++){
    if(grille[i][j]){
      grille[i][j] = 0;
      return 1;
    }
  }
  return 0;
}

int nbCoups(plateau &grille){
  int nb = 0;
  for(int i = 0; i<L; i++){
    for(int j = 0; j<C; j++){
      if(grille[i][j]){
        nb++;
      }
    }
  }
  return nb;
}

int finDeJeu(plateau &grille){
  for(int i = L-1; i>=0; i--){
    for(int j = 0;j<C;j++){
      if(grille[i][j]){
        if( (grille[i-1][j] == grille[i][j] && grille[i-2][j] == grille[i][j] && grille[i-3][j] == grille[i][j]) ||
        (grille[i-1][j+1] == grille[i][j] && grille[i-2][j+2] == grille[i][j] && grille[i-3][j+3] == grille[i][j] && j<C-3) ||
        (grille[i-1][j-1] == grille[i][j] && grille[i-2][j-2] == grille[i][j] && grille[i-3][j-3] == grille[i][j] && j>2) ||
        (grille[i][j+1] == grille[i][j] && grille[i][j+2] == grille[i][j] && grille[i][j+3] == grille[i][j] && j<C-3) ) {
          //printf("Le joueur %d a gagné!\n", grille[i][j]);
          return grille[i][j];
        }
      }
    }
  }
  return 0;
}

int getScore(plateau &grille, int joueur){
  placement rien;
  int mes_deux = 0, mes_trois = 0, mes_quatre = 0;
  for(int i = L-1; i>=0; i--){
    for(int j = C-1; j>=0; j--){
      if(grille[i][j] == joueur){
        if(grille[i-1][j] == joueur && grille[i+1][j] != joueur && i>0){
          if(grille[i-2][j] == joueur){
            if(grille[i-3][j] == joueur){
              mes_quatre++;
            }
            else if(!grille[i-3][j]){
              mes_trois++;
            }
          }
          else if(!grille[i-2][j]){
            //printf("Oui %d && (%d, %d) avec (%d, %d)\n", grille[i][j], i, j, i-1, j);
            mes_deux++;
          }
        }
        if(grille[i][j-1] == joueur && grille[i][j+1] != joueur && j>0){
          if(grille[i][j-2] == joueur){
            if(grille[i][j-3] == joueur){
              mes_quatre++;
            }
            else if(!grille[i][j-3]){
              mes_trois++;
            }
          }
          else if(!grille[i][j-2]){
            //printf("Oui %d && (%d, %d) avec (%d, %d)\n", grille[i][j], i, j, i, j-1);
            mes_deux++;
          }
        }
        if(grille[i-1][j-1] == joueur && grille[i+1][j+1] != joueur && j>0 && i>0){
          if(grille[i-2][j-2] == joueur){
            if(grille[i-3][j-3] == joueur){
              mes_quatre++;
            }
            else if(!grille[i-3][j-3]){
              mes_trois++;
            }
          }
          else if(!grille[i-2][j-2]){
            //printf("Oui %d && (%d, %d) avec (%d, %d)\n", grille[i][j], i, j, i-1, j-1);
            mes_deux++;
          }
        }
        if(grille[i-1][j+1] == joueur && grille[i+1][j-1] != joueur && j<C-1 && i>0){
          if(grille[i-2][j+2] == joueur){
            if(grille[i-3][j+3] == joueur){
              mes_quatre++;
            }
            else if(!grille[i-3][j+3]){
              mes_trois++;
            }
          }
          else if(!grille[i-2][j+2]){
            //printf("Oui %d && (%d, %d) avec (%d, %d)\n", grille[i][j], i, j, i-1, j+1);
            mes_deux++;
          }
        }
      }
      else if(!grille[i][j]){
        if(grille[i][j-1] == joueur && j>0){
          if(grille[i][j-2] == joueur){
            //printf("Oui %d && (%d, %d) avec (%d, %d)\n", grille[i][j], i, j, i, j-1);
            if(grille[i][j-3] == joueur){
              mes_trois++;
            }
            else if(grille[i][j-3] != joueur){
              //printf("Oui %d && (%d, %d) avec (%d, %d)\n", grille[i][j], i, j, i, j-1);
              mes_deux++;
            }
          }
        }
      }
    }
  }
  /*affichePlateau(grille, rien);
  printf("Joueur == %d, score == %d\n", joueur, mes_deux*5+mes_trois*20+mes_quatre*100);
  return mes_deux;*/
  //printf("")
  return mes_deux*5+mes_trois*20+mes_quatre*100;
}

int evaluation(plateau &grille, int joueur){
  placement rien;
  int joueur2 = (joueur == 1) ? 2 : 1;
  //affichePlateau(grille, rien);
  return (getScore(grille, joueur) - getScore(grille, joueur2)) / nbCoups(grille);
}

int bestMove(plateau &grille){
  int best = 0;
  int max = -INFINITY;
  int noeuds = 0;
  for(int i = 0; i<C; i++){
    if(placerJeton(grille, i, 1)){
      int score = -negamax(grille, 6, -INFINITY, INFINITY, 2, noeuds);
      if(finDeJeu(grille)){
        score = INFINITY;
      }
      //printf("%d\n", score);
      enleverJeton(grille, i);
      if(max <= score){
        max = score;
        best = i;
      }
    }
  }
  printf("%d noeuds parcourus\n", noeuds);
  //printf("%d\n", best);
  return best;
}

int negamax(plateau &grille, int profondeur, int alpha, int beta, int joueur, int& noeuds){
  placement rien;
  noeuds++;
  //affichePlateau(grille, rien);
  static int prof = profondeur;
  int joueur2 = (joueur == 1) ? 2 : 1;
  if (profondeur == 0 || finDeJeu(grille)){
    return evaluation(grille, joueur);
  }
  //int max = -INFINITY;
  /*if(prof == profondeur){
    for(int i = 0; i<C; i++){
      if(placerJeton(grille, i, joueur)){
        if(finDeJeu(grille) == joueur){
          return evaluation(grille, joueur);
        }
        enleverJeton(grille, i);
      }
    }
  }*/
  for(int i = 0; i<C; i++) {
    if(placerJeton(grille, i, joueur)){
      /*if(finDeJeu(grille)){
        affichePlateau(grille, rien);
        return INFINITY;
      }*/
      int score = -negamax(grille, profondeur - 1, -beta, -alpha, joueur2, noeuds);
      enleverJeton(grille, i);
      if (score >= alpha){
        alpha = score ;
        if (alpha>=beta) break;
      }
    }
  }
  return alpha;
}
