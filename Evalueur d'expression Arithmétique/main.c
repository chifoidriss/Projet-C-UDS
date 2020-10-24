#include "function.c"

int main() {
   char expr[MAX_LEN];  /* l'expression sous forme de chaine */
   elem* expr_vect;  /* pour l'expression sous forme d'un vecteur */
   int len_vect;
   Pile *P;
   float result;

   puts (" *******************************************************************");
   puts (" *                                                                 *");
   puts (" *    ************    ******     ******    ********************    *");
   puts (" *    ************    *******    ******    ********************    *");
   puts (" *    **  ****  **      ******   ****      **  ****    ****  **    *");
   puts (" *        ****          *******  ****          ****    ****        *");
   puts (" *        ****          ******** ****          ****    ****        *");
   puts (" *        ****          **** ********          ****    ****        *");
   puts (" *        ****          ****  *******          ****    ****        *");
   puts (" *    **  ****  **      ****   ******      **  ****    ****  **    *");
   puts (" *    ************    ******    *******    ********************    *");
   puts (" *    ************    ******     ******    ********************    *");
   puts (" *                                                                 *");
   puts (" *******************************************************************");
   puts (" *                                                                 *");
   puts (" * Utiliser 'c', 's', 't', '^', 'e' pour les cos,sin,tan,x^y,e^x   *");
   puts (" *                                                                 *");
   puts (" *******************************************************************");

   for(int i=1; i<50; i++){
      /* demander la saisi tantque l'expression est incorrecte */
      do {
         puts (" ");
         if(i>1)
            puts (" Entrez une nouvelle Expression valide: ");
         else
            puts (" Entrez une Expression valide: ");
         printf(" ");
         gets (expr);
      } while(!CorrectExpression(expr));

      expr_vect = (elem*) malloc(MAX_LEN * sizeof(elem));
      expr_vect = ChaineEnVecteur(expr, expr_vect, &len_vect);

      P = FormePostFixe(expr_vect, len_vect);

      result = EvalueFormePostFixe(P);

      printf("\n\n Le resultat est: %.2f\n", result);

      free(expr_vect);
      free(P);
   }

   return 0;
}
