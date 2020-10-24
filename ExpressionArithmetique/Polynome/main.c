#include "header.h"

monome newMono(int d,int c){
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
        if(Q->m.c>0){
            if(Q->m.c!=1){
                if(Q->m.d==0)
                    printf(" +%d",Q->m.c);
                else if(Q->m.d==1)
                    printf(" +%dX",Q->m.c);
                else
                    printf(" +%dX^%d",Q->m.c,Q->m.d);
            }else if(Q->m.c==1){
                if(Q->m.d==0)
                    printf(" +1");
                else if(Q->m.d==1)
                    printf(" +X");
                else
                    printf(" +X^%d",Q->m.d);
            }
        }else if(Q->m.c<0){
            if(Q->m.c!=-1){
                if(Q->m.d==0)
                    printf(" %d",Q->m.c);
                else if(Q->m.d==1)
                    printf(" %dX",Q->m.c);
                else
                    printf(" %dX^%d",Q->m.c,Q->m.d);
            }else if(Q->m.c==-1){
                if(Q->m.d==0)
                    printf(" -1");
                else if(Q->m.d==1)
                    printf(" -X");
                else
                    printf(" -X^%d",Q->m.d);
            }
        }
        Q = Q->next;
    }
    printf("\n");
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
    monome *mo;
    Polynome a=P,b=Q;
    poly = malloc(sizeof(*poly));
    while(!videPoly(a) || !videPoly(b)){
        if(a->m.d == b->m.d){
            mo->d = a->m.d;
            mo->c = a->m.c + b->m.c;
            ajoutPoly(poly,*mo);
        }
        a = a->next;
        b = b->next;
    }
    return poly;
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

Polynome concartPoly(Polynome P,Polynome Q){
    PolynomeElt *poly;
    poly = malloc(sizeof(*poly));
    poly = P;
    while(!videPoly(poly->next)){
        poly = poly->next;
    }
    poly->next = Q;
    effacePoly(P);
    effacePoly(Q);
    return poly;

    /*PolynomeElt *A = P;
    while(!videPoly(A->next)){
        A = A->next;
    }
    A->next = Q;
    return P;*/
}

Polynome effacePoly(Polynome P){
    if(videPoly(P))
        return newPoly();
    free(P);
    return effacePoly(P->next);
}

int main(void)
{
    printf("Bienvenue dans la gestion des Polynomes!\n");

    monome m1 = newMono(3,6);
    monome m2 = newMono(2,5);
    monome m3 = newMono(0,-1);
    monome m4 = newMono(2,7);
    monome m5 = newMono(3,-20);
    monome m6 = newMono(5,-9);
    Polynome p1 = newPoly();
    Polynome p2 = newPoly();
    Polynome p3 = newPoly();
    p1 = ajoutPoly(p1,m1);
    p1 = ajoutPoly(p1,m2);
    p1 = ajoutPoly(p1,m3);
    p1 = ajoutPoly(p1,m4);
    p1 = ajoutPoly(p1,m5);
    p2 = ajoutPoly(p2,m6);
    p2 = ajoutPoly(p2,m4);
    p2 = ajoutPoly(p2,m3);
    p2 = ajoutPoly(p2,m2);
    p2 = ajoutPoly(p2,m1);
    p3 = concartPoly(p1,p2);

    printf("-------------------------------------------------\n");
    affPoly(p1);
    printf("-------------------------------------------------\n");
    affPoly(p2);
    printf("-------------------------------------------------\n");
    affPoly(p3);
    int l = longPoly(p1);
    printf("%d\n",l);
    printf("-------------------------------------------------\n");

    return 0;
}
