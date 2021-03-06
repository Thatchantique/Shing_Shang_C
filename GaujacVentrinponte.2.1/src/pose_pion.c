#ifndef PLATEAU_H
#define PLATEAU_H


#include "I_Plateau.h"
#include <math.h>
#include<stdio.h>
#include <stdlib.h>
void pose_pion(plateau *p, Position p1, Position p2){

	if(verifier_possibilite(p, p1,  p2)==0 ){
		return;
    	}

    	Pion pion_vide;
    	pion_vide.couleur=VIDE;
	pion_vide.role=RIEN;

	p->echiquier[ p2.x ][ p2.y ] = p->echiquier[ p1.x ][ p1.y ];
	p->echiquier[ p1.x ][ p1.y ] = pion_vide;
	
	if (p->echiquier[ 1][ 4 ].role==RIEN)
		p->echiquier[ 1][ 4 ].role=BUT;
	if (p->echiquier[ 1][ 5 ].role==RIEN)
		p->echiquier[ 1][ 5 ].role=BUT;
	if (p->echiquier[ 8][ 4 ].role==RIEN)
		p->echiquier[ 8][ 4 ].role=BUT;
	if (p->echiquier[ 8][ 5 ].role==RIEN)
		p->echiquier[ 8][ 5 ].role=BUT;

}

Pion vise_pion(plateau *p, Position p1){
	Pion pion;
	pion.role=INA;

	if ( p1.y >p->nb_colonnes || p1.x > p->nb_lignes )
		return pion;
	if (p->echiquier[ p1.x ][ p1.y].role==INA )
		return pion;

	return p->echiquier[p1.x][p1.y];

}

void mettre_case_vide(plateau *p, Position p1)
{
	p->echiquier[p1.x][p1.y].role=RIEN;
	p->echiquier[p1.x][p1.y].couleur=VIDE;
}

