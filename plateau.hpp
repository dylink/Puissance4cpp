#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <sys/time.h>
#include <termios.h>
#include <unistd.h>
#include <vector>
#include <utility>
#include <iostream>
#include <thread>
#include <mutex>
#include <math.h>


///Nombre de lignes
#define L 6
///Nombre de colonnes
#define C 7

///Création d'un type "plateau" de taille C*L
typedef int plateau[L][C];
typedef int placement[C];

/*																			Fonctions de plateau																		*/

///Initialise le plateau
void initPlateau(plateau grille);
///Affiche le plateau
void affichePlateau(plateau grille, placement place);

void tableauCopie(plateau grille, plateau grille2);

void jeu(int nbThreads, int profondeur);

int eval(plateau grille, int joueur);

int nbCoups(plateau grille);

int placerJeton(plateau grille, int, int);

void choixPlacement(placement place);

int finDeJeu(plateau grille);

int enleverJeton(plateau grille, int j);

int negamax(plateau grille, int profondeur, int alpha, int beta, int joueur, int &noeuds, std::mutex &myMutex);

int bestMove(plateau grille, int profondeur, int debut, int fin, std::vector<std::pair<int,int>> &result, std::mutex &myMutex);

int threads(plateau grille, int n, int profondeur);
