#include "header.h"

monome newMono(int d,double c){
    monome *mono;
    mono = malloc(sizeof(*mono));
    if(mono == NULL){
        fprintf(stderr,"Problème d'allocation dynamique!\n");
        exit(EXIT_FAILURE);
    }
    mono->c = c;
    mono->d = d;
    return *mono;
}

Polynome newPoly(void){
    return NULL;
}

Bool videPoly(Polynome P){
    if(P == NULL)
        return true;
    return false;
}

void affPoly(Polynome P){
    Polynome Q=P;
    while(!videPoly(Q)){
        if(Q->m.c!=0){
            if(Q->m.c!=1)
                printf("%f x^%d + ",Q->m.c,Q->m.d);
            else if(Q->m.c == -1)
                printf("-x^%d + ",Q->m.d);
        }
        Q = P->next;
    }
    free(P);
}

Polynome ajoutPoly(Polynome P, monome mn){
    PolynomeElt *poly;
    poly = malloc(sizeof(*poly));
    if(videPoly(poly)){
        printf(stderr,"Problème d'allocation dynamique!\n");
        return(EXIT_FAILURE);
    }
    poly->m.c = mn.c;
    poly->m.d = mn.d;
    poly->next = P;
    return poly;
}

Polynome retirePoly(Polynome P){
    PolynomeElt *poly;
    if(videPoly(P)){
        printf("Le polynôme est vide!\n");
        return(EXIT_FAILURE);
    }
    poly = P->next;
    free(P);
    return poly;
}

monome sommetPoly(Polynome P){
    if(videPoly(P)){
        printf("Le polynôme est vide!\n");
        exit(EXIT_FAILURE);
    }
    return P->m;
}

int longPoly(Polynome P){
    int i=0;
    while(!videPoly(P)){
        i++;
        P = P->next;
    }
    return i;
}

Polynome somPoly(Polynome P,Polynome Q){
    PolynomeElt *poly;
    poly = malloc(sizeof(*poly));
    if(videPoly(P) || videPoly(P)){
        return poly;
    }
    if(P->m.d == Q->m.d){
        poly->m.d == P->m.d;
        poly->m.c = P->m.c + Q->m.c;
    }

    return somPoly(P->next,Q->next);
}

Polynome diffPoly(Polynome P,Polynome Q){
    PolynomeElt *poly;
    poly = malloc(sizeof(*poly));
    if(videPoly(P) || videPoly(P)){
        return poly;
    }
    if(P->m.d == Q->m.d){
        poly->m.d == P->m.d;
        poly->m.c = P->m.c - Q->m.c;
    }
    return somPoly(P->next,Q->next);
}

Polynome effacePoly(Polynome P){
    if(videPoly(P))
        return newPoly();
    return effacePoly(P->next);
}

int main(void)
{
    printf("Bienvenue dans la gestion des Polynômes!\n");

    monome m1 = newMono(3,6);
    monome m2 = newMono(2,5);
    monome m3 = newMono(1,6);
    monome m4 = newMono(2,7);
    monome m5 = newMono(3,13);
    monome m6 = newMono(5,9.5);
    Polynome p1 = newPoly();
    Polynome p2 = newPoly();
    p1 = ajoutPoly(p1,m1);
    p1 = ajoutPoly(p1,m2);
    p1 = ajoutPoly(p1,m3);
    p1 = ajoutPoly(p1,m4);
    p1 = ajoutPoly(p1,m5);
    if(videPoly(p1))
        printf("Polynome vide\n");
    else
        printf("Polynome avec des élements\n");
    affPoly(p1);

    return 0;
}