int deplace_lion_dragon_singe(plateau *p, Position p1, Position p2, unsigned int type_pion){
	if(verifier_possibilite(p, p1, p2)){

		if (abs(p1.x-p2.x)<=1 && abs(p1.y-p2.y)<=1){
		        pose_pion(p,p1,p2);
		        return 3;
            	}
/* Si on soustrait les positions finales aux positions initial et que l'on trouve une valeur inf ou égal à 1 on retourne 3 / 
On se déplace en diagonale */


		if (abs(p1.x-p2.x)==2 && abs(p1.y-p2.y)==0){
/* On se déplace de deux cases vers le haut ou le bas / Déplacement vertical */

			if (p1.x-p2.x==2){
/* Déplacement de deux cases vers le haut */

				if(p->echiquier[p1.x-1][p1.y].role>type_pion && p->echiquier[p1.x-1][p1.y].role < BUT)
					return 0;
/* Si la case intermédiaire à un pion ayant un rôle plus important que le pion que l'on souhaite déplacer et inférieur à un BUT (car but dispose du rôle le plus important) alors rien faire */

				if(p->echiquier[p1.x-1][p1.y].couleur!=p->echiquier[p1.x][p1.y].couleur){
				        p1.x-=1;
				        mettre_case_vide(p, p1);
				        p1.x+=1;
				        pose_pion(p,p1,p2);
				        return 2;
                    		}
/* Si le pion intermédiaire est d'une autre couleur que celui qu'on a choisi alors le programme sélectionne ce pion est le supprimé. Il reprend ensuite le nôtre et le place */

		        pose_pion(p,p1,p2);
		        return 1;
		        }
/* Si aucun de ces cas alors il applique un déplacement de deux cases tout simplement */

			if (p1.x-p2.x==-2){
				if(p->echiquier[p1.x+1][p1.y].role>type_pion && p->echiquier[p1.x+1][p1.y].role < BUT)
					return 0;
                    
				if(p->echiquier[p1.x+1][p1.y].couleur!=p->echiquier[p1.x][p1.y].couleur){
					p1.x+=1;
					mettre_case_vide(p, p1);
					p1.x-=1;
					pose_pion(p,p1,p2);
					return 2;
				}
				pose_pion(p,p1,p2);
				return 1;
                		}
            		}
/* Déplacement de deux cases vers le bas. Même procédure */

            	if (abs(p1.x-p2.x)==0 && abs(p1.y-p2.y)==2){
/* Déplacement horizontal de deux cases */

                	if (p1.y-p2.y==2){
                    		if(p->echiquier[p1.x][p1.y-1].role>type_pion && p->echiquier[p1.x][p1.y-1].role < BUT)
                     			return 0;
                    		if(p->echiquier[p1.x][p1.y-1].couleur!=p->echiquier[p1.x][p1.y].couleur){
		            		p1.y-=1;
					mettre_case_vide(p, p1);
					p1.y+=1;
					pose_pion(p,p1,p2);
					return 2;
                    		}
                    	pose_pion(p,p1,p2);
                    	return 1;
                	}
/* Deux cases vers la gauche */

                	if (p1.y-p2.y==-2){
                    		if(p->echiquier[p1.x][p1.y+1].role>type_pion && p->echiquier[p1.x][p1.y+1].role < BUT) 
		    			return 0;

                    		if(p->echiquier[p1.x][p1.y+1].couleur!=p->echiquier[p1.x][p1.y].couleur){
				    	p1.y+=1;
				    	mettre_case_vide(p, p1);
				    	p1.y-=1;
				    	pose_pion(p,p1,p2);
				    	return 2;
                    			}
                	pose_pion(p,p1,p2);
                	return 1;
                	}
            	}
/* Deux cases vers la droite */

            	if (abs(p1.x-p2.x)==2 && abs(p1.y-p2.y)==2){
/* Déplacement en diagonale */

                	if (p1.x-p2.x==2 && p1.y-p2.y==2){
                    		if(p->echiquier[p1.x-1][p1.y-1].role > type_pion && p->echiquier[p1.x-1][p1.y-1].role < BUT) 
					return 0;

				if(p->echiquier[p1.x-1][p1.y-1].couleur!=p->echiquier[p1.x][p1.y].couleur){
				    	p1.y-=1;
				    	p1.x-=1;
				   	mettre_case_vide(p, p1);
				   	p1.y+=1;
				    	p1.x+=1;
				    	pose_pion(p,p1,p2);
				    	return 2;
                    		}
                    	pose_pion(p,p1,p2);
                    	return 1;
                	}
/* En haut à gauche */

                	if (p1.x-p2.x==2 && p1.y-p2.y==-2){
                    		if(p->echiquier[p1.x-1][p1.y+1].role>type_pion && p->echiquier[p1.x-1][p1.y+1].role < BUT)
                     			return 0;
                		if(p->echiquier[p1.x-1][p1.y+1].couleur!=p->echiquier[p1.x][p1.y].couleur) {
                    			p1.y+=1;
		                        p1.x-=1;
			                mettre_case_vide(p, p1);
                    			p1.y-=1;
                    			p1.x+=1;
                    			pose_pion(p,p1,p2);
                    			return 2;
                    		}
                    		pose_pion(p,p1,p2);
                    		return 1;
                	}
/* En haut à droite */

                	if (p1.x-p2.x==-2 && p1.y-p2.y==2){
                    		if(p->echiquier[p1.x+1][p1.y-1].role>type_pion && p->echiquier[p1.x+1][p1.y-1].role < BUT)
                    			return 0;
                    		if(p->echiquier[p1.x+1][p1.y-1].couleur!=p->echiquier[p1.x][p1.y].couleur){
                    			p1.y-=1;
                    			p1.x+=1;
                    			mettre_case_vide(p, p1);
                    			p1.y+=1;
                    			p1.x-=1;
                    			pose_pion(p,p1,p2);
                    			return 2;
                    		}
                    		pose_pion(p,p1,p2);
                    		return 1;
                	}
/* En bas à gauche */

                	if (p1.x-p2.x==-2 && p1.y-p2.y==-2){
                    		if(p->echiquier[p1.x+1][p1.y+1].role>type_pion && p->echiquier[p1.x+1][p1.y+1].role < BUT)
                    			return 0;
                    		if(p->echiquier[p1.x+1][p1.y+1].couleur!=p->echiquier[p1.x][p1.y].couleur){
                    			p1.y+=1;
                    			p1.x+=1;
                    			mettre_case_vide(p, p1);
                    			p1.y-=1;
                    			p1.x-=1;
                    			pose_pion(p,p1,p2);
                    			return 2;
                    		}
                    		pose_pion(p,p1,p2);
                    		return 1;
                	}
/* En bas à droite */

            	}
            	return 0;

       
    	}
 	return 0;
}

