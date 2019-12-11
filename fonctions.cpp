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
        if( (grille[i-1][j] == grille[i][j] && grille[i-2][j] == grille[i][j] && grille[i-3][j] == grille[i][j] && i>2) ||
        (grille[i-1][j+1] == grille[i][j] && grille[i-2][j+2] == grille[i][j] && grille[i-3][j+3] == grille[i][j] && j<C-3 && i>2) ||
        (grille[i-1][j-1] == grille[i][j] && grille[i-2][j-2] == grille[i][j] && grille[i-3][j-3] == grille[i][j] && j>2 && i>2) ||
        (grille[i][j+1] == grille[i][j] && grille[i][j+2] == grille[i][j] && grille[i][j+3] == grille[i][j] && j<C-3) ) {
          return grille[i][j];
        }
      }
    }
  }
  if(nbCoups(grille) == C*L){
    return 3;
  }
  return 0;
}


int checkDiagD(plateau &grille ,int joueur){
  int joueur2 = (joueur == 1) ? 2 : 1;
  int score = 0, nbJetons = 0, nbJetonsVS = 0, x = 0, y = 0;
  for(int i = 0; i<L/2; i++){
    for(int j = C/2; j<C; j++){
      if(grille[i][j] == joueur)  nbJetons++;
      else if(grille[i][j] == joueur2)  nbJetonsVS++;
      if(grille[i+1][j-1] == joueur)  nbJetons++;
      else if(grille[i+1][j-1] == joueur2)  nbJetonsVS++;
      if(grille[i+2][j-2] == joueur)  nbJetons++;
      else if(grille[i+2][j-2] == joueur2)  nbJetonsVS++;
      if(grille[i+3][j-3] == joueur)  nbJetons++;
      else if(grille[i+3][j-3] == joueur2)  nbJetonsVS++;
      if(!nbJetons && !nbJetonsVS)  score = 1;
      switch(nbJetons){
        case 1 : score += 2; break;
        case 2 : score += 6; break;
        case 3 : score += 1000; break;
      }
      switch(nbJetonsVS){
        case 1 : score += -4; break;
        case 2 : score += -8; break;
        case 3 : score += -500; break;
      }
      nbJetons = 0, nbJetonsVS = 0;
    }
  }
  return score;
}

int checkDiagG(plateau &grille ,int joueur){
  int joueur2 = (joueur == 1) ? 2 : 1;
  int score = 0, nbJetons = 0, nbJetonsVS = 0, x = 0, y = 0;
  for(int i = 0; i<L/2; i++){
    for(int j = 0; j<=C/2; j++){
      if(grille[i][j] == joueur)  nbJetons++;
      else if(grille[i][j] == joueur2)  nbJetonsVS++;
      if(grille[i+1][j+1] == joueur)  nbJetons++;
      else if(grille[i+1][j+1] == joueur2)  nbJetonsVS++;
      if(grille[i+2][j+2] == joueur)  nbJetons++;
      else if(grille[i+2][j+2] == joueur2)  nbJetonsVS++;
      if(grille[i+3][j+3] == joueur)  nbJetons++;
      else if(grille[i+3][j+3] == joueur2)  nbJetonsVS++;

      if(!nbJetons && !nbJetonsVS)  score = 1;
      switch(nbJetons){
        case 1 : score += 2; break;
        case 2 : score += 6; break;
        case 3 : score += 1000; break;
      }
      switch(nbJetonsVS){
        case 1 : score += -4; break;
        case 2 : score += -8; break;
        case 3 : score += -500; break;
      }
      nbJetons = 0, nbJetonsVS = 0;
    }
  }
  return score;
}

