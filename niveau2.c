#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
#include "definitions.h"

// Fonction Game Over du niveau/mode 2. Elle est aussi utilisée pour le niveau 3 car les conditions sont les mêmes.
int gameOver2(int etatDeplacement2)
{
    int Option;
    if (etatDeplacement2==0)
    {
        Option = 1;
    }
    else
    {
        Option = 0;
    }
    return Option;
}

// Initialisation du niveau/mode 2 avec les obstacles.
void initialisationDeux_1(Serpent *S, Coord obstacle[30])
{
    int i;

    obstacle[0].y = 8;
    obstacle[0].x = 4;

    obstacle[1].y = 8;
    obstacle[1].x = 5;

    obstacle[2].y = 8;
    obstacle[2].x = 9;

    obstacle[3].y = 8;
    obstacle[3].x = 10;

    obstacle[4].y = 19;
    obstacle[4].x = 7;

    obstacle[5].y = 20;
    obstacle[5].x = 7;

    obstacle[6].y = 33;
    obstacle[6].x = 4;

    obstacle[7].y = 39;
    obstacle[7].x = 10;

    (*S).taille = 3; // Initialisation du serpent dans la map2_1
    (*S).tete.x = 6;
    (*S).tete.y = 20;
    (*S).taille = 3;

    for (i=0; i<3; i++)
    {
        (*S).corps[i].x=((*S).tete.x)-(i+1);
        (*S).corps[i].y=((*S).tete.y);
    }

}
void remplirMapDeux_1(char niveau[HAUTEUR][LONGUEUR], Serpent *S, Fruit *F, Coord obstacle[30])
{
    int i, j, k, e;

    // Descritpion du niveau/mode 2
    for (i=0; i < HAUTEUR; i++)
    {
        for (j=0; j < LONGUEUR; j++)
        {
            if (i==0 || i==(HAUTEUR-1) || j==0 || j==(LONGUEUR-1))
            {
                niveau[i][j] = MUR; //Assigantion des murs sur le plateau
            }
            else if (i==(*F).x && j==(*F).y)
            {
                niveau[i][j] = FRUIT;  //Assigantion des fruits sur le plateau
            }
            else
            {
                niveau[i][j] = VIDE; //Assigantion de vide sur le plateau
            }
        }
    }
    niveau[(*S).tete.x][(*S).tete.y] = TETE; //Assignation des casses a la tete

    for(k=0; k<(*S).taille; k++)
    {
        niveau[(*S).corps[k].x][(*S).corps[k].y] = CORPS; //Affiche le corps
    }
    for(e=0; e<8; e++)
    {
        niveau[obstacle[e].x][obstacle[e].y]=MUR; //Affiche obstacle
    }
}

void jouerNiveauDeux_1(int *score2, int touche, int *estGameOver2, char niveau2_1[HAUTEUR][LONGUEUR], Serpent S, Fruit F, int etatDeplacement2, Coord obstacle[30])
{
    while (*estGameOver2 == 0 && (*score2) < 3) //Quand le score est inferieur a 3 on rentre dans le boucle while qui gere le deplacement
    {
        if(_kbhit()) touche = getch(); //Enclenchement d'une touche (Frappe de touche)

        if(touche == 'z')
        {
            etatDeplacement2 = deplacerSerpent(touche,&S,niveau2_1); //Declenche la touche sur laquelle on a appuyé
            *estGameOver2 = gameOver2(etatDeplacement2); //Fonction qui déclenche le game over
            remplirMapDeux_1(niveau2_1, &S, &F, obstacle);  //Rempli la map aprés s'etre déplacé

            system("cls"); //On clean le system
            afficherNiveau(niveau2_1); //Affiche le niveau

            if (etatDeplacement2 == 2)
            {
                agrandirSerpent(&S, niveau2_1); // On agrandit le serpent
                nvPositionFruit(&F, niveau2_1); // On replace aléatoirement un fruit dans le niveau
                (*score2)++; // On augmente le score de +1
            }
            else if (*estGameOver2 == 1)
            {
                break;
            }
            else if((*score2) >= 3)
            {
                break;
            }
        }

        if(touche == 'd')
        {
            etatDeplacement2 = deplacerSerpent(touche, &S, niveau2_1); //Declenche la touche sur laquelle on a appuyé
            *estGameOver2 = gameOver2(etatDeplacement2); //Fonction qui déclenche le game over
            remplirMapDeux_1(niveau2_1,&S,&F,obstacle); //Rempli la map aprés s'etre déplacé

            system("cls"); //On clean le system
            afficherNiveau(niveau2_1); //Affiche le niveau

            if (etatDeplacement2 == 2)
            {
                agrandirSerpent(&S,niveau2_1); //On agrandit le serpent
                nvPositionFruit(&F, niveau2_1); // On replace un fruit aléatoirement
                (*score2)++; // On augmente le score de +1
            }
            else if (*estGameOver2 == 1)
            {
                break;
            }
            else if((*score2) >= 3)
            {
                break;
            }
        }

        if (touche == 's')
        {
            etatDeplacement2 = deplacerSerpent(touche,&S,niveau2_1); //Declenche la touche sur laquelle on a appuyé
            *estGameOver2 = gameOver2(etatDeplacement2); //Fonction qui déclenche le game over
            remplirMapDeux_1(niveau2_1,&S,&F,obstacle); //Rempli la map aprés s'etre déplacé

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
                break;
            }
            else if((*score2) >= 3)
            {
                break;
            }
        }
        if(touche == 'q')
        {
            etatDeplacement2 = deplacerSerpent(touche, &S, niveau2_1); //Declenche la touche sur laquelle on a appuyé
            *estGameOver2 = gameOver2(etatDeplacement2); //Fonction qui déclenche le game over
            remplirMapDeux_1(niveau2_1, &S, &F,obstacle); //Rempli la map aprés s'etre déplacé

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
                break;
            }
            else if((*score2) >= 3)
            {
                break;
            }
        }
        Sleep(200);
    }
}

