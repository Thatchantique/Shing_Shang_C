CC=gcc
CFLAGS=-fPIC -g -Wall -Wextra -ansi 
LDFLAGS=
EXEC=projet
HEADER=-I./headers

all: $(EXEC)

projet: ./bin/accueil.o ./bin/Aff_Plateau.o ./bin/I_Plateau.o ./bin/jouer.o ./bin/main.o  ./bin/pose_pion.o ./bin/verifier_possibilite.o
	$(CC) -o $@ $^ $(LDFLAGS) $(HEADER)

./bin/accueil.o: ./src/accueil.c
	$(CC) -o $@ -c $< $(CFLAGS) $(HEADER)

./bin/main.o: ./src/main.c
	$(CC) -o $@ -c $< $(CFLAGS) $(HEADER)

./bin/Aff_Plateau.o: ./src/Aff_Plateau.c
	$(CC) -o $@ -c $< $(CFLAGS) $(HEADER)

./bin/I_Plateau.o: ./src/I_Plateau.c
	$(CC) -o $@ -c $< $(CFLAGS) $(HEADER)

./bin/jouer.o: ./src/jouer.c
	$(CC) -o $@ -c $< $(CFLAGS) $(HEADER)

./bin/pose_pion.o: ./src/pose_pion.c
	$(CC) -o $@ -c $< $(CFLAGS) $(HEADER)

./bin/verifier_possibilite.o: ./src/verifier_possibilite.c
	$(CC) -o $@ -c $< $(CFLAGS) $(HEADER)

clean:
	rm -rf ./bin/*.o

mrproper: clean
	rm -rf $(EXEC)
