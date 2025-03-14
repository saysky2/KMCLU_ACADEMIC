PROCEDURE:
1. Create two files ifelse.l ( for LEX) and ifelse.y (for YACC)
2. Go on to the terminal and enter the following below command 
3. lex ifelse.l                                                //  It does an lexical analysis of the program.
4. yacc -d ifelse.y 			      //  It does parsing
5. gcc lex.yy.c y.tab.c -o ifelse -ll	      //  Creates ifelse.exe file (executable )
6. ./ifelse				      // Run the program 
 

 test case 
 1. if (x == y) { x = 5; } else { y = 10; }
 2. if (x = 10 ) { y = 5; }