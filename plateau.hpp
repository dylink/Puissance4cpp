#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <sys/time.h>
#include <termios.h>

///Nombre de lignes
#define L 15
///Nombre de colonnes
#define C 15
//Le tableau doit faire au minimum une taille de 10x5

///Création d'un type "plateau" de taille C*L
typedef int plateau[L][C];
typedef int placement[C];

/*																			Fonctions de plateau																		*/

///Initialise le plateau
void initPlateau(plateau &grille);
///Affiche le plateau
void affichePlateau(plateau &grille, placement &place);

void jeu();

int placerJeton(plateau &grille, int, int);

void choixPlacement(placement &place);

int finDeJeu(plateau &grille);
