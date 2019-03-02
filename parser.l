%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "y.tab.h"	
	#define PRINTDEBUG(x, y) fprintf(stderr, "\nDBG: %s, lineno: %d\n", x,y);
	void yyerror(const char *s);
%}
%option yylineno

letter			[A-Za-z]
digit			[0-9]
NoStar 			[^*]
NoStarDash 		[^*/]
NoQuoteDashNl 		[^\"\\\n]
id			{letter}({letter}|{digit}|_)*
INTEGER_LITERAL 	({digit})*{digit}
STRING_LITERAL		\"(\\.|{NoQuoteDashNl})*\"
single_char 		[+\-!{}[\]();,=.<>*/]
sl_comment 		(\/\/.*)
ml_comment 		(\/\*)({NoStar}|\*+{NoStarDash})*\*+\/
SYNTAX_ERR 		(\+\+)|(--)

%%
"for" 			{ return FOR; }
"class" 		{ return CLASS; }
"public" 		{ return PUBLIC; }
"static" 		{ return STATIC; }
"void" 			{ return VOID; }
"main" 			{ return MAIN; }
"String" 		{ return STRING; }
"int" 			{ return INT; }
"boolean" 		{ return BOOLEAN; }
"extends" 		{ return EXTENDS; }
"return" 		{ return RETURN; }
"if" 			{ return IF; }
"else" 			{ return ELSE; }
"while" 		{ return WHILE; }
"System.out.println" 	{ return PRINTLN; }
"System.out.print"	{ return PRINT; }
"length" 		{ return LENGTH; }
"true" 			{ return TRUE; }
"false" 		{ return FALSE; }
"this" 			{ return THIS; }
"new" 			{ return NEW; }
{id}			{ return id; }
{INTEGER_LITERAL}	{ return INTEGERLITERAL; }
{STRING_LITERAL} 	{ return STRINGLITERAL; }
"&&"			{ return AND; }
"||"			{ return OR; }
"<="			{ return LESSTHANEQ; }
">="			{ return GREATTHANEQ; }
"=="			{ return EQ; }
"!=" 			{ return NOTEQ; }
{single_char} 		{ return *yytext; }
{sl_comment} 		{ }
{ml_comment} 		{ }
{SYNTAX_ERR} 	 	{ yyerror(""); }
[ \n\t\r] 		{ }
.			{ yyerror(""); } 
%%

int yywrap(void) { return 1; }