int deplace_lion(plateau *p, Position p1, Position p2){

/* Pas de déplacement de deux cases s'il n'y a pas de pièces en intermédiaire. On enlève les possibilités de déplacement simple en deux cases mais on autorise les sauts */
int val=0;
	if (abs(p1.x-p2.x)>1 || abs(p1.y-p2.y)>1){
    		if (verif_case_interm(p,p1,p2)==0)
      			return 0;
		if(verif_case_interm(p,p1,p2)==2){
		val=deplace_lion_dragon_singe(p, p1, p2, LION);
		if(val!=0)
			return 2;
		return 0;
		}
	}

    	return deplace_lion_dragon_singe(p, p1, p2, LION);
}

int deplace_dragon(plateau *p, Position p1, Position p2){

/* On enlève tous les déplacements ayant un x et un y compris entre 0 et 1 -> Tous les déplacements "simples" du lion */

	if (abs(p1.x-p2.x)<=1 && abs(p1.y-p2.y)<=1)
		return 0;

/* On accepte les sauts */

	if(abs(p1.x-p2.x)==2 || abs(p1.y-p2.y)==2){
		if (verif_case_interm(p,p1,p2)==0)
      			return 0;
	
    	}

	return deplace_lion_dragon_singe(p, p1, p2, DRAGON);
}

