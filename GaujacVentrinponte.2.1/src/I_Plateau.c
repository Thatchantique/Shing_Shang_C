#ifndef PLATEAU_H
#define PLATEAU_H
#include <stdio.h>

#include "I_Plateau.h"
#include<string.h>
#include <stdlib.h>
#define TAILLE_MAX 1000

void Initialise_Plateau(plateau *p){
	int i,j;
    	p->nb_lignes=10;
    	p->nb_colonnes=10;
    	int nb_lignes=p->nb_lignes;
    	int nb_colonnes=p->nb_colonnes;

    	p->echiquier=(Pion**) malloc(nb_lignes*sizeof(Pion*));

    	for (i=0;i<nb_lignes;i++){
        	p->echiquier[i]=(Pion*)malloc(nb_colonnes*sizeof(Pion));
    	}

    	Pion case_vide;
    	case_vide.couleur=VIDE;
    	case_vide.role=RIEN;

    	Pion case_ina;
    	case_ina.couleur=NEUTRE;
    	case_ina.role=INA;

    	for (i=0;i<4;i++){
        	for (j=0;j<nb_colonnes;j++){
            		if (j==0 || j==nb_colonnes-1){
                		p->echiquier[i][j]=case_ina;
            		}
            		else {
                		p->echiquier[i][j]=case_vide;
            		}

        	}
    	}
    	for (i=4;i<nb_lignes-4;i++){
        	for (j=0;j<nb_colonnes;j++){
            		p->echiquier[i][j]=case_vide;
	        }
    	}
    	for (i=nb_lignes-4;i<nb_lignes;i++){
        	for (j=0;j<nb_colonnes;j++){
            		if (j==0 || j==nb_colonnes-1){
                		p->echiquier[i][j]=case_ina;
            		}
            		else {
                		p->echiquier[i][j]=case_vide;
            		}
        	}
    	}

    	Pion case_but;
    	case_but.couleur=VIDE;
    	case_but.role=BUT;

    	Pion pion_dragon1;
    	pion_dragon1.couleur=ROUGE;
    	pion_dragon1.role=DRAGON;

    	Pion pion_lion1;
    	pion_lion1.couleur=ROUGE;
    	pion_lion1.role=LION;

    	Pion pion_singe1;
    	pion_singe1.couleur=ROUGE;
    	pion_singe1.role=SINGE;
	
   	Pion pion_dragon2;
    	pion_dragon2.couleur=BLEU;
    	pion_dragon2.role=DRAGON;

    	Pion pion_lion2;
    	pion_lion2.couleur=BLEU;
    	pion_lion2.role=LION;

    	Pion pion_singe2;
    	pion_singe2.couleur=BLEU;
    	pion_singe2.role=SINGE;

/*1er joueur*/
    
	p->echiquier[0][1]=pion_dragon1;
    	p->echiquier[0][nb_colonnes-2]=pion_dragon1;
    	p->echiquier[0][2]=pion_lion1;
    	p->echiquier[0][nb_colonnes-3]=pion_lion1;
    	p->echiquier[1][1]=pion_lion1;
    	p->echiquier[1][nb_colonnes-2]=pion_lion1;
	
    	p->echiquier[0][3]=pion_singe1;
    	p->echiquier[0][nb_colonnes-4]=pion_singe1;
    	p->echiquier[1][2]=pion_singe1;
    	p->echiquier[1][nb_colonnes-3]=pion_singe1;
    	p->echiquier[2][1]=pion_singe1;
    	p->echiquier[2][nb_colonnes-2]=pion_singe1;
	
/*2e joueur*/
    	p->echiquier[nb_lignes-1][1]=pion_dragon2;
    	p->echiquier[nb_lignes-1][nb_colonnes-2]=pion_dragon2;
    	p->echiquier[nb_lignes-2][1]=pion_lion2;
    	p->echiquier[nb_lignes-1][2]=pion_lion2;
    	p->echiquier[nb_lignes-2][nb_colonnes-2]=pion_lion2;
    	p->echiquier[nb_lignes-1][nb_colonnes-3]=pion_lion2;
    	p->echiquier[nb_lignes-3][1]=pion_singe2;
    	p->echiquier[nb_lignes-2][2]=pion_singe2;
    	p->echiquier[nb_lignes-1][3]=pion_singe2;
    	p->echiquier[nb_lignes-3][nb_colonnes-2]=pion_singe2;
    	p->echiquier[nb_lignes-2][nb_colonnes-3]=pion_singe2;
    	p->echiquier[nb_lignes-1][nb_colonnes-4]=pion_singe2;
	
/*But*/
    	p->echiquier[1][4]=case_but;
    	p->echiquier[1][5]=case_but;
    	p->echiquier[nb_lignes-2][4]=case_but;
    	p->echiquier[nb_lignes-2][5]=case_but;
	
}	

