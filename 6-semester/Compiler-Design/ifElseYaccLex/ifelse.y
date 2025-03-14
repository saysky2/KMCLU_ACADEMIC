%{
#include <stdio.h>
#include <stdlib.h>

void yyerror(const char *s);  // Error handling function
int yylex();  // Lexical analyzer function
%}

%token IF ELSE LPAREN RPAREN LBRACE RBRACE EQ ASSIGN NUMBER IDENTIFIER SEMICOLON

%%

stmt:
    if_stmt
    | if_else_stmt
    ;

if_stmt:
    IF LPAREN condition RPAREN LBRACE stmt_list RBRACE
    {
        printf("Valid IF statement\n");
    }
    ;

if_else_stmt:
    IF LPAREN condition RPAREN LBRACE stmt_list RBRACE ELSE LBRACE stmt_list RBRACE
    {
        printf("Valid IF-ELSE statement\n");
    }
    ;

condition:
    IDENTIFIER EQ IDENTIFIER
    | IDENTIFIER EQ NUMBER
    ;

stmt_list:
    stmt
    | stmt_list stmt
    | IDENTIFIER ASSIGN NUMBER SEMICOLON
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main() {
    printf("Enter an IF or IF-ELSE statement:\n");
    yyparse();
    return 0;
}
