%{
#include <stdio.h>
#include <string.h>
    
int printf_count = 0, scanf_count = 0;
FILE *yyin;  // Declare yyin globally
%}
    
%%  // <-- Ensure this section exists
    
"printf" { 
    printf_count++; 
    printf("write"); 
}
"scanf" { 
    scanf_count++; 
    printf("read"); 
}
.       { putchar(yytext[0]); }  // Print other characters as they are
\n      { putchar('\n'); }       // Preserve new lines
    
%%  // <-- Ensure this section exists
    
int yywrap() {
    return 1;
}
    
int main() {
    char filename[100];
    
    printf("Enter the file name to process: ");
    scanf("%s", filename);
    
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open file %s\n", filename);
        return 1;
    }
    
    yyin = file;  // Redirect input to the file
    printf("\nModified Code:\n");
    yylex();
    fclose(file);
    
    printf("\n\nTotal occurrences:\n");
    printf("printf -> write: %d\n", printf_count);
    printf("scanf -> read: %d\n", scanf_count);
        
    return 0;
}