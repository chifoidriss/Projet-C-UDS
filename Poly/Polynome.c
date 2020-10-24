struct monome {
    double coef;
    int degre;
    struct monome *suiv;
}monome;

typedef monome *Polynome;

void insertTete(Polynome *P, monome *mn){
    mn->suiv = *P;
    *P = mn;
}

void affichePolynome(Polynome P){
    Polynome Q=P;
    while(Q != NULL){
        if(Q->coef != 1 || Q->degree == 0){
            if(Q->coef>0 && Q != P){
                printf("+");
            }
            if(){

            }
        }
    }
}
