#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <Windows.h>
#include <stdlib.h>
#include "definitions.h"

// Fonction de déplacement du serpent pour le niveau 3. Le serpent traverse les murs sans déclencher le Game Over.
int deplacerSerpentATraversMur(char touche, Serpent *S, char niveau[HAUTEUR][LONGUEUR])
{
    int etatDeplacement, i;
    if (touche == 'z'){ //Assignation de la touche Z
        if(niveau[((*S).tete.x)-1][(*S).tete.y]!=MUR && niveau[((*S).tete.x-1)][(*S).tete.y]!= CORPS && niveau[((*S).tete.x)-1][(*S).tete.y]!=FRUIT)
        {

            for (i=(*S).taille-1; i>0; i--)
            {
                (*S).corps[i].x = (*S).corps[i-1].x;
                (*S).corps[i].y = (*S).corps[i-1].y;
            }
            (*S).corps[0].x = (*S).tete.x;
            (*S).corps[0].y = (*S).tete.y;
            (*S).tete.x = (*S).tete.x;
            etatDeplacement = 1; // Déplacement effectué



        }
        else if (niveau[(*S).tete.x-1][(*S).tete.y] == FRUIT) // Quand on touche un fruit
        {
            for (i=(*S).taille; i>0; i--)
            {
                (*S).corps[i].x = (*S).corps[i-1].x;
                (*S).corps[i].y = (*S).corps[i-1].y;
            }
            (*S).corps[0].x = (*S).tete.x;
            (*S).corps[0].y = (*S).tete.y;
            (*S).tete.x = (*S).tete.x-1;
            etatDeplacement = 2; // Fruit touché

        }
        else if((*S).tete.x == 0) //Traverse le mur
        {
            for (i=(*S).taille; i>0; i--)
            {
                (*S).corps[i].x = (*S).corps[i-1].x;
                (*S).corps[i].y = (*S).corps[i-1].y;
            }
            (*S).corps[0].x = (*S).tete.x;
            (*S).corps[0].y = (*S).tete.y;
            (*S).tete.x = HAUTEUR-1;

            etatDeplacement = 1; // Déplacement effectué
        }
        else
        {
            for (i=(*S).taille-1; i>0; i--)
            {
                (*S).corps[i].x = (*S).corps[i-1].x;
                (*S).corps[i].y = (*S).corps[i-1].y;
            }
            (*S).corps[0].x = (*S).tete.x;
            (*S).corps[0].y = (*S).tete.y;
            (*S).tete.x = (*S).tete.x-1;
            etatDeplacement = 1; // Déplacement effectué
        }

    }
    else if (touche == 'd') //Assignation de la touche D
    {

        if(niveau[(*S).tete.x][(*S).tete.y+1]!=MUR && niveau[(*S).tete.x][(*S).tete.y+1]!= CORPS && niveau[(*S).tete.x][(*S).tete.y+1]!=FRUIT)
        {

            for (i=(*S).taille-1; i>0; i--)
            {
                (*S).corps[i].x = (*S).corps[i-1].x;
                (*S).corps[i].y = (*S).corps[i-1].y;
            }
            (*S).corps[0].x = (*S).tete.x; // Les 2 dernières cases ne bougent pas.
            (*S).corps[0].y = (*S).tete.y;
            (*S).tete.y = (*S).tete.y+1;

            etatDeplacement = 1; // Déplacement effectué
        }
        else if (niveau[(*S).tete.x][(*S).tete.y+1] == FRUIT) // Quand on touche un fruit
        {
            for (i=(*S).taille-1; i>0; i--)
            {
                (*S).corps[i].x = (*S).corps[i-1].x;
                (*S).corps[i].y = (*S).corps[i-1].y;
            }
            (*S).corps[0].x = (*S).tete.x;
            (*S).corps[0].y = (*S).tete.y;
            (*S).tete.y = (*S).tete.y+1;
            etatDeplacement = 2; // Fruit touché
        }
        else if ((*S).tete.y == LONGUEUR) //Traverse le mur
        {

            for (i=(*S).taille-1; i>0; i--)
            {
                (*S).corps[i].x = (*S).corps[i-1].x;
                (*S).corps[i].y = (*S).corps[i-1].y;
            }
            (*S).corps[0].x = (*S).tete.x;
            (*S).corps[0].y = (*S).tete.y;
            (*S).tete.y = (*S).tete.y-41;
            etatDeplacement = 1; // Déplacement effectué
        }
        else{
            for (i=(*S).taille-1; i>0; i--)
            {
                (*S).corps[i].x = (*S).corps[i-1].x;
                (*S).corps[i].y = (*S).corps[i-1].y;
            }
            (*S).corps[0].x = (*S).tete.x;
            (*S).corps[0].y = (*S).tete.y;
            (*S).tete.y = (*S).tete.y+1;}
            etatDeplacement = 1; // Déplacement effectué

    }

    else if (touche == 'q') //Assignation de la touche Q
    {
        if(niveau[(*S).tete.x][(*S).tete.y-1]!=MUR && niveau[(*S).tete.x][(*S).tete.y-1]!= CORPS && niveau[(*S).tete.x][(*S).tete.y-1]!=FRUIT)
        {

            for (i=(*S).taille-1; i>0; i--)
            {
                (*S).corps[i].x = (*S).corps[i-1].x;
                (*S).corps[i].y = (*S).corps[i-1].y;
            }
            (*S).corps[0].y = (*S).tete.y;
            (*S).corps[0].x = (*S).tete.x;
            (*S).tete.y = ((*S).tete.y)-1;
            etatDeplacement = 1;
        }
        else if (niveau[(*S).tete.x][(*S).tete.y-1] == FRUIT) //Quand on touche un fruit
        {

            for (i=(*S).taille-1; i>0; i--)
            {
                (*S).corps[i].x = (*S).corps[i-1].x;
                (*S).corps[i].y = (*S).corps[i-1].y;
            }
            (*S).corps[0].y = (*S).tete.y;
            (*S).corps[0].x = (*S).tete.x;
            (*S).tete.y = ((*S).tete.y)-1;
            etatDeplacement = 2; //2 correspond à toucher fruit
        }
        else if ((*S).tete.y == 0) //Traverse le mur
        {
             for (i=(*S).taille-1; i>0; i--)
            {
                (*S).corps[i].x=(*S).corps[i-1].x;
                (*S).corps[i].y=(*S).corps[i-1].y;
            }
            (*S).corps[0].y=(*S).tete.y;
            (*S).corps[0].x=(*S).tete.x;
            (*S).tete.y = ((*S).tete.y) + LONGUEUR;
            etatDeplacement = 1;
        }
        else
        {
             for (i=(*S).taille-1; i>0; i--)
            {
                (*S).corps[i].x = (*S).corps[i-1].x;
                (*S).corps[i].y = (*S).corps[i-1].y;
            }
            (*S).corps[0].y = (*S).tete.y;
            (*S).corps[0].x = (*S).tete.x;
            (*S).tete.y = ((*S).tete.y)-1;
        etatDeplacement = 1;
        }

    }


    else if (touche == 's') //Assignation de la touche S
    {

        if(niveau[(*S).tete.x+1][(*S).tete.y]!=MUR && niveau[(*S).tete.x+1][(*S).tete.y]!= CORPS && niveau[(*S).tete.x+1][(*S).tete.y]!=FRUIT)
        {
            for (i=(*S).taille-1; i>0; i--)
            {
                (*S).corps[i].x = (*S).corps[i-1].x;
                (*S).corps[i].y = (*S).corps[i-1].y;
            }
            (*S).corps[0].y = (*S).tete.y;
            (*S).corps[0].x = (*S).tete.x;
            (*S).tete.x = ((*S).tete.x)+1;
            etatDeplacement = 1;
        }
        else if (niveau[(*S).tete.x+1][(*S).tete.y] == FRUIT) //Quand on touche un fruit
        {
            for (i=(*S).taille-1; i>0; i--)
            {
                (*S).corps[i].x = (*S).corps[i-1].x;
                (*S).corps[i].y = (*S).corps[i-1].y;
            }
            (*S).corps[0].y = (*S).tete.y;
            (*S).corps[0].x = (*S).tete.x;
            (*S).tete.x = ((*S).tete.x)+1;

            etatDeplacement = 2; // Fruit touché
        }
        else if ((*S).tete.x == (HAUTEUR-1)) //Traverse le mur
        {
            for (i=(*S).taille-1; i>0; i--)
            {
                (*S).corps[i].x = (*S).corps[i-1].x;
                (*S).corps[i].y = (*S).corps[i-1].y;
            }
            (*S).corps[0].y = (*S).tete.y;
            (*S).corps[0].x = (*S).tete.x;
            (*S).tete.x = ((*S).tete.x)-11;
            etatDeplacement = 1;
        }
        else
        {
            for (i=(*S).taille-1; i>0; i--)
            {
                (*S).corps[i].x = (*S).corps[i-1].x;
                (*S).corps[i].y = (*S).corps[i-1].y;
            }
            (*S).corps[0].y = (*S).tete.y;
            (*S).corps[0].x = (*S).tete.x;
            (*S).tete.x = ((*S).tete.x)+1;
        etatDeplacement = 1;
        }

    }
    return etatDeplacement;
}

