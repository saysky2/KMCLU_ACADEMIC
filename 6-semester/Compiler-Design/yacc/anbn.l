%{
#include "y.tab.h"
%}

%%
a   return A;
b   return B;
\n  return 0;
.   return -1;
%%

int yywrap() {
    return 1;
}