#ifndef PLATEAU_H
#define PLATEAU_H


#include "I_Plateau.h"
#include<stdio.h>
#include <stdlib.h>

int verifier_possibilite(plateau *p, Position p1, Position p2){
    if (p2.x > p->nb_lignes || p2.y >p->nb_colonnes || p1.x >p->nb_lignes || p1.y>p->nb_colonnes  )
    return 0;
    if (p->echiquier[ p1.x ][ p1.y].role==INA || p->echiquier[ p2.x ][ p2.y].role==INA)
    return 0;
    if (p->echiquier[ p1.x ][ p1.y].role==RIEN)
    return 0;
    if (p->echiquier[ p2.x ][ p2.y].role==BUT) {
       if(p->echiquier[ p1.x ][ p1.y].role==DRAGON){
       return 1;
       }
       else return 0;
    }
    if (p->echiquier[ p2.x ][ p2.y].role!=RIEN){
    return 0;
    }
    return 1;
}

int verif_case_interm(plateau *p, Position p1, Position p2)
{
if (p1.x-p2.x==2){
    if (p1.y-p2.y==0){
        if(p->echiquier[p1.x-1][p1.y].role==RIEN)
        	return 0;
        if(p->echiquier[p1.x-1][p1.y].couleur==p->echiquier[p1.x][p1.y].couleur)
		return 2;
    }

    if(p1.y-p2.y==2){
        if (p->echiquier[p1.x-1][p1.y-1].role==RIEN)
       	 	return 0;
        
	if(p->echiquier[p1.x-1][p1.y-1].couleur==p->echiquier[p1.x][p1.y].couleur)
		return 2;
     
    }

    if(p1.y-p2.y==-2){
       if (p->echiquier[p1.x-1][p1.y-1].role==RIEN)
        	return 0;
        if(p->echiquier[p1.x-1][p1.y-1].couleur==p->echiquier[p1.x][p1.y].couleur)
		return 2;
  
    }
}
if (p1.x-p2.x==-2){
    if (p1.y-p2.y==0){
        if(p->echiquier[p1.x+1][p1.y].role==RIEN)
        	return 0;
        if(p->echiquier[p1.x+1][p1.y].couleur==p->echiquier[p1.x][p1.y].couleur)
		return 2;
    }

    if(p1.y-p2.y==2){
        if (p->echiquier[p1.x+1][p1.y-1].role==RIEN)
        	return 0;
        if(p->echiquier[p1.x+1][p1.y-1].couleur==p->echiquier[p1.x][p1.y].couleur)
		return 2;
     
    }

    if(p1.y-p2.y==-2){
       if (p->echiquier[p1.x+1][p1.y+1].role==RIEN)
        	return 0;
        if(p->echiquier[p1.x+1][p1.y+1].couleur==p->echiquier[p1.x][p1.y].couleur)
		return 2;
        
    }
    }
    if (p1.x-p2.x==0){
    if (p1.y-p2.y==0){
        return 0;
    }

    if(p1.y-p2.y==2){
        if (p->echiquier[p1.x][p1.y-1].role==RIEN)
        	return 0;
        if(p->echiquier[p1.x][p1.y-1].couleur==p->echiquier[p1.x][p1.y].couleur)
		return 2;
      
    }

    if(p1.y-p2.y==-2){
       if (p->echiquier[p1.x][p1.y+1].role==RIEN)
        	return 0;
        if(p->echiquier[p1.x][p1.y+1].couleur==p->echiquier[p1.x][p1.y].couleur)
		return 2;
        
    }
    }
    return 1;
}

#endif
