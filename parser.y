%{
	#include <stdio.h>
	int yylex(void);
	void yyerror(char *);
	extern FILE *yyin;
	extern int yy_flex_debug;
%}

%token id
%token STRING_LITERAL
%token INTEGER_LITERAL
%token op
%token FOR CLASS PUBLIC STATIC VOID MAIN STRING EXTENDS RETURN INT BOOLEAN IF ELSE WHILE PRINT LENGTH TRUE FALSE THIS NEW

%%

Program 	: MainClass ClassDeclList
		;

ClassDeclList	: ClassDeclList ClassDecl
		|
		;

MainClass 	: CLASS id '{' PUBLIC STATIC VOID MAIN '(' STRING '[' ']' id ')' '{' Statement '}' '}'
		;

ClassDecl	: CLASS id '{' VarDeclList MethodDeclList '}'
		| CLASS id EXTENDS id '{' VarDeclList MethodDeclList '}'
		;

VarDeclList	: VarDeclList VarDecl
		|
		;

VarDecl		: Type id ';'
		;

MethodDeclList	: MethodDeclList MethodDecl
		|
		;

MethodDecl	: PUBLIC Type id '(' FormalList ')' '{' VarDeclList StatementList RETURN Exp ';' '}'
		;

FormalList	: Type id FormalRestList
		|
		;

FormalRestList	: FormalRestList FormalRest
		|
		;

FormalRest	: ',' Type id
		;

Type		: INT
		| BOOLEAN
		| id
		| Type '[' ']'
		;

StatementList	: StatementList Statement
		|
		;

Statement	: '{' StatementList '}'
		| IF '(' Exp ')' Statement ELSE Statement
		| WHILE '(' Exp ')' Statement
		| PRINT '(' Exp ')' ';'
		| PRINT '(' STRING_LITERAL ')' ';'
		| id '=' Exp ';'
		| id Index '=' Exp ';'
		;

Index		: '[' Exp ']'
		| Index '[' Exp ']'
		;

Exp		: Exp op Exp
		| Exp '<' Exp
		| Exp '>' Exp
		| Exp '+' Exp
		| Exp '-' Exp
		| Exp '*' Exp
		| Exp '/' Exp
		| '!' Exp
		| '+' Exp
		| '-' Exp
		| '(' Exp ')'
		| id Index
		| id '.' LENGTH
		| id Index '.' LENGTH
		| INTEGER_LITERAL
		| TRUE
		| FALSE
		| Object
		| Object '.' id '(' ExpList ')'
		;

Object		: id
		| THIS
		| NEW id '(' ')'
		| NEW Type Index
		;

ExpList		: Exp ExpRestList
		|
		;

ExpRestList 	: ExpRestList ExpRest
		|
		;

ExpRest 	: ',' Exp
		;

%%

void yyerror(char *s) {
	fprintf(stderr, "%s\n", s);
}

int main(int argc, char **argv) {
	yy_flex_debug = 1;
	++argv, --argc;
	if (argc > 0)
		yyin = fopen(argv[0], "r");
	else
		yyin = stdin;
	yyparse();
	return 0;
}
