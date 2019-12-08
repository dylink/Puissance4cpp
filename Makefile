
Puissance4: main.o plateau.o jeu.o fonctions.o
	g++ -std=c++17 -Wall -o Puissance4 main.o plateau.o jeu.o fonctions.o

main.o: main.cpp plateau.cpp jeu.cpp fonctions.cpp plateau.hpp
	g++ -std=c++17 -Wall -o main.o -c main.cpp

plateau.o: plateau.cpp plateau.hpp
	g++ -std=c++17 -Wall -o plateau.o -c plateau.cpp

jeu.o: jeu.cpp plateau.hpp
	g++ -std=c++17 -Wall -o jeu.o -c jeu.cpp

fonctions.o: fonctions.cpp plateau.hpp
	g++ -std=c++17 -Wall -o fonctions.o -c fonctions.cpp

clean:
	rm -v -f *.o *~core
mrproper: clean
	rm -v -f Puzzle
