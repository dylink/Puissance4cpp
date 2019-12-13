#include "plateau.hpp"

using namespace std;

int placerJeton(plateau grille, int j, int joueur){
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

int enleverJeton(plateau grille, int j){
  for(int i = 0; i<L; i++){
    if(grille[i][j]){
      grille[i][j] = 0;
      return 1;
    }
  }
  return 0;
}

int nbCoups(plateau grille){
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

int finDeJeu(plateau grille){
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


int checkDiagD(plateau grille ,int joueur){
  int joueur2 = (joueur == 1) ? 2 : 1;
  int score = 0, nbJetons = 0, nbJetonsVS = 0;
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
      switch(nbJetons){
        case 1 : score += 1; break;
        case 2 : score += 10; break;
        case 3 : score += 1000; break;
      }
      switch(nbJetonsVS){
        case 1 : score += -1; break;
        case 2 : score += -10; break;
        case 3 : score += -500; break;
      }
      nbJetons = 0, nbJetonsVS = 0;
    }
  }
  return score;
}

int checkDiagG(plateau grille ,int joueur){
  int joueur2 = (joueur == 1) ? 2 : 1;
  int score = 0, nbJetons = 0, nbJetonsVS = 0;
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

      switch(nbJetons){
        case 1 : score += 1; break;
        case 2 : score += 10; break;
        case 3 : score += 1000; break;
      }
      switch(nbJetonsVS){
        case 1 : score += -1; break;
        case 2 : score += -10; break;
        case 3 : score += -500; break;
      }
      nbJetons = 0, nbJetonsVS = 0;
    }
  }
  return score;
}

int checkHori(plateau grille ,int joueur){
  int joueur2 = (joueur == 1) ? 2 : 1;
  int score = 0, nbJetons = 0, nbJetonsVS = 0;
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
      switch(nbJetons){
        case 1 : score += 1; break;
        case 2 : score += 6;  break;
        case 3 : score += 1000; break;
      }
      switch(nbJetonsVS){
        case 1 : score += -1; break;
        case 2 : score += -10; break;
        case 3 : score += -500; break;
      }
      nbJetons = 0, nbJetonsVS = 0;
    }
  }
  return score;
}

int checkVert(plateau grille ,int joueur){
  int joueur2 = (joueur == 1) ? 2 : 1;
  int score = 0, nbJetons = 0, nbJetonsVS = 0;
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
      switch(nbJetons){
        case 1 : score += 1; break;
        case 2 : score += 10; break;
        case 3 : score += 1000; break;
      }
      switch(nbJetonsVS){
        case 1 : score += -1; break;
        case 2 : score += -10; break;
        case 3 : score += -500; break;
      }
      nbJetons = 0, nbJetonsVS = 0;
    }
  }
  return score;
}

int eval(plateau grille, int joueur){
  int joueur2 = (joueur == 1) ? 2 : 1;
  if(finDeJeu(grille) == joueur){
    return 100000;
  }
  else if(finDeJeu(grille) == joueur2){
    return -100000;
  }
  return checkDiagG(grille, joueur) + checkDiagD(grille, joueur) + checkHori(grille, joueur) + checkVert(grille, joueur);
}

int negamax(plateau grille, int profondeur, int alpha, int beta, int joueur, int& noeuds, std::mutex &myMutex){
  noeuds++;
  int joueur2 = (joueur == 1) ? 2 : 1;
  if (profondeur == 0 || finDeJeu(grille)){
    return eval(grille, joueur);
  }
  for(int i = 0; i<C; i++) {
    if(placerJeton(grille, i, joueur)){
      int score = -negamax(grille, profondeur - 1, -beta, -alpha, joueur2, noeuds, myMutex);
      enleverJeton(grille, i);
      if (score >= alpha){
        alpha = score ;
        if (alpha>=beta) break;
      }
    }
  }
  return alpha;
}

int bestMove(plateau grille, int profondeur, int debut, int fin, vector<pair<int, int>> &result, std::mutex &myMutex){
  placement rien;
  pair<int, int> a;
  int best = 0;
  int max = -99999999;
  int noeuds = 0;
  for(int i = debut; i<fin; i++){
    myMutex.lock();
    if(placerJeton(grille, i, 2)){
      affichePlateau(grille, rien);
      if(finDeJeu(grille) == 2){
        enleverJeton(grille, i);
        a.first = max;
        a.second = i;
        max = 99999999;
        result.push_back(a);
        myMutex.unlock();
        return i;
      }
      enleverJeton(grille, i);
    }
    myMutex.unlock();
  }
  for(int i = debut; i<fin; i++){
    myMutex.lock();
    if(placerJeton(grille, i, 1)){
      if(finDeJeu(grille) == 1){
        enleverJeton(grille, i);
        max = 99999999;
        a.first = max;
        a.second = i;
        result.push_back(a);
        myMutex.unlock();
        return i;
      }
      int score = -negamax(grille, profondeur, -99999999, 99999999, 2, noeuds, myMutex);
      if(max < score){
        max = score;
        best = i;
      }
      myMutex.unlock();
    }
    enleverJeton(grille, i);
  }
  myMutex.lock();
  a.first = max;
  a.second = best;
  result.push_back(a);
  myMutex.unlock();
  return best;
}

int threads(plateau grille, int n, int profondeur){
  std::mutex myMutex;
  int max = -99999999;
  int best = 0;
  vector<pair<int, int>> results;
  vector<thread> vect;                                                       //Déclaration d'un vecteur de threads
  for(int i = 0; i<n; i++){
    float debut = (float(i)*(float(C)/float(n)));                                         //Déclaration du début de l'intervalle
    float fin = debut + float(C)/float(n);                                        //Déclaration du seuil de l'intervalle
    int d = ceil(debut);
    int f = ceil(fin);
    vect.push_back(thread(bestMove, grille, profondeur, d, f, ref(results), ref(myMutex)));            //Insertion des threads dans le vecteur
  }
  for(thread &t : vect){
    t.join();                                                                //Fermeture des threads
  }
  for(auto f : results){
    if(max < f.first){
      max = f.first;
      best = f.second;
    }
  }
  return best;
}
