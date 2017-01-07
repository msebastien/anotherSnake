#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include "definitions.h"

// Cette fonction sert à afficher le niveau (tableau de caractère)
void afficherNiveau(char niveau[HAUTEUR][LONGUEUR])
{
    int x, y;
    for (x=0; x < HAUTEUR; x++)
    {
        for (y=0; y < LONGUEUR; y++)
        {
            printf("%c", niveau[x][y]);
        }
        printf("\n");
    }
}

// Affichage du menu
void afficherMenu()
{
    printf("----------------------\n");
	printf("| Bienvenue dans Snake |\n");
	printf("----------------------\n\n");
	printf("---------------------------- Menu ----------------------------\n\n");
	printf("1 - Mode 1 : Deplacement manuel dans un labyrinthe\n");
	printf("2 - Mode 2 : Serpent en mouvement\n");
	printf("3 - Mode 3 : Serpent en mouvement a travers les murs\n");
	printf("4 - Aide\n");
	printf("--------------------------------------------------------------\n\n");
	printf("Quel est votre choix?\n");
}

// Procédure générant une position aléatoire pour le fruit
int nvPositionFruit(Fruit *F, char niveau[HAUTEUR][LONGUEUR])
{
    int etat = 0;
    F->x=rand()%HAUTEUR; //Genére un x au hasard
    F->y=rand()%LONGUEUR; // Genere un y au hasard

    while (niveau[(*F).x][(*F).y]==MUR)
    {
        (*F).x=rand()%HAUTEUR;
        (*F).y=rand()%LONGUEUR;
        etat = 1;
    }

    return etat; // Renvoie 1 si les fruits ont bien été placés, 0 sinon.
}

// Affichage de l'aide
void afficherAide()
{
    printf("Bienvenue dans SNAKE\nCette fenetre a pour but de vous expliquer les regles du jeu\n");
    printf("Le but est de deplacer le serpent a l'aider des touches Z(haut), S(bas), Q(gauche), D(droite) afin de manger le plus de fruit possible.\n");
    printf("La partie s'arrete si le serpent se heurte a un mur, un obstacle ou s'il se heurte lui-meme.\n");
    printf("Dans le menu precedent il existe trois version du jeu, la premiere version est la version classique.\n");
    printf("dans la seconde version, la vitesse du serpent augmente lorsque l'on passe au niveau supérieur.\n");
    printf("Le joueur passe au niveau superieur tous les fruits manges\n");
    printf("Enfin, dans la troisieme version le joueur possede des vies et le serpent se déplace à travers les murs.\n");

}
int sauvegarderScore(int *scoreFinal) // Sauvegarde le meilleur score dns un fichier.txt
{
    int score[3];
    FILE*fichier = NULL; // Fichier vide

    fichier = fopen("meilleurs_scores.txt","r"); //Ouvre le fichier texte du meilleur score

    if (fichier != NULL)
    {
        fscanf(fichier, "%d %d %d", &score[0], &score[1], &score[2]);
        fclose(fichier);
    }
    if (*scoreFinal > score[2]) //Remplace le score obtenu par le meilleur score si celui ci est superieur
    {
        if (*scoreFinal > score[1])
        {
            if (*scoreFinal > score[0])
            {
                score[2] = score[1]; //Change les scores
                score[1] = score[0];
                score[0] = *scoreFinal;
            }
            else
            {
                score[2] = score[1];
                score[1] = *scoreFinal;
            }
        }
        else
        {
            score[2] = *scoreFinal;
        }
    }
    fichier = fopen("meilleurs_scores.txt","w+");

    if(fichier != NULL)
    {
        fprintf(fichier, "%d %d %d", score[0], score[1], score[2]); // Sauvegarde les trois meilleurs temps
        printf("MEILLEURS SCORES: %d, %d, %d", score[0], score[1], score[2]); // Affiche les trois meilleurs score
    }
    fclose(fichier); // Ferme le fichier

    return 1; // Score sauvegardé
}