/* Ouvrir un plateau depuis un fichier / Lancer une sauvegarde */
void initialise_depuis_fichier(char * nomfichier, plateau *p){
    	FILE * fichier=NULL;
    	int i=0,j;
    	fichier=fopen( nomfichier,"r");
    	char ligne[TAILLE_MAX]="";
    	int nb_lignes, nb_colonnes;
    	fscanf(fichier, "%d %d",&nb_lignes, &nb_colonnes);
    	p->nb_lignes=nb_lignes;
    	p->nb_colonnes=nb_colonnes;
    	
/**allocation dynaqmique*/

    	p->echiquier=(Pion**)malloc(nb_lignes*sizeof(Pion*));

    	for (i=0;i<nb_lignes;i++){
        	p->echiquier[i]=(Pion*)malloc(nb_colonnes*sizeof(Pion));
    	}
    	
	i=0;

    /***Création des types de pions*/
    	Pion case_vide;
    	case_vide.couleur=VIDE;
    	case_vide.role=RIEN;

    	Pion case_ina;
    	case_ina.couleur=NEUTRE;
    	case_ina.role=INA;
	
    	Pion case_but;
    	case_but.couleur=VIDE;
    	case_but.role=BUT;
	
    	Pion pion_dragon1;
    	pion_dragon1.couleur=ROUGE;
    	pion_dragon1.role=DRAGON;
	
    	Pion pion_lion1;
    	pion_lion1.couleur=ROUGE;
    	pion_lion1.role=LION;
	
    	Pion pion_singe1;
    	pion_singe1.couleur=ROUGE;
    	pion_singe1.role=SINGE;
	
    	Pion pion_dragon2;
    	pion_dragon2.couleur=BLEU;
    	pion_dragon2.role=DRAGON;
	
    	Pion pion_lion2;
    	pion_lion2.couleur=BLEU;
    	pion_lion2.role=LION;
	
    	Pion pion_singe2;
    	pion_singe2.couleur=BLEU;
    	pion_singe2.role=SINGE;
	
    	if (fichier!=NULL){
    	    fgets(ligne,TAILLE_MAX,fichier);
    	    while(fgets(ligne,TAILLE_MAX,fichier)!=NULL && i < nb_lignes){
    	        for (j=0; j<nb_colonnes;j++){
    	            if (ligne[j]=='S')
    	                p->echiquier[i][j]=pion_singe1;
    	            if (ligne[j]=='D')
    	                p->echiquier[i][j]=pion_dragon1;
    	            if (ligne[j]=='L')
    	                p->echiquier[i][j]=pion_lion1;
    	            if (ligne[j]=='s')
			p->echiquier[i][j]=pion_singe2;
	                if (ligne[j]=='d')
	                    p->echiquier[i][j]=pion_dragon2;
	                if (ligne[j]=='l')
	                    p->echiquier[i][j]=pion_lion2;
	                if (ligne[j]=='B')
	                    p->echiquier[i][j]=case_but;
	                if (ligne[j]=='/')
	                    p->echiquier[i][j]=case_ina;
	                if (ligne[j]=='.')
	                    p->echiquier[i][j]=case_vide;
	            }
	            i++;
        	}
    	}
    	else {
        	printf("erreur d'ouverture \n");
    	}
    	fclose(fichier);
}

void save_file(plateau *p){
	char  dir_fichier[35];
	char  nom[25];
	int i,j,choix=2;
	FILE * f =NULL;
	do{
		memcpy(dir_fichier,"./Configurations/",35);
	    	memcpy(nom," ",1);
	    	printf("Entrez le nom du fichier à sauvegarder.\n");

	    	scanf("%s", nom);
	    	strcat(dir_fichier,nom);
	    	strcat(dir_fichier,".txt");
	
	   	f= fopen(dir_fichier,"r");
	     	if( f!=NULL){
			printf("Voulez-vous remplacer le fichier ? (tapez autre chose que 2)\nVoulez-vous remplacer le nom ? (tapez 2)");
			scanf("%d",&choix);
			fclose(f);
	     	}
	} while(f!=NULL && choix==2);

	f = fopen(dir_fichier,"w+");
	if (f!=NULL){
		fprintf(f, "%d %d\n", p->nb_lignes,p->nb_colonnes);

		for (i=0;i<p->nb_lignes;i++){
			for (j=0;j<p->nb_colonnes;j++){
				if(p->echiquier[i][j].couleur==ROUGE){
				        if(p->echiquier[i][j].role==SINGE)
			         	{
			         		fprintf(f,"%c",'S');
			         	}
			          	if(p->echiquier[i][j].role==LION)
			         	{
			         		fprintf(f,"%c",'L');
			         	}
			         	if(p->echiquier[i][j].role==DRAGON)
			         	{
			         		fprintf(f,"%c",'D');
			         	}
			    	}	
			    	if(p->echiquier[i][j].couleur==BLEU){
			        	if(p->echiquier[i][j].role==SINGE)
			        	{
			        		fprintf(f,"%c",'s');
			        	}
			         	if(p->echiquier[i][j].role==LION)
			         	{
			         		fprintf(f,"%c",'l');
			         	}
			         	if(p->echiquier[i][j].role==DRAGON)
			         	{
			         		fprintf(f,"%c",'d');
			         	}
			    	}
			    	if(p->echiquier[i][j].role==BUT){
			    		fprintf(f,"%c",'B');
			    	}
			    	if(p->echiquier[i][j].role==RIEN){
			    		fprintf(f,"%c",'.');
			    	}
			    	if(p->echiquier[i][j].role==INA){
			    		fprintf(f,"%c",'/');
			    	}
			}
			fprintf(f,"\n");
		}
		fclose(f);
		printf("La configuration est sauvegardée\n");
	}	
	else{
		printf("fichier n'existe pas \n");
	}

}

#endif

