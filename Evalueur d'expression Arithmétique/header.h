#include <stdio.h>  /* Pour les Entrers/Sorties */
#include <stdlib.h> /* Pour l'Allocation dynamique et autre */
#include <string.h> /* Pour les fonctions de manipulation de chaines */
#include <ctype.h>  /* Pour la fonction isdigit() */
#include <math.h>   /* Pour la fonction pow() */

#define MAX_LEN 30  /* Langeur maximale de l'expression */

/* Definition du type elem pour les elements du vecteur */
typedef struct Elem {
   float val;
   int type;  /* 0=>operateur.  1=>operande.  2=>paranthese, 3=>E ou e */
}elem;

/* Definition du type Pile pour la Pile */
typedef struct Pile {
   elem element;  /* l'element du vecteur */
   struct Pile *next;
}Pile;

/********************** The Prototyps **********************/
int CorrectExpression (char*);  /* Verifie si l'expression est correcte */

int IsOperator (elem);  /* Verifie si c'est un operateur */
int IsOperand (elem);  /* Verifie si c'est un operande */
int Priority (elem);  /* retourne la priorité d'un operateur */
elem Operation (float, float, float);  /* effectue une operation simple */

elem* ChaineEnVecteur (char*, elem*, int*);  /* chaine => vecteur d'elements */
Pile* FormePostFixe (elem*, int);  /* La pile de la forme postfixé */
float EvalueFormePostFixe (Pile*);  /* Evalué l'expression */

elem Depiler (Pile**);  /* Depiler */
void Empiler (Pile**, elem);  /* Empiler */
void InitPile (Pile**);  /* Initialiser la pile */
int PileVide (Pile*);  /* Verifie si la pile est vide ou pas */
elem sommetPile (Pile*);  /* retourne l'element de tête de la pile */
