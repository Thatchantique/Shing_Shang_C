#ifndef PLATEAU_H
#define PLATEAU_H

#include "I_Plateau.h"
#include <stddef.h>
#include<stdio.h>
#include <stdlib.h>
#define couleur(param) printf("\033[%sm",param);

void affiche_plateau(plateau p){
    int i,j;
    int nb_lignes=p.nb_lignes;
    int nb_colonnes=p.nb_colonnes;
    printf("   ");
    for (i=0;i<nb_lignes;i++){
        printf("%d  ",i);
    }
    printf("\n");
    for (i=0;i<nb_lignes;i++){
        printf("| ");
        for (j=0;j<nb_colonnes;j++){
            if (p.echiquier[i][j].couleur==BLEU && p.echiquier[i][j].role==SINGE){
                printf(" ");
                couleur("34");
                printf("S ");
                couleur("0");
            }
            if (p.echiquier[i][j].couleur==BLEU && p.echiquier[i][j].role==LION){
                printf(" ");
                couleur("34");
                printf("L ");
                couleur("0");
            }
            if (p.echiquier[i][j].couleur==BLEU && p.echiquier[i][j].role==DRAGON){
                printf(" ");
                couleur("34");
                printf("D ");
                couleur("0");
            }

            if (p.echiquier[i][j].couleur==ROUGE && p.echiquier[i][j].role==SINGE){
                printf(" ");
                couleur("31");
                printf("S ");
                couleur("0");
            }
            if (p.echiquier[i][j].couleur==ROUGE && p.echiquier[i][j].role==LION){
                printf(" ");
                couleur("31");
                printf("L ");
                couleur("0");
            }
            if (p.echiquier[i][j].couleur==ROUGE && p.echiquier[i][j].role==DRAGON){
                printf(" ");
                couleur("31");
                printf("D ");
                couleur("0");
            }
            if (p.echiquier[i][j].couleur==VIDE && p.echiquier[i][j].role==BUT){
                printf(" ");
                couleur("0");
                printf("B ");
                couleur("0");
            }
            if (p.echiquier[i][j].couleur==VIDE && p.echiquier[i][j].role==RIEN){
                printf(" ");
                couleur("0");
                printf("%d ", p.echiquier[i][j].role);
                couleur("0");
            }
            if (p.echiquier[i][j].couleur==NEUTRE){
                printf(" / ");
            }

        }
        printf(" | %d\n", i);
        couleur("0");
    }
}
#endif