int sauvegarderTemps(clock_t tempsActuel) // Sauvegarde le meilleur tps dans un fichier.txt
{
    double temps[3];
    FILE*fichier = NULL; // Fichier vide

    fichier = fopen("meilleurs_temps.txt","r"); // Ouvre le fichier texte du meilleur

    if (fichier!=NULL)
    {
        fscanf(fichier, "%lf %lf %lf", &temps[0], &temps[1], &temps[2]); // Remplace le temps obtenu par le meilleur temps si celui ci est superieur
        fclose(fichier);
    }

    if ((double)tempsActuel/CLOCKS_PER_SEC > temps[2])
    {
        if ((double)tempsActuel/CLOCKS_PER_SEC > temps[1])
        {
            if ((double)tempsActuel/CLOCKS_PER_SEC > temps[0])
            {
                temps[2] = temps[1]; // Change les temps
                temps[1] = temps[0];
                temps[0] = (double)tempsActuel/CLOCKS_PER_SEC;
            }
            else
            {
                temps[2] = temps[1];
                temps[1] = (double)tempsActuel/CLOCKS_PER_SEC;
            }
        }
        else
        {
            temps[2] = (double)tempsActuel/CLOCKS_PER_SEC;
        }
    }

    fichier = fopen("meilleurs_temps.txt","w+");

    if(fichier != NULL)
    {
        fprintf(fichier,"%lf %lf %lf", temps[0], temps[1], temps[2]); // Sauvegarde les trois meilleurs temps
        printf("MEILLEURS TEMPS: %lf, %lf,%lf", temps[0], temps[1], temps[2]); // Affiche les trois meilleurs temps
    }
    fclose(fichier);
    return 1; // Temps sauvegardé
}

