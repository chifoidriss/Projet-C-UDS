#include "header.h"

Arbre *newArbre(int x){
    Arbre *a = malloc(sizeof(*a));

    if(a == NULL){
        fprintf(stderr,"Erreur d'allocation dynamique!\n");
        exit(EXIT_FAILURE);
    }
    a->val = x;
    a->sag = NULL;
    a->sad = NULL;
    a->parent = NULL;

    printf("Creation de: %d\n",a->val);
    return a;
}

void effaceArbre(Arbre *a){
    if(a == NULL)
        return;
    printf("Suppression de: %d\n",a->val);
    effaceArbre(a->sag);
    effaceArbre(a->sad);
    free(a);
}

Arbre *joinArbre(Arbre *a,Arbre *b, int noeud){
    Arbre *ar = newArbre(noeud);
    ar->sag = a;
    ar->sad = b;
    if(a != NULL)
        a->parent = ar;
    if(b != NULL)
        b->parent = ar;
    return ar;
}

void affArbre_prefix(Arbre *a){
    if(a == NULL)
        return;
    if(a->parent != NULL)
        printf("(%d)->[%d]\n",a->parent->val,a->val);
    else
        printf("[%d]\n",a->val);
    if(a->sag != NULL)
        affArbre_prefix(a->sag);
    if(a->sad != NULL)
        affArbre_prefix(a->sad);
}

int main()
{
    printf("Bienvenu dans la gestion des arbres binaires de recherche!\n\n");

    Arbre *A = joinArbre(newArbre(5),newArbre(10),7);

    affArbre_prefix(A);

    effaceArbre(A);

    return 0;
}