int deplace_singe(plateau *p, Position p1, Position p2){
	int val=deplace_lion_dragon_singe(p, p1, p2, SINGE);

	/* test : printf("appel deplace_singe\n");*/

	if(val==1){
		int direction=recupere_direction(p1,p2);

		/* test : printf(" singe pos1(%d,%d) pos2=(%d,%d)\n", p1.x,p1.y,p2.x,p2.y);*/

/* On appelle la fonction nous permettant de savoir sur quelle ligne l'utilisateur souhaite se déplacer */

		if (direction==1){

			/* En haut à droite */

        		/* test : printf("1 \n");*/

        		p1.x=p2.x;
        		p1.y=p2.y;
        		p2.x-=1;
        		p2.y+=1;

/* La position initiale devient celle où on souhaite se rendre et la position finale devient celle qui vient après la nôtre sur la même ligne */

        		if (p2.x >=0 && p2.y <p->nb_colonnes){

/* On verifie que la case qui se trouve après la notre et sur la même ligne soit bien sur l'echiquier */

            			if (p->echiquier[p1.x][p1.y].couleur!=p->echiquier[p2.x][p2.y].couleur && p->echiquier[p2.x][p2.y].role!=INA){

/* Si la case qui se trouve après celle où on souhaite se rendre est d'une couleur différentes on s'arrête car on refait appel à la même fonction mais avec un val != 0, on peut plus rentrer dans la boucle. */

            				p2.x-=1;
            				p2.y+=1;
            				return deplace_singe(p, p1, p2);
           			}

        		}
         		return 1;
    		}

/* Même action pour toutes les autres directions */

		if (direction==2){

			/* Au dessus */

			/*test : printf("2 \n");*/

        		p1=p2;
        		p2.x-=1;
        		if (p2.x >=0 ){
        	    		if (p->echiquier[p1.x][p1.y].couleur!=p->echiquier[p2.x][p2.y].couleur && p->echiquier[p2.x][p2.y].role!=INA){
        	    			p2.x-=1;
        	    			return deplace_singe(p, p1, p2);
        	    		}
        	    	}
        	 	return 1;
    		}
	
		if (direction==3){

			/* En haut à gauche */

      			/* test : printf("3 \n");*/

        		p1=p2;
        		p2.x-=1;
        		p2.y-=1;
        		if (p2.x >=0 && p2.y>=0){
        	    		if (p->echiquier[p1.x][p1.y].couleur!=p->echiquier[p2.x][p2.y].couleur && p->echiquier[p2.x][p2.y].role!=INA){
        	    			p2.x-=1;
        	    			p2.y-=1;
        	    			return deplace_singe(p, p1, p2);
        	    		}
        		}
        	 	return 1;
    		}
      		if (direction==4){

			/* A gauche */

      			/* test : printf("4 \n");*/

        		p1=p2;
        		p2.y-=1;
        		if (p2.y>=0){
        	    		if (p->echiquier[p1.x][p1.y].couleur!=p->echiquier[p2.x][p2.y].couleur && p->echiquier[p2.x][p2.y].role!=INA){
        	    			p2.y-=1;
        	    			return deplace_singe(p, p1, p2);
        	    		}
        		}
			return 1;
		}
		if (direction==5){

			/* En bas à gauche */

			/* test : printf("5 \n");*/

			p1=p2;
        		p2.x+=1;
        		p2.y-=1;
        		if (p2.x <p->nb_lignes && p2.y>=0){
        	    		if (p->echiquier[p1.x][p1.y].couleur!=p->echiquier[p2.x][p2.y].couleur && p->echiquier[p2.x][p2.y].role!=INA){
        	    			p2.x+=1;
        	    			p2.y-=1;
        	    			return deplace_singe(p, p1, p2);
        	    		}
			}
        	 	return 1;
    		}
		if (direction==6){

			/* En bas à droite */
		
			/* test : printf("6 \n");*/

        		p1=p2;
        		p2.x+=1;
        		if (p2.x < p->nb_lignes){
				if (p->echiquier[p1.x][p1.y].couleur!=p->echiquier[p2.x][p2.y].couleur && p->echiquier[p2.x][p2.y].role!=INA){
					p2.x+=1;
					return deplace_singe(p, p1, p2);
        	    		}
			}
			return 1;
    		}
      		if (direction==7){

			/* En bas à droite */

      			/* test : printf("7 \n");*/

        		p1=p2;
        		p2.x+=1;
        		p2.y+=1;
        		if (p2.x <p->nb_lignes && p2.y<p->nb_colonnes){
        	    		if (p->echiquier[p1.x][p1.y].couleur!=p->echiquier[p2.x][p2.y].couleur && p->echiquier[p2.x][p2.y].role!=INA){
					p2.x+=1;
					p2.y+=1;
					return deplace_singe(p, p1, p2);
       		    		}
       		 	}
       		  	return 1;
		}
		if (direction==8){

			/* A droite */
	
			/* test :printf("8 \n");*/

       		 	p1=p2;
       		 	p2.y+=1;
       		 	if (p2.y<p->nb_colonnes){
       		     		if (p->echiquier[p1.x][p1.y].couleur!=p->echiquier[p2.x][p2.y].couleur && p->echiquier[p2.x][p2.y].role!=INA){
       		     			p2.y+=1;
       		     			return deplace_singe(p, p1, p2);
       		     		}
			}
			return val;
		}
	}
	return val;
}

int recupere_direction(Position p1, Position p2){

/* programme permettant de placer des numéros sur les différentes possibilités */

	int difX=p1.x-p2.x;
	int difY=p1.y-p2.y;
	if (difX < 0){

/* Ligne du bas */

        	if (difY<0){
        		return 7;

/* En bas à droite */

        	}
        	if (difY==0){
        		return 6;

/* En dessous*/

        	}

        	if (difY>0){
        		return 5;

/* En bas à gauche */

        	}
	}
	if (difX==0)
	{

/* Lignes de la position initiale */

      	  	if (difY<0){
       	 		return 8;
/* A droite */

        	}
        	if (difY>0){
        		return 4;

/* A gauche */

        	}

	}
	if (difX>0){

/* Lignes en haut */

        	if (difY<0){
        		return 1;

/* En haut à droite */

        	}
        	if (difY==0){
        		return 2;

/* Au dessus */

        	}

        	if (difY>0){
        		return 3;

/* En haut à gauche */

        	}
	}
	return -1;
}

#endif
