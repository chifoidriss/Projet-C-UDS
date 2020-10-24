#include "header.h"

int est_vide(PILE_TAB* pile)
{
    return (pile->sommet ==-1);
}

int est_pleine(PILE_TAB* pile) {
    if(pile->sommet == 99)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void init_pile(PILE_TAB* pile) {
    pile->sommet=-1;
}

int empiler(PILE_TAB* pile, ELEMENT nouveau) {
    int i;
    if(est_pleine(&pile))
    {
        return 1;
    }
    else
    {
        pile->tab[pile->sommet+1]= nouveau;
        pile->sommet=pile->sommet+1;
    }
    printf("affichage de la pile\n");
    for(i=pile->sommet; i>=0; i--)
    {
        printf("%c\n",pile->tab[i]);
    }
}

int depile(PILE_TAB* pile) {
    int x,y,resultat;
    char op;
    int i;
    if(est_vide(&pile))
    {
        return 1;
    }
    else
    {
        x=pile->tab[pile->sommet];
        op=pile->tab[pile->sommet-1];
        y=pile->tab[pile->sommet-2];
        pile->sommet=pile->sommet-2;
        resultat = x + op + y;
        printf("%c\n", resultat);
        printf("affichage de la pile après avoir depile\n");
        for(i=pile->sommet; i>=0; i--)
        {
            printf("%c\n",pile->tab[i]);
        }
        empiler(&pile, resultat);
    }
}

int main()
{
    PILE_TAB pile;
    char expression[MAX];
    int i;
    printf("Entrez votre expression arithmétique\n");
    scanf("%s", expression);
    printf("Vous avez entre l'epression suivante : %s\n", expression);
    printf(" : %c\n", expression[1]); // Pour vérifier que j'affiche aussi bien
    init_pile(&pile);
    for(i=0; expression[i]!='='; i++)
    {
    if(expression[i]=='(')
    {
    }
    else if(expression[i] != '(' && expression[i] != ')')
    {
    empiler(&pile, expression[i]);
    }
    else if(expression[i]==')')
    {
    depile(&pile);
    }
    }
    printf("Hello world!\n");
    return 0;
}
