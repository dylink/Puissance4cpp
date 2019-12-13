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
///Effectue une copie du tableau
void tableauCopie(plateau grille, plateau grille2);
///Boucle de jeu principale
void jeu(int nbThreads, int profondeur);
///Evalue la grille
int eval(plateau grille, int joueur);
///Détermine le nombre de jetons sur la grille
int nbCoups(plateau grille);
///Place un jeton sur la grille
int placerJeton(plateau grille, int, int);
///Déclare un tableau vide pour le choix de pièce
void choixPlacement(placement place);
///Détermine s'il y a fin de jeu ou non
int finDeJeu(plateau grille);
///Retire un jeton du plateau
int enleverJeton(plateau grille, int j);
///Algorithme negamax alpha-bêta
int negamax(plateau grille, int profondeur, int alpha, int beta, int joueur, int &noeuds);
///Retourne la meilleure colonne pour l'IA
int bestMove(plateau grille, int profondeur, int debut, int fin, std::vector<std::pair<int,int>> &result, int index);
///Fonction qui répartie les tâches aux threads
int threads(plateau grille, int n, int profondeur);
