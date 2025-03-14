%{
#include <stdio.h>
#include <stdlib.h>

void yyerror(const char *s);
int yylex();
%}

%token A B

%%
S : A S B   // Ensures balanced number of A's and B's
  | A B     // Base case: Single 'A' followed by 'B'
  ;

%%

void yyerror(const char *s) {
    printf("Invalid string: %s\n", s);
}

int main() {
    printf("Enter a string of 'a's and 'b's: ");
    if (yyparse() == 0) {
        printf("Valid string: It belongs to the language { aⁿbⁿ | n > 0 }\n");
    }
    return 0;
}
