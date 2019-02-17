%{
	#include <stdio.h>
	int yylex(void);
	void yyerror(char *);
	extern FILE *yyin;
	int yydebug=1;
	extern int yylineno;
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

VarDecl		: VDType id ';'
		| id id ';'
		;

VDType		: VDTypePrime
		| VDType '[' ']'
		| id '[' ']'
		;

VDTypePrime	: INT
		| BOOLEAN
		;

MethodDeclList	: MethodDeclList MethodDecl
		|
		;

MethodDecl	: PUBLIC Type id '(' FormalList ')' '{' VarDeclList StatementList RETURN Exp ';' '}'
		| PUBLIC Type id '(' FormalList ')' '{' VarDeclList RETURN Exp ';' '}'
		;

FormalList	: Type id FormalRestList
		|
		;

FormalRestList	: FormalRestList FormalRest
		|
		;

FormalRest	: ',' Type id
		;

Type		: PrimeType 
		| Type '[' ']'
		;

PrimeType	: INT
		| BOOLEAN
		| id
		;

StatementList	: StatementList Statement
		| Statement 
		;

Statement	: '{' StatementList '}'
		| '{' '}'
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

Exp		: Exp op PrefixExp
		| Exp '<' PrefixExp
		| Exp '>' PrefixExp
		| Exp '+' PrefixExp
		| Exp '-' PrefixExp
		| Exp '*' PrefixExp
		| Exp '/' PrefixExp 
		| PrefixExp
		;

PrefixExp	: '!' PrimaryExp
		| '-' PrimaryExp
		| '+' PrimaryExp
		| PrimaryExp
		;

PrimaryExp	: INTEGER_LITERAL
		| TRUE
		| FALSE
		| Object
		| '(' Exp ')' 
		| id '.' LENGTH
		| id Index '.' LENGTH
		| id '.' id '(' ExpList ')'
		| ObjectPrime '.' id '(' ExpList ')'
		;

Object		: id
		| THIS
		| NEW id '(' ')'
		| NEW PrimeType Index
		; 

ObjectPrime	: THIS
		| NEW id '(' ')'
		| NEW PrimeType Index
		;

ExpList		: Exp ExpRestList
		;

ExpRestList 	: ExpRestList ExpRest
		|
		;

ExpRest 	: ',' Exp
		;

%%

void yyerror(char *s) {
	fprintf(stderr, "Syntax errors in %d\n", yylineno);
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