int checkHori(plateau &grille ,int joueur){
  int joueur2 = (joueur == 1) ? 2 : 1;
  int score = 0, nbJetons = 0, nbJetonsVS = 0, x = 0, y = 0;
  for(int i = 0; i<L; i++){
    for(int j = 0; j<=C/2; j++){
      if(grille[i][j] == joueur)    nbJetons++;
      else if(grille[i][j] == joueur2)    nbJetonsVS++;
      if(grille[i][j+1] == joueur)    nbJetons++;
      else if(grille[i][j+1] == joueur2)    nbJetonsVS++;
      if(grille[i][j+2] == joueur)    nbJetons++;
      else if(grille[i][j+2] == joueur2)    nbJetonsVS++;
      if(grille[i][j+3] == joueur)    nbJetons++;
      else if(grille[i][j+3] == joueur2)    nbJetonsVS++;
      if(!nbJetons && !nbJetonsVS)  score = 1;
      switch(nbJetons){
        case 1 : score += 2; break;
        case 2 : score += 6;  break;
        case 3 : score += 1000; break;
      }
      switch(nbJetonsVS){
        case 1 : score += -4; break;
        case 2 : score += -8; break;
        case 3 : score += -500; break;
      }
      //printf("%d && %d && %d\n", joueur, nbJetonsVS, j);
      nbJetons = 0, nbJetonsVS = 0;
    }
  }
  return score;
}

int checkVert(plateau &grille ,int joueur){
  int joueur2 = (joueur == 1) ? 2 : 1;
  int score = 0, nbJetons = 0, nbJetonsVS = 0, x = 0, y = 0;
  for(int i = 0; i<L/2; i++){
    for(int j = 0; j<C; j++){
      if(grille[i][j] == joueur)  nbJetons++;
      else if(grille[i][j] == joueur2)  nbJetonsVS++;
      if(grille[i+1][j] == joueur)  nbJetons++;
      else if(grille[i+1][j] == joueur2)  nbJetonsVS++;
      if(grille[i+2][j] == joueur)  nbJetons++;
      else if(grille[i+2][j] == joueur2)  nbJetonsVS++;
      if(grille[i+3][j] == joueur)  nbJetons++;
      else if(grille[i+3][j] == joueur2)  nbJetonsVS++;
      if(!nbJetons && !nbJetonsVS)  score = 1;
      if(!nbJetons && !nbJetonsVS)  score = 1;
      switch(nbJetons){
        case 1 : score += 2; break;
        case 2 : score += 6; break;
        case 3 : score += 1000; break;
      }
      switch(nbJetonsVS){
        case 1 : score += -4; break;
        case 2 : score += -8; break;
        case 3 : score += -500; break;
      }
      nbJetons = 0, nbJetonsVS = 0;
    }
  }
  return score;
}

int eval(plateau &grille, int joueur){
  int joueur2 = (joueur == 1) ? 2 : 1;
  if(finDeJeu(grille) == joueur){
    return 100000;
  }
  else if(finDeJeu(grille) == joueur2){
    return -100000;
  }
  return checkDiagG(grille, joueur) + checkDiagD(grille, joueur) + checkHori(grille, joueur) + checkVert(grille, joueur);
}

int bestMove(plateau &grille){
  placement rien;
  int best = 0;
  int max = -INFINITY;
  int noeuds = 0;
  //printf("    ");
  for(int i = 0; i<C; i++){
    if(placerJeton(grille, i, 2)){
      if(finDeJeu(grille) == 2){
        enleverJeton(grille, i);
        return i;
      }
      enleverJeton(grille, i);
    }
  }
  for(int i = 0; i<C; i++){
    if(placerJeton(grille, i, 1)){
      if(finDeJeu(grille) == 1){
        printf("Joueur 1 gagne %d\n", i);
        affichePlateau(grille, rien);
        printf("%d\n", finDeJeu(grille));
        enleverJeton(grille, i);
        return i;
      }
      int score = -negamax(grille, 6, -INFINITY, INFINITY, 2, noeuds);
      enleverJeton(grille, i);
      if(max < score){
        max = score;
        best = i;
      }
      printf("max %d && score %d\n", max, score);
    }
  }
  printf("\n%d noeuds parcourus\n", noeuds);
  return best;
}

int negamax(plateau &grille, int profondeur, int alpha, int beta, int joueur, int& noeuds){
  placement rien;
  noeuds++;
  int joueur2 = (joueur == 1) ? 2 : 1;
  if (profondeur == 0 || finDeJeu(grille)){
    return eval(grille, joueur);
  }
  for(int i = 0; i<C; i++) {
    if(placerJeton(grille, i, joueur)){
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
