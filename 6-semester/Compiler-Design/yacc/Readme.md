PROCEDURE:
1. On terminal, CD to folder where anbn.y and anbn.l file is present
2. sudo apt install bison                   //  To run yacc parser
3. sudo apt install flex                      // To run lex parser
4. lex anbn.l              	            // this command creates a file lex.yy.c
5. yacc -d anbn.y                               // It creates two program files of yacc parser.( y.tab.c &  y.tab.h)
6. gcc lex.yy.c y.tab.c -o anbn -ll    // These creates an anbn.exe (executable) file
7. ./anbn  			            // these helps in running the program
