#include <stdio.h>
#include <stdlib.h>
#include "I_Plateau.h"


int menu ()
{
  int x;
  printf("**********Bienvenue dans le jeu SHING SHANG***********\n");
  printf("\n");
  printf("\n");
  printf("\n");
  printf("***********ACCUEIL**********\n");
  printf("\n");
  printf("\n");
  printf("1) JOUER AU JEU :\n");
  printf("\n");
  printf("2) CHARGER UNE PARTIE :\n");
  printf("\n");
  printf("3) REGLE DU JEU :\n");
  printf("\n");
  printf("4) QUITTER \n");
  printf("\n");
  printf("\n");
  printf("Tapez le numéros de la catégorie que vous souhaiteriez entrer\n");
  scanf("%d",&x);
  if
    (x<1 || x> 4){
      do {
	printf("Saisir un numéro entre 1 et 4 \n");
	scanf("%d",&x);
      }
      while (x<1 || x>4);
  }

  switch (x)
    {
    case 1:
        printf("LE JEU\n");
        lancer_jeu(0);
      break;
    case 2:
     system_clear_linux();
     lancer_jeu(1);
     break;
    case 3:
     system_clear_linux();
     regles();
     break;
    case 4:
     printf("AU REVOIR \n");
     return 1;
	break;
    }
  return 0;
}



void but ()
{
  int l;
  printf("**********BUT DU JEU ***********\n");
  printf("\n");
  printf("\n");
  printf("\n");
  printf("Comment gagner ?\n");
  printf("\n");
  printf("Un joueur gagne la partie lorqu'il parvient à amener l'un de ses dragons \n ");
  printf("sur l'un des portails de son adversaire.\n");
  printf("OU bien, si il capture les deux dragons de sont adversaire\n");
  printf("\n");
  printf("\n");
  printf("\n");
  printf("\n");

  do {
    printf("Tapez 1 pour revenir au règle : \n");
    scanf("%d",&l);
  }
  while (l!=1);


  printf("++ l:%d\n",l);
  switch (l)
    {
 case 1:
   printf("--\n");
   system_clear_linux();
   regles();
   break;
  }
 }


void derou ()
{
  int p;
  printf("**********DEROULEMENT DU JEU**********\n");
  printf("\n");
  printf("\n");
  printf("Le joueur rouge commence, puis les joueurs jouent à tour de role.\n");
  printf("Lors de son tour de jeu un joueur doit déplacer l'un de ses pions\n");
  printf("(mouvement simple ou saut) selon les règles suivantes :\n");
  printf("\n");
  printf("Les singes peuvent:\n");
  printf("\n");
  printf(" - Soit se déplacer de une ou deux cases dans n'importe quelles direction, horizontalement,\n");
  printf("verticalement ou en diagonal mais sans changer de direction au cours du tour.\n");
  printf("\n");
  printf(" - Soit effectuer un ou une série de sauts.\n");
  printf("\n");
  printf("\n");
  printf("Les lions peuvent: \n");
  printf("\n");
  printf(" - Soit se déplacer de une case dans n'importes quelles direction, horizontalement,\n");
  printf("verticalement ou en diagonal (Comme le roi aux Echecs). \n");
  printf("\n");
  printf(" - Soit effectuer un ou une série de sauts.\n");
  printf("\n");
  printf("\n");
  printf("Les dragons ne peuvent se déplacer qu'en sautant.\n");
  printf("\n");
  printf("\n");
  printf("\n");
  printf("Les sauts: \n");
  printf("\n");
  printf(" - Une figurine peut sauter une autre figurine à condition que la pièce sauter soit de la \n");
  printf("meme taille ou de taille inférieure .\n");
  printf("Un dragons peut sauter par dessus un autre dragon, un lion ou un singe.\n");
  printf("Un lions peut sauter par dessus un autre lion ou un singe.\n");
  printf("Un singe ne peut sauter que par dessus un autre singe.\n");
  printf("\n");
  printf(" - De plus il faut qu'au départ de son mouvement, la figurine se trouve sur une case contige\n");
  printf("à une case occupée par une figurine , elle peut sauter la pièce, verticalement, horizontalement\n");
  printf("ou en diagonale, à condition que la case suivante soit vide.\n");
  printf("On peut enchainer plusieurs sauts au cours d'un meme tour(= SHING SHANG)\n");
  printf("Si au cours d'un SHING SHANG on saute par dessus une ou plusieurs figurines adverses , celle-ci sont retiré du plateau.\n");
  printf("\n");
  printf("\n");
  printf("\n");

  printf("Tapez 1 pour retourner au régles\n");
  scanf("%d",&p);
  if
    (p<1 || p> 1){
      do {
	printf("Tapez 1 pour retourner au régles \n");
	scanf("%d",&p);
      }
      while (p<1 || p>1);
  }
  switch (p)
    {
    case 1:
       system_clear_linux();
       regles();
      break;
    }
}

void def ()
{
  int o;
  printf("**********SHING SHANG**********\n");
  printf("\n");
  printf("''On peut enchainer plusieurs sauts au cours d'un meme tour(= SHING SHANG)\n");
  printf("Si au cours d'un SHING SHANG on saute par dessus une ou plusieurs figurines adverses , celle-ci sont retiré du plateau.''\n");
  printf("\n");
  printf("Shing Shang signifie donc l'action d'avoir combattu un adversaire et réussi à gagner afin de le retirer du plateau.\n");
  printf("\n");

  printf("Tapez 1 pour retourner au régles\n");
  scanf("%d",&o);
  if
    (o<1 || o>1){
      do {
	printf("Tapez 1 pour retourner au régles \n");
	scanf("%d",&o);
      }
      while (o<1 || o>1);
  }

  switch (o)
    {
    case 1:
       system_clear_linux();
       regles();
      break;
    }
}

void regles ()
{
    int k;
    printf("**********Bienvenue dans les régles du jeu***********\n");
    printf("\n");
    printf("\n");
    printf("1) But du jeu  :\n");
    printf("\n");
    printf("2) Déroulement du jeu :\n");
    printf("\n");
    printf("3) Qu'est ce que le SHING SHNG :\n");
    printf("\n");
    printf("4) Retour \n");
    printf("\n");
    printf("\n");
    printf("Tapez le numéros de la catégorie que vous souhaiteriez entrer\n");
    scanf("%d",&k);
    if(k<1 || k> 4){
        do {
            printf("Saisir un numéro entre 1 et 4 \n");
            scanf("%d",&k);
        }
        while (k<1 || k>4);
    }
    switch (k)
    {
    case 1:
      system_clear_linux();
      but();
      break;
    case 2:
      system_clear_linux();
      derou();
      break;
    case 3:
      system_clear_linux();
      def();
      break;
    case 4:
      system_clear_linux();
	  menu();
	  break;
    }

}
