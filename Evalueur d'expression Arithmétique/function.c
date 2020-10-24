#include "header.h"

/**============= Verifie si un caractére est un operateur ou pas **/
int IsOperator ( elem E ) {
   if( E.type == 0 )
         return 1;  /* c'est un operateur */
   return 0;  /* ce n'est pas un operateur */
}

/**============= Verifie si un caractére est un operande ou pas **/
int IsOperand (elem E) {
   if( E.type == 1 )
        return 1;  /* c'est un operande */
   return 0;  /* ce n'est pas un operande */
}

/**============= retourne la proprieter d'un operateur **/
int Priority (elem E) {
   /* L'element passé à Priority() est un operateur */
   if( E.val=='*' || E.val=='/' || E.val=='%' )
      return 2;
   else if( E.val=='-' || E.val=='+' )
      return 1;
   else
      return -1;  /* erreur ! */
}

/**============= effectue l'operation x op y **/
elem Operation (float x, float y, float op) {
   elem ret;
   ret.type = 1;  /* Le resultat de l'operation est un operande */
   switch ((int)op) {
      case '+' :  ret.val = x + y;  break;
      case '-' :  ret.val = x - y;  break;
      case '*' :  ret.val = x * y;  break;
      case '/' :  ret.val = x / y;  break;
      case '%' :  ret.val = (int)x % (int)y; break;
   }
   return ret;
}

/**============= retourne la taille du vecteur **/
elem* ChaineEnVecteur(char* char_exp, elem* vect_exp, int *len_vect) {
   int i=0, j=0, i_tmp=0, is_unar_minus=0, len = strlen(char_exp);
   int taille_en_plus = 0, taille_en_plus_E = 0; /* les taille à enlever */
   char *tmp; /*Pour contenir le nombre temporerement sous forum d'une chaine*/
   elem* vect;

   while( i<len ) {
      /* Si c'est ce caractére est un chifre */
      if( isdigit(char_exp[i]) ) {
         tmp = (char*) malloc(len);
         /* Comstruire le nombre sous forme d'une chaine tmp */
         while( (isdigit(char_exp[i]) || char_exp[i] == '.') && i<len ) {
            tmp[i_tmp] = char_exp[i];
            i_tmp++;
            taille_en_plus++;  /* ex: le nbr "548" est sur 3 position */
            i++;  /* passé à la case suivante de la chaine */
         }
         /* un nombre sur 3 position dans la chaine va devenir sur 1 seul
            position (dans le vecteur), donc il y a 3-1 = 2 position en plus */
         taille_en_plus--;

         tmp[i_tmp] = '\0';  /* on termine la chaine tmp par '\0' */
         vect_exp[j].type = 1;  /* c'est un operande */
         if(is_unar_minus) {
            vect_exp[j].val = (-1)*atof(tmp);
            is_unar_minus = 0;  /* reinitialisé à FAUX */
         } else
            vect_exp[j].val = atof(tmp);
         j++; /* passé à la case suivante du vecteur */

         free(tmp);
         i_tmp = 0;
      }
      /* Si ce n'est pas un chifre, alors: */
      else {
         /* Si le caractére - n'est pas précédé par un chifre (le - unaire) */
         if( char_exp[i] == '-' && ! isdigit(char_exp[i-1]) ) {
            is_unar_minus = 1;  /* VRAI, c'est un - unaire */
            i++;
         } else {
            vect_exp[j].val = char_exp[i]; /* le code ascii */

            if( char_exp[i] == ')' || char_exp[i] == '(' )
               vect_exp[j].type = 2;  /* indique que c'est soit ) ou ( */
            else if( char_exp[i] == 'E' || char_exp[i] == 'e' )
               vect_exp[j].type = 3;  /* indique que c'est un E */
            else if( char_exp[i] == 'c'  || char_exp[i] == 'C' )
               vect_exp[j].type = 5;  /* indique que c'est un cosinus */
            else if( char_exp[i] == 's' || char_exp[i] == 'S')
                vect_exp[j].type = 6;  /* indique que c'est un sinus */
            else if( char_exp[i] == 't' || char_exp[i] == 'T')
                vect_exp[j].type = 7;  /* indique que c'est un tan */
            else if( char_exp[i] == '^' )
                vect_exp[j].type = 8;  /* indique que c'est une puissance */
            else
               vect_exp[j].type = 0;  /* c'est un operateur */

            j++;
            i++;
         }
      }
   }
   /* à la sortie de while, (len-taille_en_plus) == taille actuel de vect_exp */
   /* Maintenant on va s'occuper des caractéres 'E' ou 'e' : */
   vect = (elem*) malloc( (len - taille_en_plus) * sizeof(elem) );
   for( i=0, j=0; i < (len-taille_en_plus); i++ ) {
      if( vect_exp[i].type < 3 ) { /* si c'est un E ou e ou c ou s ou t */
         vect[j] = vect_exp[i];
         j++;
      } else if(vect_exp[i].type == 5){ /* si c'est un c ou C */
        vect[j-1].val = vect_exp[i-1].val*cos(vect_exp[i+1].val*3.14/180);
         i++;
         taille_en_plus_E = taille_en_plus_E + 2;
      } else if(vect_exp[i].type == 6){ /* si c'est un s ou S */
        vect[j-1].val = vect_exp[i-1].val*sin(vect_exp[i+1].val*3.14/180);
         i++;
         taille_en_plus_E = taille_en_plus_E + 2;
      } else if(vect_exp[i].type == 7){ /* si c'est un t ou T */
        vect[j-1].val = vect_exp[i-1].val*tan(vect_exp[i+1].val*3.14/180);
         i++;
         taille_en_plus_E = taille_en_plus_E + 2;
      } else if(vect_exp[i].type == 8) { /* si c'est un ^ */
         vect[j-1].val = pow(vect_exp[i-1].val, vect_exp[i+1].val);
         i++;
         taille_en_plus_E = taille_en_plus_E + 2;
      } else if(vect_exp[i].type == 3) { /* si c'est un e ou E */
        vect[j-1].val = vect_exp[i-1].val*exp(vect_exp[i+1].val);
         i++;
         taille_en_plus_E = taille_en_plus_E + 2;
      }
   }
   *len_vect = len - taille_en_plus - taille_en_plus_E;
   return vect;  /* le vecteur qu'on cherche */
}

