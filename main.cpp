#include "plateau.hpp"


int main(int argc, char * argv[]){

  if(argc < 3){
    printf("Usage : ./Puissance4 nbThreads depth\n");
    exit(1);
  }
  if(atoi(argv[1]) > C){
    printf("Too much threads : Limit = %d\n", C);
    exit(1);
  }
  printf("\e[2J\e[8;27;100t");
  jeu(atoi(argv[1]), atoi(argv[2]));
  return 0;
}
