#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#define HAUTEUR 12
#define LONGUEUR 41

#define MUR '#'
#define TETE 'O'
#define CORPS 'x'
#define VIDE ' '
#define FRUIT '@'

// STRUCTURES
typedef struct
{
	int x ;
	int y ;
}Coord;

typedef struct
{
    int taille;
    Coord corps[386];
    Coord tete;
}Serpent;

typedef struct
{
    int x;
    int y;
}Fruit;

//=================== PROTOTYPES ==============================
void afficherNiveau(char niveau[HAUTEUR][LONGUEUR]);
void afficherMenu();
void afficherAide();

// GENERAL
int deplacerSerpent(char, Serpent *, char niveau[HAUTEUR][LONGUEUR]);
int agrandirSerpent(Serpent *, char niveau[HAUTEUR][LONGUEUR]);
int sauvegarderScore(int *);
int sauvegarderTemps(clock_t);

// MODE 1
void initialisationSerpent(Serpent *);
int gameOver(int, clock_t);
int jouerNiveauUn(int *, Serpent, Fruit, char niveau1[HAUTEUR][LONGUEUR], char, int);
void remplirMapUn(char niveau[HAUTEUR][LONGUEUR], Serpent *, Fruit *);
int nvPositionFruit(Fruit *, char niveau[HAUTEUR][LONGUEUR]);

// MODE 2
void initialisationDeux_1(Serpent *, Coord obstacle[30]);
void remplirMapDeux_1(char niveau[HAUTEUR][LONGUEUR], Serpent *, Fruit *, Coord obstacle[30]);
int gameOver2(int);
void jouerNiveauDeux_1(int *, int, int *, char niveau2_1[HAUTEUR][LONGUEUR], Serpent, Fruit, int, Coord obstacle[30]);
void jouerNiveauDeux_2(int *, int, int *, char niveau2_1[HAUTEUR][LONGUEUR], Serpent, Fruit, int, Coord obstacle[30]);
void jouerNiveauDeux_3(int *, int, int *, char niveau2_1[HAUTEUR][LONGUEUR], Serpent, Fruit, int, Coord obstacle[30]);

// MODE 3
int deplacerSerpentATraversMur(char, Serpent *, char niveau[HAUTEUR][LONGUEUR]);
void jouerNiveauTrois(int *, char, int *, char niveau2_1[HAUTEUR][LONGUEUR], Serpent, Fruit, int, Coord obstacle[30], int);

#endif /* DEFINITIONS_H*/
