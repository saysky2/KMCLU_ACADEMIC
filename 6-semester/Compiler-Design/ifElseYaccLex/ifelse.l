%{
#include "y.tab.h"  // Include YACC header file for token definitions
%}

%option noyywrap

%%

"if"      { return IF; }
"else"    { return ELSE; }
"("       { return LPAREN; }
")"       { return RPAREN; }
"{"       { return LBRACE; }
"}"       { return RBRACE; }
"=="      { return EQ; }
"="       { return ASSIGN; }
[0-9]+    { return NUMBER; }
[a-zA-Z_][a-zA-Z0-9_]* { return IDENTIFIER; }
";"       { return SEMICOLON; }
.         { /* Ignore unrecognized characters */ }

%%

