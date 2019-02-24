%{
	#include <stdio.h>
//	#include "ast.h"
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
%token FOR CLASS PUBLIC STATIC VOID MAIN STRING EXTENDS RETURN INT BOOLEAN IF ELSE WHILE PRINT PRINTLN LENGTH TRUE FALSE THIS NEW
%left '+' '-'
%left '*' '/'
%left op
%left '<' '>'
%left '!'
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

VarDecl		: TypePrime id ';'
		| id id ';'
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

Type		: PrimType 
		| Type '[' ']'
		;

PrimType	: INT
		| BOOLEAN
		| id
		;

TypePrime	: PrimTypePrime
		| TypePrime '[' ']'
		| id '[' ']'
		;

PrimTypePrime	: INT
		| BOOLEAN
		;

StatementList	: StatementList Statement
		| Statement 
		;

Statement	: '{' StatementList '}'
		| '{' '}'
		| IF '(' Exp ')' Statement ELSE Statement
		| WHILE '(' Exp ')' Statement
		| PRINTLN '(' Exp ')' ';'
		| PRINTLN '(' STRING_LITERAL ')' ';'
		| PRINT '(' Exp ')' ';'
		| PRINT '(' STRING_LITERAL ')' ';'
		| id '=' Exp ';'
		| id Index '=' Exp ';'
		| RETURN Exp ';'
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
		| '-' Exp
		| '+' Exp
		| INTEGER_LITERAL
		| TRUE
		| FALSE
		| Object
		| '(' Exp ')' 
		| id Index
		| id '.' LENGTH
		| id Index '.' LENGTH
		| id '.' id '(' ExpList ')'
		| ObjectPrime '.' id '(' ExpList ')'
		;

Object		: id
		| THIS
		| NEW id '(' ')'
		| NEW PrimType Index
		; 

ObjectPrime	: THIS
		| NEW id '(' ')'
		| NEW PrimType Index
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
