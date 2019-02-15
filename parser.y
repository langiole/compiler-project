%{
	#include <stdio.h>
	int yylex(void);
	void yyerror(char *);
	extern FILE *yyin;
%}

%token id
%token STRING_LITERAL
%token INTEGER_LITERAL
%token op
%token FOR CLASS PUBLIC STATIC VOID MAIN STRING EXTENDS RETURN INT BOOLEAN IF ELSE WHILE PRINT LENGTH TRUE FALSE THIS NEW

%%
Exp : 'int'
%%
void yyerror(char *s) {
	fprintf(stderr, "%s\n", s);
}

int main(int argc, char **argv) {
	++argv, --argc;
	if (argc > 0)
		yyin = fopen(argv[0], "r");
	else
		yyin = stdin;
	yyparse();
	return 0;
}
