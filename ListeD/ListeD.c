#include "header.h"

Dliste newDliste(void){
    return NULL;
}

Bool videDliste(Dliste l){
    if(l==NULL)
        return true;
    return false;
}

int longDliste(Dliste l){
    if(videDliste(l))
        return 0;
    return l->taille;
}

int premierEltDliste(Dliste l){
    if(videDliste(l))
        exit(1);
    return l->deb->val;
}

int dernierEltDliste(Dliste l){
    if(videDliste(l))
        exit(1);
    return l->fin->val;
}

void affDliste(Dliste l){
    if(videDliste(l))
        printf("Aucun élément à afficher, la liste est vide!\n");
    else{
        DListeNode *temp = l->deb;

        while(temp != NULL){
            printf("[%d] ",temp->val);
            temp = temp->next;
        }
        printf("\n");
    }
}

Dliste ajoutFinDliste(Dliste l, int x){
    DListeNode *elt;
    elt = malloc(sizeof(*elt));

    if (elt == NULL) {
        fprintf(stderr, "Erreur: problème d'allocation dynamique.\n");
        exit(EXIT_FAILURE);
    }

    elt->val = x;
    elt->next = NULL;
    elt->prev = NULL;

    if (videDliste(l)) {
        l = malloc(sizeof(*l));
        if (l == NULL) {
            fprintf(stderr, "Erreur: problème d'allocation dynamique.\n");
            exit(EXIT_FAILURE);
        }
        l->taille = 0;
        l->deb = elt;
        l->fin = elt;
    }else {
        l->fin->next = elt;
        elt->prev = l->fin;
        l->fin = elt;
    }

    l->taille++;
    return l;

}

Dliste ajoutDebutDliste(Dliste l, int x){
    DListeNode *elt;
    elt = malloc(sizeof(*elt));

    if (elt == NULL) {
        fprintf(stderr, "Erreur: problème d'allocation dynamique.\n");
        exit(EXIT_FAILURE);
    }

    elt->val = x;
    elt->next = NULL;
    elt->prev = NULL;

    if(videDliste(l)) {
        l = malloc(sizeof(*l));
        if (l == NULL) {
            fprintf(stderr, "Erreur: problème d'allocation dynamique.\n");
            exit(EXIT_FAILURE);
        }
        l->taille = 0;
        l->deb = elt;
        l->fin = elt;
    }else {
        l->deb->prev = elt;
        elt->next = l->deb;
        l->deb = elt;
    }

    l->taille++;
    return l;
}

Dliste retraitFinDliste(Dliste l){
    if(videDliste(l)){
        printf("Rien à supprimer, la liste est vide!\n");
        return newDliste();
    }
    if(l->deb == l->fin){
        free(l);
        l = NULL;
        return newDliste();
    }
    DListeNode *temp = l->fin;
    l->fin = l->fin->prev;
    l->fin->next = NULL;

    temp->next = NULL;
    temp->prev = NULL;
    free(temp);
    temp = NULL;

    l->taille--;
    return l;
}

Dliste retraitDebutDliste(Dliste l){
    if(videDliste(l)){
        printf("Rien à supprimer, la liste est vide!\n");
        return newDliste();
    }
    if(l->deb == l->fin){
        free(l);
        l = NULL;
        return newDliste();
    }
    DListeNode *temp = l->deb;
    l->deb = l->deb->next;
    l->deb->prev = NULL;

    temp->next = NULL;
    temp->prev = NULL;
    free(temp);
    temp = NULL;

    l->taille--;
    return l;
}

Dliste effacerDliste(Dliste l){
    while(!videDliste(l))
        l = retraitFinDliste(l);
    return newDliste();
}

int main(void)
{

    printf("Bienvenue dans la gestion des listes doublement chainees!\n");

    Dliste my = newDliste();
    if(videDliste(my))
        printf("Votre liste est vide.\n");
    else
        printf("Votre liste contient des elements.\n");
    printf("Longueur de la liste: %d\n",longDliste(my));

    return 0;
}