int main()
{
    // DEFINITION DES VARIABLES
    Coord obstacle[30];
    Serpent S;
    Fruit F;
    srand(time(NULL));

    char niveau1[HAUTEUR][LONGUEUR];
    char niveau2_1[HAUTEUR][LONGUEUR];
    char touche;
    char touche2 = 0;
    int choix;
    int choix2 = 1;

    int etatDeplacement = 0;
    int etatDeplacement2 = 0;
    int etatDeplacement3 = 0;
    int estGameOver = 0;
    int estGameOver2 = 0;
    int estGameOver3 = 0;
    int score = 0;
    int score2 = 0;
    int score3 = 0;
    int vie = 3;

    // MENU
    afficherMenu();
    scanf("%d", &choix);
    system("cls");

    if (choix == 1)
    {
        while(choix2 == 1) // MODE 1
        {
            score = 0;
            estGameOver = jouerNiveauUn(&score, S, F, niveau1, touche, etatDeplacement);

            if(estGameOver == 2)
            {
                printf("GAME OVER\n temps expire\n");
                printf("score : %d\n", score);
                printf("Voulez vous continuez? Si oui, appuyez sur 1 sinon appuyez sur 0\n");
                scanf("%d", &choix2);
            }
            else
            {
                printf("GAME OVER\n");
                printf("Votre score est: %d\n",score);
                printf("voulez vous continuez? Si oui appuyez sur 1 sinon appuyer sur 0\n");
                scanf("%d",&choix2);
                system("cls");
            }
        }
    }
    else if (choix == 2) // MODE 2
    {
        char touche;
        clock_t tempsActuel;

        initialisationDeux_1(&S, obstacle); //Initialisation du niveau 2_1
        remplirMapDeux_1(niveau2_1, &S ,&F, obstacle); //Remplie la map 2_1
        nvPositionFruit(&F, niveau2_1); //Place un fruit dans la map 2_3
        afficherNiveau(niveau2_1);//Affiche le niveau 2_1

        jouerNiveauDeux_1(&score2, touche, &estGameOver2, niveau2_1, S, F, etatDeplacement2, obstacle); //Fonction qui execute le niveau 2_1
        tempsActuel=clock(); //Actualise le temps
        if(estGameOver2 == 1)
        {
            printf("GAME OVER");
            printf("\nSCORE:%d\n TEMPS:%lf sec\n", score2, (double)tempsActuel/CLOCKS_PER_SEC);
            sauvegarderScore(&score2);
            system("PAUSE");

        }
        if(score2 >= 3) // Passe au niveau suivant si notre score est egale a 3
        {
            printf("NIVEAU SUIVANT !\n");
            printf("Atteignez un score de 8\n");

            system("PAUSE");
            system("cls");

            initialisationDeux_1(&S,obstacle); //Initialisation du niveau 2_2
            remplirMapDeux_1(niveau2_1,&S,&F,obstacle); //Remplie la map 2_1
            nvPositionFruit(&F,niveau2_1); //Place un fruit dans la map 2_2
            afficherNiveau(niveau2_1); //Affiche le niveau 2_2

            jouerNiveauDeux_2(&score2, touche, &estGameOver2, niveau2_1, S, F, etatDeplacement2, obstacle); //Fonction qui execute le niveau 2_2
            tempsActuel = clock(); //Actualise le temps

            if(estGameOver2 == 1)
            {
                printf("GAME OVER\n");
                printf("\nSCORE:%d\nTEMPS:%lf sec\n", score2, (double)tempsActuel/CLOCKS_PER_SEC);
                sauvegarderScore(&score2);
                system("PAUSE");
            }
            if(score2 >= 8) // Passe au niveau suivant si notre score est egale a 8
            {
                printf("NIVEAU SUIVANT !\n");
                system("PAUSE");
                system("cls");

                printf("Vous êtes pret ?\n");
                system("PAUSE");
                system("cls");

                printf("C'est parti!!!!!!!!!!!!!!!!!!!!\n");
                system("PAUSE");
                system("cls");

                initialisationDeux_1(&S, obstacle); //Initialisation du niveau 2_3
                remplirMapDeux_1(niveau2_1, &S, &F, obstacle); //Remplie la map 2_3
                nvPositionFruit(&F, niveau2_1); //Place un fruit dans la map 2_3
                afficherNiveau(niveau2_1); //Affiche le niveau 2_3

                jouerNiveauDeux_3(&score2, touche, &estGameOver2, niveau2_1, S, F, etatDeplacement2, obstacle); //Fonction qui execute le niveau 2_3
                tempsActuel = clock(); //Actualise le temps

                if(estGameOver2 == 1)
                {
                    printf("GAME OVER");
                    //Affiche le meilleur score et le meilleur temps
                    printf("\nSCORE:%d\nTEMPS:%lf sec\n", score2, (double)tempsActuel/CLOCKS_PER_SEC);

                    sauvegarderScore(&score2); //Sauvegarde le meilleur score
                    printf("\n");
                    sauvegarderTemps(tempsActuel); //Sauvegarde le meilleur temps

                    system("PAUSE");
                }
                else
                {
                    //Affiche le score et le temps du joeur qui fait la partie
                    printf("Votre score est de %d. Votre temps est de %lf sec.", score2, (double)tempsActuel/CLOCKS_PER_SEC);

                    sauvegarderScore(&score2); //Sauvegarde le meilleur score
                    sauvegarderTemps(tempsActuel);//Sauvegarde le meilleur temps
                }
            }
        }
    }
    else if (choix == 3) //MODE 3
    {
        clock_t tempsActuel3; //Affiche le temps
        score3 = 0;

        initialisationDeux_1(&S, obstacle);  //Initialisation du niveau 3

        remplirMapDeux_1(niveau2_1, &S, &F, obstacle); //Rempli l map 3
        nvPositionFruit(&F, niveau2_1); //Place un fruit dans la map 3
        afficherNiveau(niveau2_1); //Affiche le niveau

        tempsActuel3 = clock(); //Actualise le temps
        jouerNiveauTrois(&score3, touche2, &estGameOver3, niveau2_1, S, F, etatDeplacement3, obstacle, vie); //Fonction du niveau 3

        printf("GAME OVER\nSCORE: %d \nTEMPS: %lf", score3, (double)tempsActuel3/CLOCKS_PER_SEC); //Game over qui affiche le score et le temps
    }

    else if(choix == 4) //affichage de l'aide du snake
    {
        afficherAide(); //Declenche la fonction aide
    }
    else
    {
        printf("Cette entrée ne correspond à aucune option existante.");
    }
    return 0;

}