void jouerNiveauTrois(int *score2, char touche, int *estGameOver2, char niveau2_1[HAUTEUR][LONGUEUR], Serpent S, Fruit F, int etatDeplacement2, Coord obstacle[30], int vie)
{
    int i;
    while (vie > 0) //On rentre dans le boucle si vie est inferieur a 0 sinon on affiche le game over
    {

        if(kbhit()){
                touche = getch();
        }

        if(touche == 'z'){ //Assignation de la touche Z

            etatDeplacement2 = deplacerSerpent(touche, &S, niveau2_1); //Declenche la touche sur laquelle on a appuyé
            *estGameOver2 = gameOver2(etatDeplacement2); //Fonction qui déclenche le game over
            remplirMapDeux_1(niveau2_1,&S,&F,obstacle); //Rempli la map aprés s'etre déplacé

            system("cls"); //On clean le system
            afficherNiveau(niveau2_1); //Affiche le niveau

            if (etatDeplacement2 == 2)
            {
                agrandirSerpent(&S,niveau2_1); //On aggrandi le serpent
                nvPositionFruit(&F,niveau2_1); // On replace un fruit aléatoirement
                (*score2)++; // On augmente le score de +1
            }
            else if (*estGameOver2 == 1)
            {
                vie--; //Diminue le nombre de vie
                for (i=0; i<6; i++){
                        deplacerSerpentATraversMur(touche, &S, niveau2_1);
                }
            }
             if (vie <0 && *estGameOver2 == 1){
                    break;
             }

        }

        if(touche == 'd') //Assignation de la touche D
        {
            etatDeplacement2 = deplacerSerpent(touche,&S,niveau2_1); //Declenche la touche sur laquelle on a appuyé
            *estGameOver2 = gameOver2(etatDeplacement2); //Fonction qui déclenche le game over
            remplirMapDeux_1(niveau2_1, &S, &F, obstacle); //Rempli la map aprés s'etre déplacé

            system("cls"); //On clean le system
            afficherNiveau(niveau2_1); //Affiche le niveau

            if (etatDeplacement2 == 2)
            {
                agrandirSerpent(&S, niveau2_1); //On aggrandi le serpent
                nvPositionFruit(&F, niveau2_1); // On replace un fruit aléatoirement
                (*score2)++; // On augmente le score de +1
            }
              else if (*estGameOver2 == 1)
            {
                vie--; //Diminue le nombre de vie
                for (i=0; i<6; i++){
                        deplacerSerpentATraversMur(touche, &S, niveau2_1);
                }
            }
            if (vie < 0 && *estGameOver2 == 1){
                    break;
            }
        }
        if (touche == 's') //Assignation de la touche S
        {
            etatDeplacement2 = deplacerSerpent(touche, &S, niveau2_1); //Declenche la touche sur laquelle on a appuyé
            *estGameOver2 = gameOver2(etatDeplacement2); //Fonction qui déclenche le game over
            remplirMapDeux_1(niveau2_1, &S, &F, obstacle); //Rempli la map aprés s'etre déplacé

            system("cls"); //On clean le system
            afficherNiveau(niveau2_1); //Affiche le niveau

            if (etatDeplacement2 == 2)
            {
                agrandirSerpent(&S, niveau2_1); //On aggrandi le serpent
                nvPositionFruit(&F, niveau2_1); // On replace un fruit aléatoirement
                (*score2)++; // On augmente le score de +1
            }
             else if (*estGameOver2 == 1)
            {
                  vie--; //Diminue le nombre de vie
                for (i=0; i<6; i++){
                        deplacerSerpentATraversMur(touche, &S, niveau2_1);
                }

            }
           if (vie <0 && *estGameOver2 == 1){
                break;
           }
        }
        if(touche == 'q') //Assignation de la touche Q
        {
            etatDeplacement2 = deplacerSerpent(touche, &S, niveau2_1); //Declenche la touche sur laquelle on a appuyé
            *estGameOver2 = gameOver2(etatDeplacement2); //Fonction qui déclenche le game over
            remplirMapDeux_1(niveau2_1, &S, &F, obstacle);  //Rempli la map aprés s'etre déplacé

            system("cls"); //On clean le system
            afficherNiveau(niveau2_1); //Affiche le niveau

            if (etatDeplacement2 == 2)
            {
                agrandirSerpent(&S, niveau2_1); //On aggrandi le serpent
                nvPositionFruit(&F, niveau2_1); // On replace un fruit aléatoirement
                (*score2)++; // On augmente le score de +1
            }
              else if (*estGameOver2 == 1)
            {
                 vie--; // Diminue le nombre de vie
                for (i=0; i<6; i++){
                        deplacerSerpentATraversMur(touche, &S, niveau2_1);
                }
            }
             if (vie < 0 && *estGameOver2 == 1){
                    break;
             }
        }
        Sleep(20);
    }
}