/**============= Les Algos de postfixation et d'evaluation: **/
/* la forme postfixee sera dans la pile P */
Pile* FormePostFixe( elem* vect, int len_vect ) {
   int i;
   elem E;
   Pile *R, *P;
   Pile* D;  /* Juste pour tester le Debugage, pour voir la forme postfixé */
   InitPile(&P);
   InitPile(&R);

   for( i=0; i<len_vect; i++ ) {
      if( IsOperand(vect[i]) )
         Empiler(&R, vect[i]);
      else if( IsOperator(vect[i]) ) {
         while( !PileVide(P) && IsOperator(sommetPile(P)) &&
                ( Priority(vect[i]) <= Priority(sommetPile(P)) ) ) {
            E = Depiler(&P);
            Empiler(&R, E);
         }
         Empiler(&P, vect[i]);
      }
      else if( vect[i].val == '(' )
         Empiler(&P, vect[i]);
      else {
         while( (!PileVide(P)) && sommetPile(P).val != '(' ) {
            E = Depiler(&P);
            Empiler(&R, E);
         }
         E = Depiler(&P);
      }
   }
   while( !PileVide(R) ) {
      E = Depiler(&R);
      Empiler(&P, E);
   }
#if 1 /* Debugage pour voir la forme poste fixée. désactivé avec: #if 0 */
   printf("\n Forme PostFixee de l'expression: \n");
   D = P;
   for( ; D != NULL; D = D->next ) {
      if(D->element.type == 1)
         printf(" %.2f  ", D->element.val);
      else
         printf(" %c  ", (int)D->element.val);
   }

#endif /* Fin Debugage ... */
   return P;
}

