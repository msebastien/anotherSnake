#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include "definitions.h"

// Fonction Game Over du mode 1
int gameOver(int etatDeplacement, clock_t TEMPS)
{
    int Option;

    if (etatDeplacement==0) //Si on touche le mur alors game over
    {
        Option = 1;
    }
    else if (((double)TEMPS/CLOCKS_PER_SEC)>40) //Si le temps est écoulé alors game over
    {
        Option = 2;
    }
    else
    {
        Option = 0;
    }
    return Option;
}

// On remplit le plateau/carte avec les murs, les fruits et les espaces vides
void remplirMapUn(char niveau[HAUTEUR][LONGUEUR], Serpent *S, Fruit *F)
{
    int i, j, k;

    for (i=0; i < HAUTEUR; i++) //Description du niveau 1
    {
        for (j=0; j < LONGUEUR; j++)
        {
            if (i==0 || i==(HAUTEUR-1) || j==0 || j==(LONGUEUR-1))
            {
                niveau[i][j] = MUR; //Assigantion des murs sur le plateau
            }
            else if (i == (*F).x && j == (*F).y)
            {
                niveau[i][j] = FRUIT; //Assigantion des fruits sur le plateau
            }
            else
            {
                niveau[i][j] = VIDE; //Assignation du vide sur le plateau
            }
        }
    }
    niveau[(*S).tete.x][(*S).tete.y] = TETE; //Assignation des casses à la tete
    for(k=0; k < (*S).taille-1; k++)
    {
        niveau[(*S).corps[k].x][(*S).corps[k].y] = CORPS; //Assigantion du corps
    }
}

// Fonction exécutant l'ensemble des actions nécessaires au fonctionnment du niveau/mode 1
int jouerNiveauUn(int *score, Serpent S, Fruit F, char niveau1[HAUTEUR][LONGUEUR], char touche, int etatDeplacement)
{
    int estGameOver;
    clock_t temps;
    clock_t tempsDebut = clock();//Debut du temps de l'horloge

    initialisationSerpent(&S); // Initialisation du serpent
    remplirMapUn(niveau1, &S, &F); //Rempli la map du niveau 1
    afficherNiveau(niveau1); //Affiche la map du niveau 1
    nvPositionFruit(&F, niveau1); //Positionne le fruit sur la map 1

    touche = getch(); //On appuie sur une touche pour enclencher la fonction deplacement

    etatDeplacement = deplacerSerpent(touche, &S, niveau1); //Fonction déplacement déclencher quand on bouge
    remplirMapUn(niveau1, &S, &F); //Rempli la map de nouveau aprés s'etre déplacé
    temps = clock() - tempsDebut; //Calcul du temps
    estGameOver = gameOver(etatDeplacement, temps); //Fonction qui déclenche le game over

    system("cls"); //On clean le system

    afficherNiveau(niveau1); //Raffiche le niveau 1
    temps = clock() - tempsDebut; //Calcul du temps
    estGameOver = gameOver(etatDeplacement, temps); //Fonction qui déclenche le game over

    printf("TEMPS: %f",((double) temps/CLOCKS_PER_SEC)); //Affiche le temps sur le plateau

    while(estGameOver == 0)
    {
        if(etatDeplacement == 2)
        {
            agrandirSerpent(&S, niveau1); //Déclenche l'aggrandissement du snake
            nvPositionFruit(&F,niveau1); //Nouvelle position pour le fruit
            (*score)++; //Augmente le score aprés que le fruit soit manger
        }
        touche=getch();  //On appuie sur une touche pour enclencher la fonction deplacement

        system("cls"); //On clean le system

        etatDeplacement = deplacerSerpent(touche, &S, niveau1);  //Fonction déplacement déclencher quand on bouge
        remplirMapUn(niveau1, &S, &F); //Rempli la map du niveau 1
        afficherNiveau(niveau1); //Affiche la map du niveau 1

        temps = clock() - tempsDebut; //Calcul du temps
        printf("TEMPS: %f\n",(double)temps/CLOCKS_PER_SEC); //Affiche le temps sur le plateau

        estGameOver = gameOver(etatDeplacement,temps); //Fonction qui déclenche le game over
    }
    return estGameOver;
}
