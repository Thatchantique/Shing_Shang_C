#define LIGNE 10;
#define COLONNE 10;
#define taille_max 3;

enum Couleur {VIDE=0, NEUTRE, BLEU, ROUGE};
enum Role {RIEN=0, INA, SINGE, LION, DRAGON, BUT};

typedef struct position{
 int x;
 int y;
}Position;

/** unsigned = Valeur absolue */

typedef struct Pion{
    enum Couleur couleur;
    enum Role role;
}Pion;

typedef struct plateau{
    int nb_lignes, nb_colonnes;
    Pion** echiquier;
}plateau;

void affiche_plateau(plateau p);
void Initialise_Plateau(plateau *p);

void pose_pion(plateau *p, Position p1, Position p2);
Pion vise_pion(plateau *p, Position p1);

int deplace_dragon_lion_singe(plateau *p, Position p1, Position p2, int type_position);
int deplace_lion(plateau *p, Position p1, Position p2);
int deplace_singe(plateau *p, Position p1, Position p2);
int deplace_dragon(plateau *p, Position p1, Position p2);

int verifier_possibilite(plateau *p, Position p1, Position p2);

void mettre_case_vide(plateau *p, Position p1);

int verif_case_interm(plateau *p, Position p1, Position p2);

/**---lecture et écriture depuis un fichier---**/

void initialise_depuis_fichier(char * fichier, plateau *p);

int recupere_direction(Position p1, Position p2);

/*****/
int menu();
void but ();
void derou ();
void def ();
void regles ();

void lancer_jeu(int i);
int est_gagne(plateau *p);
void lister_fichier();
void system_clear_linux();
void save_file(plateau *p);
