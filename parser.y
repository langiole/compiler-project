%{
	#include <stdio.h>
	int yylex(void);
	void yyerror(char *);
	extern FILE *yyin;
	int yydebug=1;
	extern int yylineno;
	void * root;
%}

%union {
	AST_Node * node;
};

%code requires {
	#include "ast.h"
}

%token id
%token STRINGLITERAL
%token INTEGERLITERAL
%token FOR CLASS PUBLIC STATIC VOID MAIN STRING EXTENDS RETURN INT BOOLEAN IF ELSE WHILE PRINT PRINTLN LENGTH TRUE FALSE THIS NEW AND OR LESSTHANEQ GREATTHANEQ EQ NOTEQ

%type<node> Program MainClass ClassDeclList ClassDecl id Statement VarDeclList VarDecl StatementList MethodDeclList TypePrime MethodDecl Type FormalList Exp FormalRestList FormalRest PrimType PrimTypePrime STRINGLITERAL Index INTEGERLITERAL Object ExpList ObjectPrime ExpRestList ExpRest

%left '+' '-'
%left '*' '/'
%left '<' '>'
%left LESSTHANEQ GREATTHANEQ
%left AND OR
%left NOTEQ
%left EQ
%left '!'
%%

Program 	
	: MainClass ClassDeclList 	{ root = mknode2(PROGRAM, $1, $2); }
	;

ClassDeclList	
	: ClassDeclList ClassDecl 	{ $$ = mknode2(CLASSDECLLIST, $1, $2); }
	| 				{ $$ = mknode0(CLASSDECLLIST); }
	;

MainClass
	: CLASS id '{' PUBLIC STATIC VOID MAIN '(' STRING '[' ']' id ')' '{' Statement '}' '}'
		{ $$ = mknode3(MAINCLASS, $2, $12, $15); }
	;

ClassDecl
	: CLASS id '{' VarDeclList MethodDeclList '}' 			{ $$ = mknode3(CLASSDECL, $2, $4, $5); }
	| CLASS id EXTENDS id '{' VarDeclList MethodDeclList '}' 	{ $$ = mknode4(CLASSDECL, $2, $4, $6, $7); }
	;

VarDeclList	
	: VarDeclList VarDecl 	{ $$ = mknode2(VARDECLLIST, $1, $2); }
	| 			{ $$ = mknode0(VARDECLLIST); }
	;

VarDecl		
	: TypePrime id ';' 	{ $$ = mknode2(VARDECL, $1, $2); }
	| id id ';' 		{ $$ = mknode2(VARDECL, mknode1(TYPE, mknode1(PRIMTYPE, $1)), $2); }
	;

MethodDeclList	
	: MethodDeclList MethodDecl 	{ $$ = mknode2(METHODDECLLIST, $1, $2); }
	| 				{ $$ = mknode0(METHODDECLLIST); }
	;

MethodDecl	
	: PUBLIC Type id '(' FormalList ')' '{' VarDeclList StatementList RETURN Exp ';' '}' 	{ $$ = mknode6(METHODDECL, $2, $3, $5, $8, $9, $11); }
	| PUBLIC Type id '(' FormalList ')' '{' VarDeclList RETURN Exp ';' '}' 			{ $$ = mknode5(METHODDECL, $2, $3, $5, $8, $10); }
	;

FormalList	
	: Type id FormalRestList 	{ $$ = mknode3(FORMALLIST, $1, $2, $3); }
	| 				{ $$ = mknode0(FORMALLIST); }
	;

FormalRestList	
	: FormalRestList FormalRest 	{ $$ = mknode2(FORMALRESTLIST, $1, $2); }
	| 				{ $$ = mknode0(FORMALRESTLIST); }
	;

FormalRest	
	: ',' Type id 	{ $$ = mknode2(FORMALREST, $2, $3); }
	;

Type
	: PrimType 	{ $$ = mknode1(TYPEPRIM, $1); }
	| Type '[' ']' 	{ $$ = mknode1(TYPEARR, $1); }
	;

PrimType
	: INT 		{ $$ = mknode0(PRIMTYPEINT); }
	| BOOLEAN 	{ $$ = mknode0(PRIMTYPEBOOL); }
	| id 		{ $$ = mknode1(PRIMTYPEID, $1); }
	;

TypePrime
	: PrimTypePrime 	{ $$ = mknode1(TYPEPRIM, $1); }
	| TypePrime '[' ']' 	{ $$ = mknode1(TYPEARR, $1); }
	| id '[' ']' 		{ $$ = mknode1(TYPEARR, mknode1(TYPEPRIM, mknode1(PRIMTYPEID, $1))); }
	;

PrimTypePrime	
	: INT 		{ $$ = mknode0(PRIMTYPEINT); }
	| BOOLEAN 	{ $$ = mknode0(PRIMTYPEBOOL); }
	;

StatementList
	: StatementList Statement 	{ $$ = mknode2(STATEMENTLIST, $1, $2); }
	| Statement 			{ $$ = mknode1(STATEMENTLIST, $1); }
	;

