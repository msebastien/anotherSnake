#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include "definitions.h"

// Initialisation du serpent. On établit sa position initale.
 void initialisationSerpent(Serpent *S)
{
    int i;
    (*S).taille = 3; //Nombre de case qui compose le snake
    (*S).tete.x = 6; //Initialisation de la position x de la tete du snake
    (*S).tete.y = 20; //Initialisation de la position y de la tete du snake

    for (i=0; i < 3; i++)
    {
        (*S).corps[i].x = ((*S).tete.x)-(i+1); //Initialisation de la position x du corps du snake par rapport a la tete
        (*S).corps[i].y = ((*S).tete.y); //Initialisation de la position y du corps du snake par rapport a la tete
    }

}

//La fonction deplacement déplace le serpent. Elle renvoie 1 si le déplacement a pu être effectué, 2 s'il a manger un fruit et 0 s'il ne peut paa bouger (Niveau 1 et 2)
int deplacerSerpent(char touche, Serpent *S, char niveau[HAUTEUR][LONGUEUR])
{
    int etatDeplacement, i;
    if (touche == 'z') // Touche "Avancer"
    {
        if(niveau[((*S).tete.x)-1][(*S).tete.y]!=MUR && niveau[((*S).tete.x-1)][(*S).tete.y]!= CORPS && niveau[((*S).tete.x)-1][(*S).tete.y] != FRUIT) //Quand on ne touche pas un fruit
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
        else if (niveau[(*S).tete.x-1][(*S).tete.y] == FRUIT) //Quand on touche un fruit
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
        else
        {
            etatDeplacement = 0; // Ne peut pas bouger
        }

    }
    else if (touche == 'd') // Touche "Tourner à droite"
    {

        if(niveau[(*S).tete.x][(*S).tete.y+1]!=MUR && niveau[(*S).tete.x][(*S).tete.y+1]!= CORPS && niveau[(*S).tete.x][(*S).tete.y+1]!=FRUIT) //Quand on ne touche pas un fruit
        {

            for (i=(*S).taille-1; i>0; i--)
            {
                (*S).corps[i].x = (*S).corps[i-1].x;
                (*S).corps[i].y = (*S).corps[i-1].y;
            }
            (*S).corps[0].x = (*S).tete.x;
            (*S).corps[0].y = (*S).tete.y;
            (*S).tete.y = (*S).tete.y+1;

            etatDeplacement = 1; // Déplacement effectué
        }
        else if (niveau[(*S).tete.x][(*S).tete.y+1] == FRUIT) //Quand on touche un fruit
        {
            for (i=(*S).taille-1; i>0; i--)
            {
                (*S).corps[i].x=(*S).corps[i-1].x;
                (*S).corps[i].y=(*S).corps[i-1].y;
            }
            (*S).corps[0].x = (*S).tete.x;
            (*S).corps[0].y = (*S).tete.y;
            (*S).tete.y = (*S).tete.y+1;
            etatDeplacement = 2; // Fruit touché
        }
        else
        {
            etatDeplacement = 0; // Ne peut pas bouger
        }

    }

    else if (touche == 'q') // Touche "Aller à gauche"
    {
        if(niveau[(*S).tete.x][(*S).tete.y-1]!=MUR && niveau[(*S).tete.x][(*S).tete.y-1]!= CORPS && niveau[(*S).tete.x][(*S).tete.y-1]!=FRUIT) //Quand on ne touche pas un fruit
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
        else
        {
            etatDeplacement = 0;
        }

    }


    else if (touche == 's') // Touche "Reculer"
    {

        if(niveau[(*S).tete.x+1][(*S).tete.y]!=MUR && niveau[(*S).tete.x+1][(*S).tete.y]!= CORPS && niveau[(*S).tete.x+1][(*S).tete.y]!=FRUIT) //Quand on ne touche pas un fruit
        {
            for (i=(*S).taille-1; i>0; i--)
            {
                (*S).corps[i].x = (*S).corps[i-1].x;
                (*S).corps[i].y = (*S).corps[i-1].y;
            }
            (*S).corps[0].y = (*S).tete.y;
            (*S).corps[0].x = (*S).tete.x;
            (*S).tete.x = ((*S).tete.x)+1;
            etatDeplacement = 1; // Déplacement effectué
        }
        else if (niveau[(*S).tete.x+1][(*S).tete.y]==FRUIT) //Quand on touche un fruit
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
        else
        {
            etatDeplacement = 0; // Ne peut pas bouger
        }

    }
    return etatDeplacement;
}

//Fonction qui permet d'agrandir le serpent

int agrandirSerpent(Serpent *S, char niveau[HAUTEUR][LONGUEUR])
{
    (*S).taille++;
    niveau[(*S).corps[(*S).taille-2].x][(*S).corps[(*S).taille-2].y]=CORPS;

    return 1; // Le serpent a bien été agrandi.
}
