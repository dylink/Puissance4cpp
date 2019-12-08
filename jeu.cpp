#include "plateau.hpp"

static struct termios g_old_kbd_mode;

static void old_attr(void){
    tcsetattr(0, TCSANOW, &g_old_kbd_mode);
}


void jeu(){
  plateau grille;
  placement place;
  int joueur = 1;
  initPlateau(grille);
  choixPlacement(place);
  int j = 0;
  place[0] = joueur;
  system("clear");
  while(!finDeJeu(grille)){
    affichePlateau(grille, place);
    printf("Au tour du joueur %d\n\n", joueur);
    printf("Veuillez choisir votre emplacement\n\n");
    printf("d = déplacer à droite\t q = déplacer à gauche\t v = confirmer\n");

    /* La partie qui suit vient d'un bout de code prit sur internet */

    static char init;
    struct termios new_kbd_mode;

    if(init)
        return;
    tcgetattr(0, &g_old_kbd_mode);
    memcpy(&new_kbd_mode, &g_old_kbd_mode, sizeof(struct termios));

    new_kbd_mode.c_lflag &= ~(ICANON | ECHO);
    new_kbd_mode.c_cc[VTIME] = 0;
    new_kbd_mode.c_cc[VMIN] = 1;
    tcsetattr(0, TCSANOW, &new_kbd_mode);
    atexit(old_attr);

    char saisie = getchar();

    /*Il permet de ne pas avoir à appuyer sur entrée à chaque saisie*/

    if(((saisie != 'q') && (saisie != 'd') && (saisie != 'v'))) {
      system("clear");
      break;
    }

    switch(saisie){
      case 'd' : if(j<C-1){
        place[j] = 0; j+=1; place[j] = joueur;}
        system("clear");
        break;
      case 'q' : if(j>0){
        place[j] = 0; j-=1; place[j] = joueur;}
        system("clear");
        break;
      case 'v' :
        if(placerJeton(grille, j, joueur)){
          place[j] = 0; j = 0;
          joueur = (joueur==1) ? 2 : 1;
          place[j] = joueur;
          system("clear");
        }
        else{
          system("clear");
          printf("Cette colonne est déjà remplie\n");
        }; break;
    }
  }
  place[0] = 0;
  affichePlateau(grille, place);
}
