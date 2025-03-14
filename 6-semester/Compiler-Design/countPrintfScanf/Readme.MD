PROCEDURE:
1. Create a file with .l extension & at test.txt file with some scanf & printf codes init.
( As Printf will be replaced by write and scanf by read.)
2. On to the terminal, input sudo apt install flex (as required to run lex parsers)
3. flex countPrintfScanf.l        		// flex fileName.l
4. gcc lex.yy.c -o countPrintfScanf -lfl     	// Creates an countPrintfScanf.exe
5. ./countPrintfScanf                                  	// To Run the program 