/** Evaluation de l'expression à partire de sa forme postfixée **/
float EvalueFormePostFixe( Pile* P ) {
   elem x, y, e;
   Pile *R;
   InitPile( &R );

   while( !PileVide(P) ) {
      e = Depiler(&P);
      if( IsOperand(e) )
         Empiler(&R, e);
      else {
         x = Depiler (&R);
         y = Depiler (&R);
         Empiler(&P, Operation (y.val, x.val, e.val));
      }
   }
   /* le resultat de l'expression est dans R */
   return R->element.val;
}

/************* Les fonctions classique sur les Piles : *************/
void Empiler (Pile** S, elem E) {
   Pile* tmp = malloc (sizeof (Pile));
   tmp->element = E;
   tmp->next = *S;
   *S = tmp;
}

elem Depiler (Pile **S) {
   Pile* tmp;
   elem ret;

   if( !PileVide(*S) ) {
      tmp = *S;
      *S = (*S)->next;
      ret = tmp->element; /* on va retourner cette element */
      free(tmp);

      return ret;
   }
}

void InitPile( Pile **S ) {
   *S = NULL;
}

int PileVide (Pile *S) {
   if( S == NULL )
      return 1;  /* Oui pile vide */
   return 0;  /* Pile non vide */
}

elem sommetPile ( Pile *S ) {
   return (S->element);
}