Statement
	: '{' StatementList '}' 			{ $$ = mknode1(BLOCK, $2); }
	| '{' '}' 					{ $$ = mknode0(BLOCK); }
	| IF '(' Exp ')' Statement ELSE Statement 	{ $$ = mknode3(IF, $3, $5, $7); }
	| WHILE '(' Exp ')' Statement 			{ $$ = mknode2(WHILE, $3, $5); }
	| PRINTLN '(' Exp ')' ';' 			{ $$ = mknode1(PRINTLNEXP, $3); }
	| PRINTLN '(' STRINGLITERAL ')' ';' 		{ $$ = mknode1(PRINTLNSTR, $3); }
	| PRINT '(' Exp ')' ';' 			{ $$ = mknode1(PRINTEXP, $3); }
	| PRINT '(' STRINGLITERAL ')' ';' 		{ $$ = mknode1(PRINTSTR, $3); }
	| id '=' Exp ';' 				{ $$ = mknode2(ASSGN, $1, $3); }
	| id Index '=' Exp ';' 				{ $$ = mknode3(ARRASSGN, $1, $2, $4); }
	| RETURN Exp ';' 				{ $$ = mknode1(RET, $2); }
	;

Index	
	: '[' Exp ']' 		{ $$ = mknode1(INDEX, $2); }
	| Index '[' Exp ']' 	{ $$ = mknode2(INDEX, $1, $3); }
	;

Exp
	: Exp AND Exp 				{ $$ = mknode2(AND, $1, $3); }
	| Exp OR Exp 				{ $$ = mknode2(OR, $1, $3); }
	| Exp EQ Exp 				{ $$ = mknode2(EQ, $1, $3); }
	| Exp NOTEQ Exp 			{ $$ = mknode2(NOTEQ, $1, $3); }
	| Exp LESSTHANEQ Exp 			{ $$ = mknode2(LESSTHANEQ, $1, $3); }
	| Exp GREATTHANEQ Exp 			{ $$ = mknode2(GREATTHANEQ, $1, $3); }
	| Exp '<' Exp 				{ $$ = mknode2(LESSTHAN, $1, $3); }
	| Exp '>' Exp 				{ $$ = mknode2(GREATTHAN, $1, $3); }
	| Exp '+' Exp 				{ $$ = mknode2(PLUS, $1, $3); }
	| Exp '-' Exp 				{ $$ = mknode2(MINUS, $1, $3); }
	| Exp '*' Exp 				{ $$ = mknode2(TIMES, $1, $3); }
	| Exp '/' Exp 				{ $$ = mknode2(DIVIDE, $1, $3); }
	| '!' Exp 				{ $$ = mknode1(NEGATE, $2); }
	| '-' Exp 				{ $$ = mknode1(MINUS, $2); }
	| '+' Exp 				{ $$ = mknode1(PLUS, $2); }
	| INTEGERLITERAL			{ $$ = mknode1(EXPINT, $1); }
	| TRUE					{ $$ = mknode0(TRUE); }
	| FALSE					{ $$ = mknode0(FALSE); }
	| Object				{ $$ = mknode1(EXPOBJECT, $1); }
	| '(' Exp ')' 				{ $$ = mknode1(PAREN, $2); }
	| id Index 				{ $$ = mknode2(ARRLOOKUP, $1, $2); }
	| id '.' LENGTH 			{ $$ = mknode1(IDENTIFIERLEN, $1); }
	| id Index '.' LENGTH			{ $$ = mknode2(ARRLEN, $1, $2); }
	| id '.' id '(' ExpList ')' 		{ $$ = mknode3(CALL, mknode1(OBJID, $1), $3, $5); }
	| ObjectPrime '.' id '(' ExpList ')' 	{ $$ = mknode3(CALL, $1, $3, $5); }
	;

Object		: id 			{ $$ = mknode1(OBJID, $1); }
		| THIS 			{ $$ = mknode0(THIS); }
		| NEW id '(' ')' 	{ $$ = mknode1(NEWOBJ, $2); }
		| NEW PrimType Index 	{ $$ = mknode2(NEWARR, $2, $3); }
		; 

ObjectPrime	: THIS 			{ $$ = mknode0(THIS); }
		| NEW id '(' ')' 	{ $$ = mknode1(NEWOBJ, $2); }
		| NEW PrimType Index 	{ $$ = mknode2(NEWARR, $2, $3); }
		;

ExpList		: Exp ExpRestList 	{ $$ = mknode2(EXPLIST, $1, $2); }
		|			{ $$ = mknode0(EXPLIST); }
		;

ExpRestList 	: ExpRestList ExpRest 	{ $$ = mknode2(EXPRESTLIST, $1, $2); }
		| 			{ $$ = mknode0(EXPRESTLIST); }
		;

ExpRest 	: ',' Exp 		{ $$ = mknode1(EXPREST, $2); }
		;

%%
#include "dfs.h"

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
	dfs(root);
	return 0;
}
