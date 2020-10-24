#include "header.h"

File newFile(){
    return NULL;
}

Bool videFile(File F){
    if(F==NULL)
        return true;
    return false;
}

int longFile(File F){
    if(videFile(F))
        return 0;

    File A = F;
    int i=0;
    while(A != NULL){
        A = A->next;
        i++;
    }
    return i;
}

int premierFile(File F){
    if(videFile(F)){
        printf("File vide!");
        exit(1);
    }
    return F->val;
}

int dernierFile(File F){
    if(videFile(F)){
        printf("File vide!");
        exit(1);
    }
    File A = F;
    while(A->next != NULL)
        A = A->next;
    return A->val;
}

void afficheFile(File F){
    if(videFile(F)){
        printf("\n");
        return;
    }
    printf("[%d]",F->val);
    afficheFile(F->next);
}

File Emfiler(File F,int x){
    FileElt *elt = malloc(sizeof(*elt));
    if(elt == NULL){
        fprintf(stderr,"Problème allocation dynamique.\n");
        exit(EXIT_FAILURE);
    }
    elt->val = x;
    elt->next = NULL;
    if(videFile(F))
        return elt;
    File tmp = F;
    while(tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = elt;

    return F;
}

File Defiler(File F){
    if(videFile(F)){
        printf("Rien a retirer! Je suis vide!\n");
        return newFile();
    }
    return F->next;
}

int main(void) {
    printf("Bienvenue dans la gestion des FILES!\n");

    File a = newFile();
    a = Defiler(a);
    a = Emfiler(a,2);
    a = Emfiler(a,5);
    a = Emfiler(a,9);
    a = Emfiler(a,12);
    a = Emfiler(a,21);
    afficheFile(a);
    a = Defiler(a);
    if(videFile(a))
        printf("je suis vide!\n");
    else
        printf("Je suis chargee de longueur: %d\n",longFile(a));
    afficheFile(a);

    printf("Premier element: %d\n",premierFile(a));
    printf("Dernier element: %d\n",dernierFile(a));

    free(a);

    getchar();
    return 0;
}