/** Verifie si l'expression est correcte ou pas **/
int CorrectExpression( char* expr ) {
   char symbol[29] = "0123456789.eE()*/%+-cstCST^"; /* il y a 25 symboles autorisés */
   int i, j, trouve = 0, brackets = 0, len = strlen(expr);

   /**========== Verification si l'expression n'est pas vide: ==========**/
   if(len<1){
        printf(" Erreur: Expression vide!!!\n");
        return 0;   /* Expression Incorrecte */
   }

   /**========== Verification Lexicale: ==========**/
   for( i=0; i < len; i++ ) {
      trouve = 0;
      /* Verifier si le expre[i] apartiens à la liste des symboles autorisé */
      for( j=0; j < 29; j++ ) {
         if( expr[i] == symbol[j] ) {
            trouve = 1;
            break;
         }
      }
      /* s'il ne se trouve pas dans la liste des symboles autorisé : */
      if( !trouve ) {
         printf(" Erreur: Expression Incorrecte. carateres non autoriser!!!\n");
         return 0;   /* Expression Incorrecte */
      }
   }
   /**========== Verification Syntaxique: ==========**/
   /* Verifier si le nbr de ')' est egale au nbr de '(' */
   for( i=0; i < len; i++ ) {
      if( expr[i] == '(' )
         brackets++;
      else if( expr[i] == ')' )
         brackets--;
   }
   if( brackets > 0 ) {
      printf(" Erreur: Il manque %d caractere ')' dans l'expression.\n", brackets);
      return 0;
   } else if( brackets < 0 ) {
      printf(" Erreur: Il manque %d caractere '(' dans l'expression.\n", (-1) * brackets);
      return 0;
   }
   /* Verification de l'ordre des caracteres: */
   for( i=0; i < len; i++ ) {
      /* pour les caracteres + - * / % */
      if( expr[i] == '+' || expr[i] == '/' || expr[i] == '*' ||
             expr[i] == '%' || expr[i] == '-' ) {
         /* si l'operateur ce trouve tout en debut ou en fin de l'expression: */
         if( i == len-1 ) {
            printf(" Erreur: presence de caractere(s) mal placer.\n");
            return 0;   /* Expression Incorrecte */
         } else if( i == 0 ) {
            if( expr[i] != '-' ) {
               printf(" Erreur: presence de caractere(s) mal placer.\n");
               return 0;   /* Expression Incorrecte */
            }
            else if( !( isdigit(expr[i+1]) || expr[i+1] == '(' ) ) {
               printf(" Erreur: presence de caractere(s) mal placer.\n");
               return 0;   /* Expression Incorrecte */
            }
         }

         /* Dans le cas d'un operateur differant de '-' :
            il faut que l'operateur soi suivi d'un nombre ou bien d'une '(' ou
            bien un '-'  ,ET, il faut qu'il soi préceder par un nombre
            ou bien par une ')' , Dans le cas contrere, C'est une erreur */
         else if( expr[i] != '-' ) {
            if( !( (isdigit(expr[i+1]) || expr[i+1] == '(' || expr[i+1] == '-')
                    &&  (isdigit(expr[i-1]) || expr[i-1] == ')') ) ) {
               printf(" Erreur: presence caractere(s) mal placer.\n");
               return 0;   /* Expression Incorrecte */
            }
         }
         /* Si l'operateur est un '-' : */
         else if( !( (isdigit(expr[i+1]) || expr[i+1] == '(' )
             && (isdigit(expr[i-1]) || expr[i-1]==')' || expr[i-1]=='('||
                 expr[i-1] == 'E' || expr[i-1] == 'e' || expr[i-1]=='+'||
                 expr[i-1]=='*' || expr[i-1]=='/'||expr[i-1]=='%') )) {
            printf(" Erreur: presence caractere(s) mal placer.\n");
            return 0;   /* Expression Incorrecte */
         }
      }
      /* pour le caractere '(' */
      if( expr[i] == '(' ) {
         /* s'il ce trouve au début de l'expression */
         if( i == 0 ) {
            /* il faut qu'il soit suivi par soi un nbr soi '(' soi '-'  */
            if( ! (isdigit(expr[i+1]) || expr[i+1]=='(' || expr[i+1]=='-') ) {
               printf(" Erreur: presence caractere(s) mal placer.\n");
               return 0;
            }
         }
         /* s'il ce trouve a la fin de l'expression, alors c'est une erreur */
         else if( i == len-1 ) {
            printf(" Erreur: presence caractere(s) mal placer.\n");
            return 0;
         }
         /* s'il ce trouve quelque part dans l'expression */
         else {
            if( ! ( (isdigit(expr[i+1]) || expr[i+1]=='(' || expr[i+1]=='-') &&
                    (expr[i-1]=='*' || expr[i-1]=='-'|| expr[i-1]=='/' ||
                     expr[i-1]=='+' || expr[i-1]=='%'|| expr[i-1]=='(') ) ){
              printf(" Erreur: presence caractere(s) mal placer.\n");
              return 0;
            }
         }
      }
      /* pour le caractere ')' */
      if( expr[i] == ')' ) {
         /* s'il ce trouve a la fin de l'expression */
         if( i == len-1 ) {
            /* il faut qu'il soit preceder par soi un nbr soi ')'  */
            if( ! ( isdigit(expr[i-1]) || expr[i-1]==')' ) ) {
               printf(" Erreur: presence caractere(s) mal placer.\n");
               return 0;
            }
         }
         /* s'il ce trouve au début de l'expression, alors c'est une erreur */
         else if( i == 0 ) {
            printf(" Erreur: presence caractere(s) mal placer.\n");
            return 0;
         }
         /* s'il ce trouve quelque part dans l'expression */
         else {
            if( ! ( (isdigit(expr[i-1]) || expr[i-1]==')') &&
                    (expr[i+1]=='*' || expr[i+1]=='-'|| expr[i+1]=='/' ||
                     expr[i+1]=='+' || expr[i+1]=='%'|| expr[i+1]==')') ) ) {
              printf(" Erreur: presence caractere(s) mal placer.\n");
              return 0;
            }
         }
      }
      if(expr[0]=='e' || expr[0]=='E' || expr[len-1]=='e' || expr[len-1]=='E' ) {
         printf(" Erreur: presence caractere(s) mal placer.\n");
         return 0;
      } else if( (expr[i] == 'E' || expr[i] == 'e' ) &&
               (expr[i+1]== '*' || expr[i+1]== '/' || expr[i+1]== '+' || expr[i+1]== '%') ) {
         printf(" Erreur: presence caractere(s) mal placer.\n");
         return 0;
      }
   }
   return 1;   /* Expression correcte */
}