void jouerNiveauDeux_2(int *score2, int touche, int *estGameOver2, char niveau2_1[HAUTEUR][LONGUEUR], Serpent S, Fruit F, int etatDeplacement2, Coord obstacle[30])
{
    while (*estGameOver2 == 0 && (*score2) < 8) //Quand le score est inferieur a 8 on rentre dans le boucle while qui gere le deplacement
    {
        if(kbhit()) touche = getch();

        if(touche == 'z')
        {
            etatDeplacement2 = deplacerSerpent(touche, &S, niveau2_1); //Declenche la touche sur laquelle on a appuyé
            *estGameOver2 = gameOver2(etatDeplacement2);//Fonction qui déclenche le game over
            remplirMapDeux_1(niveau2_1,&S,&F,obstacle); //Rempli la map aprés s'etre déplacé

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
                break;
            }
            else if((*score2) >= 8)
            {
                break;
            }
        }

        if(touche == 'd')
        {
            etatDeplacement2 = deplacerSerpent(touche, &S, niveau2_1); //Declenche la touche sur laquelle on a appuyé
            *estGameOver2 = gameOver2(etatDeplacement2); //Fonction qui déclenche le game over
            remplirMapDeux_1(niveau2_1, &S, &F, obstacle); //Rempli la map aprés s'etre déplacé

            system("cls"); //On clean le system
            afficherNiveau(niveau2_1); //Affiche le niveau

            if (etatDeplacement2 == 2)
            {
                agrandirSerpent(&S, niveau2_1); //On aggrandi le serpent
                nvPositionFruit(&F,niveau2_1); // On replace un fruit aléatoirement
                (*score2)++; // On augmente le score de +1
            }
            else if (*estGameOver2 == 1)
            {
                break;
            }
            else if((*score2) >= 8)
            {
                break;
            }
        }
        if (touche == 's')
        {
            etatDeplacement2 = deplacerSerpent(touche, &S, niveau2_1); //Declenche la touche sur laquelle on a appuyé
            *estGameOver2 = gameOver2(etatDeplacement2); //Fonction qui déclenche le game over
            remplirMapDeux_1(niveau2_1,&S,&F,obstacle); //Rempli la map aprés s'etre déplacé

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
                break;
            }
            else if((*score2) >= 8)
            {
                break;
            }
        }
        if(touche == 'q')
        {
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
                break;
            }
            else if((*score2) >= 8)
            {
                break;
            }
        }
        Sleep(100);
    }
}


void jouerNiveauDeux_3(int *score2, int touche, int *estGameOver2, char niveau2_1[HAUTEUR][LONGUEUR], Serpent S, Fruit F, int etatDeplacement2, Coord obstacle[30])
{
    while (*estGameOver2 == 0 && (*score2) < 14) //Quand le score est inferieur a 14 on rentre dans le boucle while qui gere le deplacement
    {
        if(kbhit()) touche = getch();

        if(touche == 'z')
        {
            etatDeplacement2 = deplacerSerpent(touche, &S, niveau2_1); //Declenche la touche sur laquelle on a appuyé
            *estGameOver2 = gameOver2(etatDeplacement2); //Fonction qui déclenche le game over
            remplirMapDeux_1(niveau2_1,&S,&F,obstacle); //Rempli la map aprés s'etre déplacé

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
                break;
            }
            else if((*score2) >= 14)
            {
                break;
            }
        }

        if(touche == 'd')
        {
            etatDeplacement2 = deplacerSerpent(touche, &S, niveau2_1); //Declenche la touche sur laquelle on a appuyé
            *estGameOver2 = gameOver2(etatDeplacement2); //Fonction qui déclenche le game over
            remplirMapDeux_1(niveau2_1, &S, &F, obstacle); //Rempli la map aprés s'etre déplacé

            system("cls"); //On clean le system
            afficherNiveau(niveau2_1); //Affiche le niveau

            if (etatDeplacement2 == 2)
            {
                agrandirSerpent(&S, niveau2_1); //On aggrandi le serpent
                nvPositionFruit(&F, niveau2_1);// On replace un fruit aléatoirement
                (*score2)++; // On augmente le score de +1
            }
            else if (*estGameOver2 == 1)
            {
                break;
            }
            else if((*score2) >= 14)
            {
                break;
            }
        }
        if (touche == 's')
        {
            etatDeplacement2 = deplacerSerpent(touche, &S, niveau2_1); //Declenche la touche sur laquelle on a appuyé
            *estGameOver2 = gameOver2(etatDeplacement2); //Fonction qui déclenche le game over
            remplirMapDeux_1(niveau2_1, &S, &F, obstacle); //Rempli la map aprés s'etre déplacé

            system("cls"); //On clean le system
            afficherNiveau(niveau2_1); //Affiche le niveau

            if (etatDeplacement2 == 2)
            {
                agrandirSerpent(&S, niveau2_1); //On agrandit le serpent
                nvPositionFruit(&F,niveau2_1); // On replace un fruit aléatoirement
                (*score2)++; // On augmente le score de +1
            }
            else if (*estGameOver2 == 1)
            {
                break;
            }
            else if((*score2) >= 14)
            {
                break;
            }
        }
        if(touche == 'q')
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
                break;
            }
            else if((*score2) >= 14)
            {
                break;
            }
        }
        Sleep(20);
    }
}

