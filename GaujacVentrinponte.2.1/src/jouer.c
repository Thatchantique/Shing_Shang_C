#ifndef JOUER_H
#define JOUER_H
#include <sys/types.h>
#include <dirent.h>
#include "I_Plateau.h"
#include <string.h>
#include<stdio.h>
#include <stdlib.h>

void lancer_jeu(int i){
    plateau p;
    int err=1;
    if(i==0)
      Initialise_Plateau(&p);
      else{
      lister_fichier();
      printf("Quel fichier charger ?\n");
      char fichier[20];
      scanf("%s", fichier);
      char dir[50]="./Configurations/";
      strcat(dir,fichier);
      initialise_depuis_fichier(dir, &p);
      }

    /*system("clear");*/
    system_clear_linux();
    Position p1;
    Position p2;

    
   unsigned int couleur_joueur=ROUGE;
   /*int  val = deplace_singe(&p, p1, p2);*/
    int Continue=1;
    int condition_x=0;
    int condition_y=0;
    int rej=0;
	rej=rej;
    while(Continue){
        system_clear_linux();
        affiche_plateau(p);

        if (couleur_joueur==BLEU)
            printf("Tour du joueur BLEU Donner les positions initiales\n");
        else
            printf("Tour du joueur ROUGE Donner les positions initiales\n");

        do{
	    printf("Donner la ligne (x) ou saisissez 99 pour sauvegarder:");
	    scanf("%d",&p1.x);
	         if( ( p1.x >=10 && p1.x !=99 ) ||  p1.x <0 )
  		    condition_x=1;
		 else
   		    condition_x=0;
        }while(condition_x);
	if(p1.x == 99){
        save_file(&p);
        break;
        }
        do{
	    printf("Donner la colonne (y):");
	    scanf("%d",&p1.y);
	         if((p1.y>=10 && p1.y != 99 ) ||  p1.y <0 )
  		    condition_y=1;
		 else
   		    condition_y=0;
        }while(condition_y);

        while( p.echiquier[p1.x][p1.y].couleur!=couleur_joueur) {
            printf("Vous n'avez pas l'autorisation de prendre ce pion :\n");
            printf("Redonner la ligne (x) :");
            scanf("%d", &p1.x);
            printf("Redonner la colonne (y) :");
            scanf("%d", &p1.y);
        }
      do{
      if(err==0)
        printf("Redonner les positions finales\n");
      else
        printf("Donner les positions finales\n");

	condition_y=0;
	condition_x=0;

	do{
	    printf("Donner la ligne (x):");
	    scanf("%d",&p2.x);
	         if((p2.x>=10 && p2.x != 99 ) ||  p1.x <0 )
  		    condition_x=1;
		 else
   		    condition_x=0;
        }while(condition_x);

        do{
	    printf("Donner la colonne (y):");
	    scanf("%d",&p2.y);
	         if((p2.y>=10 && p2.y != 99 ) ||  p2.y <0 )
  		    condition_y=1;
		 else
   		    condition_y=0;
        }while(condition_y);

        if (p.echiquier[p1.x][p1.y].role==SINGE){
            err=deplace_singe(&p, p1, p2);
        }
        if (p.echiquier[p1.x][p1.y].role==LION){
            err=deplace_lion(&p, p1, p2);
		if(err==2){
		rej=2;
		}
	        else
		rej=0;
        } else
	   rej=0;
        if (p.echiquier[p1.x][p1.y].role==DRAGON){
            err=deplace_dragon(&p,p1,p2);
        }
        }while(err==0);
        if (est_gagne(&p)==0)
        {
          Continue=1;
        }
	else {
           affiche_plateau(p);
           if (est_gagne(&p)==1){
             printf ("Le joueur bleu a gagné !\n");
           }
           else {
             printf ("Le joueur rouge a gagné !\n");
           }
          Continue=0;
        }


        if (couleur_joueur==BLEU && rej!=2){
            couleur_joueur=ROUGE;
        }
        if (couleur_joueur==ROUGE && rej!=2){
            couleur_joueur=BLEU;
        }
    }
}

int est_gagne(plateau *p)
{
 int nb_pions_bleu=0, nb_pions_rouge=0, i, j;
    if (p->echiquier[1][4].role==DRAGON || p->echiquier[1][5].role==DRAGON){
        return 1;
    }
    if (p->echiquier[8][4].role==DRAGON || p->echiquier[8][5].role==DRAGON){
        return 2;
    }

    for (i=0;i<p->nb_lignes;i++){
        for (j=0;j<p->nb_colonnes;j++){
            if(p->echiquier[i][j].couleur==ROUGE){
            nb_pions_rouge++;
            }
            if(p->echiquier[i][j].couleur==BLEU){
            nb_pions_bleu++;
            }
        }
    }
    if (nb_pions_bleu==0){
    return 2;
    }
    if (nb_pions_rouge==0){
    return 1;
    }
    return 0;
}

void lister_fichier()
{
    struct dirent *lecture;
    DIR *rep;
    rep = opendir("./Configurations" );
    while ((lecture = readdir(rep))) {
        printf("%s\n", lecture->d_name);
    }
    closedir(rep);
}

void system_clear_linux(){
printf("\033[H\033[2J");
}

#endif
